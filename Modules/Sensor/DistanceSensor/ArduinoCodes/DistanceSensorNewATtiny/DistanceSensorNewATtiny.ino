/*
**  DistanceSensorATtiny.ino
**  MakerWear DistanceSensor Module's ATtiny Program.
**
**  Changes voltage output proportional to distance of any obstacle that is
**  in front of the sensor. Outputs 0 when very far or there are no obstacles
**  near and outputs 5V when there is something very close.
**
**
**  Arduino Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): IR Receiver           Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): IR LEDs
**
**
**  Created on 7/5/16.
**  By Alex Jiao
**  
**  Based on code by Ricardo Ouvina: http://www.instructables.com/id/Simple-IR-proximity-sensor-with-Arduino/
**  
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

const float A = 243.8;
const float B = -.6762;
int filter_size = 15;
int input_pin = A3;
int output_pin = 1;
int ir_pin = A2;               // IR photodiode on ATtiny pin 3
int led_pin = 0;               // IR emitter LED on ATtiny pin 5

SignalProcessing input(input_pin, filter_size);

void setup(){
  //Serial.begin(9600);         // initializing Serial monitor
  pinMode(led_pin, OUTPUT);     // IR emitter LED on digital pin 2
  digitalWrite(led_pin, LOW);   // setup IR LED as off
}

void loop(){
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  if(input_val < 1){
    digitalWrite(led_pin, LOW);
    return;
  }
  int val = readIR(20);                        // calling the function that will read the distance and passing the "accuracy" to it
  int distance = A*pow(val, B);                //converting to distance
  //Serial.println(distance);
  int output_val = cutAndMap(distance, 5, 65, input_val/4, 0);
  //Serial.println(output_val);
  analogWrite(output_pin, output_val);
}

int readIR(int times){
  int value[times];                // array to store the IR values
  int total = 0;
  int ambientIR;                   // variable to store the IR coming from the ambient
  int obstacleIR;                  // variable to store the IR coming from the object
  
  for(int x = 0; x < times; x++){     
    digitalWrite(led_pin,LOW);           // turning the IR LEDs off to read the IR coming from the ambient
    delay(1);                            // minimum delay necessary to read values
    ambientIR = analogRead(ir_pin);      // storing IR coming from the ambient
    digitalWrite(led_pin,HIGH);          // turning the IR LEDs on to read the IR coming from the obstacle
    delay(1);                            // minimum delay necessary to read values
    obstacleIR = analogRead(ir_pin);     // storing IR coming from the obstacle
    value[x] = ambientIR-obstacleIR;     // calculating changes in IR values and storing it for future average
  }
 
  for(int x = 0; x < times; x++){        
    total += value[x];
  }
  return(total/times);                   // return the average
}

