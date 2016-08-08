/*
**  SoundSensorArduino.ino
**  MakerWear Sound Sensor Module's Arduino Program.
**
**  A microphone that detects sound levels and outputs voltage accordingly.
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**  Arduino Pin A1: Microphone Input
**
**
**  Created on 8/8/16.
**  By Alex Jiao
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/
#include "SignalProcessing.h"
#define DEBUG 1

int output_pin = 3;
int input_pin = A0;
int sensor_pin = A1;
int filter_size = 15;                        //Noise reduction filter size

SignalProcessing input(input_pin, filter_size);

void setup() {
  pinMode(output_pin, OUTPUT);
  #if DEBUG
   Serial.begin(9600);
  #endif
}

void loop() {

  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int sensor_val = analogRead(A0);
  int output_val = cutAndMap(input_val, 350, 475, 0, 255);              //350 and 475 experimentally determined
  
  for(int i = output_val; i >= 25; i-=25){                            //fade output slightly
    analogWrite(output_pin , i);
    delay(16);
  }
  analogWrite(3, 0);
  #if DEBUG
   Serial.println(input_val);
   Serial.print(" ");
   Serial.println(output_val);
  #endif
}
