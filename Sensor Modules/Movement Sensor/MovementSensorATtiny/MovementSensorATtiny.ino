/*
**  MovementSensorATtiny.ino
**  MakerWear Movement Sensor Module's ATtiny Program.
**
**  Changes voltage output proportional to movement (higher voltage
**  means more movement has been sensed)
**
**
**  ATtiny Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   SCK
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): SDA
**
**
**  Created on 12/22/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <TinyWireM.h>
#include <ATtinyAccMag.h>
#include <Vector.h>
#define BUFFSIZE 40
double ratio = 100.0; 

int output_pin = 1;
int input_pin = 3;                           //Pin 2 on ATtiny

int accel_x = 0;
int accel_y = 0;
int accel_z = 0;

Vector queue[BUFFSIZE];
int head = 0;
int tail = 0;

void qpush(Vector v)
{
  if(((tail+1) % BUFFSIZE) != head)
  {
    queue[tail] = v;
    tail = (tail+1) % BUFFSIZE;
  }
}

Vector qpop()
{ 
  if(head != tail){
    Vector returnItem = queue[head];
    head = (head+1) % BUFFSIZE;
    
    return returnItem;
  }
}

ATtinyAccMag sensor;

long timer = 0;   //general purpuse timer

// Reads x,y and z accelerometer registers
void Read_Accel()
{
  //read accelerometer data:
  sensor.readAcc();
  
  //shift left 4 bits to use 12-bit representation
  //set the correct signs
  accel_x = -1 * (sensor.a.x >> 4);
  accel_y = -1 * (sensor.a.y >> 4);
  accel_z = -1 * (sensor.a.z >> 4);
}

void InitializeAccelerometer()
{
  while(!sensor.init())
  {
    //ping();
    delay(250);
  }
  
  sensor.enableDefault();
  
  switch (sensor.getDeviceType())
  {
    case ATtinyAccMag::device_D:
      sensor.writeReg(ATtinyAccMag::CTRL2, 0x18); // 8 g full scale: AFS = 011
      break;
    case ATtinyAccMag::device_DLHC:
      sensor.writeReg(ATtinyAccMag::CTRL_REG4_A, 0x28); // 8 g full scale: FS = 10; high resolution output mode
      break;
    default: // DLM, DLH
      sensor.writeReg(ATtinyAccMag::CTRL_REG4_A, 0x30); // 8 g full scale: FS = 11
  }
}

void setup() 
{  
  InitializeAccelerometer();
  
  pinMode(output_pin, OUTPUT);
  
  timer = millis();
  delay(20);
}

void loop() 
{
    int input_val = map(analogRead(input_pin), 50, 975, 0, 1023);
  
  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;


    //maintain a window of all recent (BUFF_SIZE) accelerometer read values
    Read_Accel();
    Vector v(accel_x, accel_y, accel_z);
    
    if(((tail+1) % BUFFSIZE) != head)
    {
      qpush(v);
    }
    else{
      qpop();
      qpush(v);
    }
    
    double meanx = 0, meany = 0, meanz = 0;
    double sdx = 0, sdy = 0, sdz = 0;
    double power = 0.0;
    
    //loop through the window and calculate the Mean    
    for(int i = 0; i < BUFFSIZE; i++){
       meanx += queue[i].x;
       meany += queue[i].y;
       meanz += queue[i].z;
    }
    
    meanx = meanx/BUFFSIZE;
    meany = meany/BUFFSIZE;
    meanz = meanz/BUFFSIZE;

    //loop through the window and calculate the Standard Deviation for
    //X, Y & Z separately. (e.g. SD of X = Sum((Xi-Mean)^2)/N )
    for(int i = 0; i < BUFFSIZE; i++){
       sdx += (queue[i].x-meanx) * (queue[i].x-meanx);
       sdy += (queue[i].y-meany) * (queue[i].y-meany);
       sdz += (queue[i].z-meanz) * (queue[i].z-meanz);
    }
    
    sdx = sdx/BUFFSIZE;
    sdy = sdy/BUFFSIZE;
    sdz = sdz/BUFFSIZE;

    power = (sdx + sdy + sdz)/ratio;
    
    if(power < 0)
      power = 0;
    else if(power > 1000)
      power = 1000;
      
    int output_val = map(power, 0, 1000, 0, input_val/4);
    
    //write output value:
    analogWrite(output_pin, output_val);
}
