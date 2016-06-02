#include <QueueArray.h>

#include <Wire.h>
#include <LSM303.h>

#define BUFFSIZE 10      // Buffer size for processing
#define RMSTHREDSHOLD 3.0

int ledPin = 11; 
 
LSM303 compass;
double ratio = 100.0; 

// X axis pointing forward
// Y axis pointing to the right 
// and Z axis pointing down.
int SENSOR_SIGN[3] = {-1, -1, -1};  // correct directions x, y, z - accelerometer
int AN[3]; //array that stores accelerometer data

int accel_x;
int accel_y;
int accel_z;

class LSM{
  public:
    int x;
    int y; 
    int z;
};

QueueArray <LSM> queue;

long timer = 0;   //general purpuse timer
unsigned int counter = 0;   // count the time of accelerometer data collection
boolean is_full = false;  
double rms;               // RMS

void Accel_Init()
{
  compass.init();
  compass.enableDefault();
  
  switch (compass.getDeviceType())
  {
    case LSM303::device_D:
      compass.writeReg(LSM303::CTRL2, 0x18); // 8 g full scale: AFS = 011
      break;
    case LSM303::device_DLHC:
      compass.writeReg(LSM303::CTRL_REG4_A, 0x28); // 8 g full scale: FS = 10; high resolution output mode
      break;
    default: // DLM, DLH
      compass.writeReg(LSM303::CTRL_REG4_A, 0x30); // 8 g full scale: FS = 11
  }
}

// Reads x,y and z accelerometer registers
void Read_Accel()
{
  compass.readAcc();
  
  AN[0] = compass.a.x >> 4; // shift left 4 bits to use 12-bit representation (1 g = 256)
  AN[1] = compass.a.y >> 4; 
  AN[2] = compass.a.z >> 4; 
  
  accel_x = SENSOR_SIGN[0] * (AN[0]);
  accel_y = SENSOR_SIGN[1] * (AN[1]);
  accel_z = SENSOR_SIGN[2] * (AN[2]);
}

void I2C_Init()
{
  Wire.begin();
}

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);   // sets the pin as output
  
  I2C_Init();
  delay(1500);
  
  Accel_Init();
  delay(20);
  
  timer=millis();
  delay(20);
}

void loop() 
{
  if((millis()-timer)>=50){ // Main loop runs at 20Hz
    counter++;
    timer = millis();
    
    Read_Accel();

    // store the data into the buffer
    if(is_full){
      // pop the front from the queue
      // push the currect data into the end of the queue
      queue.pop();
      LSM temp;
      temp.x = accel_x;
      temp.y = accel_y;
      temp.z = accel_z;
      queue.push(temp);
    }
    else{
      // directly push the current one into the end of the queue
      LSM temp;
      temp.x = accel_x;
      temp.y = accel_y;
      temp.z = accel_z;
      queue.push(temp);
    }
    if(counter >= BUFFSIZE){
      is_full = true;
      counter  = 0;
    }

    // calculate the RMS
    rms = 0;
    int len = queue.count();
      
    // tranpass the buffer and compute the RMS
    for(int index = 0; index < len; index++){
       LSM temp = queue.pop();
       rms += temp.x/ratio * temp.x/ratio;
       rms += temp.y/ratio * temp.y/ratio;
       rms += temp.z/ratio * temp.z/ratio;
       queue.push(temp); 
    }

    // update the RMS for each axis
    rms = sqrt(rms/len);
      
    //printRMS();

    if(rms >= RMSTHREDSHOLD){
      // Active
      Serial.println("------------ active ------------");
      int len1 = queue.count();
      double meanx = 0, meany = 0, meanz = 0;
      double sdx = 0, sdy = 0, sdz = 0;
      double power = 0.0;
      
      // tranpass the buffer and compute the RMS
      for(int index = 0; index < len1; index++){
         LSM temp = queue.pop();
         meanx += temp.x;
         meany += temp.y;
         meanz += temp.z;
         queue.push(temp); 
      }
      meanx = meanx/len1;
      meany = meany/len1;
      meanz = meanz/len1;

      for(int j = 0; j < len1; j++){
         LSM temp = queue.pop();
         sdx += (temp.x-meanx) * (temp.x-meanx);
         sdy += (temp.y-meany) * (temp.y-meany);
         sdz += (temp.z-meanz) * (temp.z-meanz);
         queue.push(temp); 
      }
      sdx = sdx/len1;
      sdy = sdy/len1;
      sdz = sdz/len1;

      power = (sdx + sdy + sdz)/ratio;
      
//      Serial.print("Power: ");
      Serial.println(power);
      int val = 0;
      
      if(power < 10000)
         val = map(power, 0, 10000, 0, 255);
      else
        val = 255;
      
      analogWrite(ledPin, val);
    }
    else{
      Serial.println("------------ static ------------");
      analogWrite(ledPin, 0);
    }
  }
  //printdata(); 
}

void printdata(void){
  Serial.print("Acc: ");
  Serial.print(accel_x);
  Serial.print(", ");
  Serial.print(accel_y);
  Serial.print(", ");
  Serial.println(accel_z);
}

void printRMS(void){
  Serial.print("RMS: ");
  Serial.println(rms);
}
