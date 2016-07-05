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
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 7/5/16.
**  By Alex Jiao
**  
**  Based on original code by Ricardo Ouvina
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
int ir_pin = A2;               // IR photodiode on analog pin A2
int led_pin = 2;               // IR emitter LED on digital pin 2

SignalProcessing input(input_pin, filter_size);

void setup(){
  Serial.begin(9600);         // initializing Serial monitor
  pinMode(IRemitter,OUTPUT);  // IR emitter LED on digital pin 2
  digitalWrite(IRemitter,LOW);// setup IR LED as off
  pinMode(11,OUTPUT);         // buzzer in digital pin 11
}

void loop(){
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int val = readIR(15);                        // calling the function that will read the distance and passing the "accuracy" to it
  int distance = A*pow(val, B);                //converting to distance
  //Serial.println(distance);
  int output_val = cutAndMap(distance, 5, 65, input_val/4, 0);
  Serial.println(output_val);
  analogWrite(output_pin, output_val);
}

int readIR(int times){
  int value[times];                // array to store the IR values
  int total = 0;
  int ambientIR;                // variable to store the IR coming from the ambient
  int obstacleIR;               // variable to store the IR coming from the object
  
  for(int x = 0; x < times; x++){     
    digitalWrite(IRemitter,LOW);           // turning the IR LEDs off to read the IR coming from the ambient
    delay(1);                                             // minimum delay necessary to read values
    ambientIR = analogRead(IRpin);  // storing IR coming from the ambient
    digitalWrite(IRemitter,HIGH);          // turning the IR LEDs on to read the IR coming from the obstacle
    delay(1);                                             // minimum delay necessary to read values
    obstacleIR = analogRead(IRpin);  // storing IR coming from the obstacle
    value[x] = ambientIR-obstacleIR;   // calculating changes in IR values and storing it for future average
  }
 
  for(int x = 0; x < times; x++){        // calculating the average based on the "accuracy"
    total += value[x];
  }
  return(total/times);            // return the final value
}

