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
#define DEBUG 0                 //0 -> no serial output

int output_pin = 3;
int input_pin = A0;
int sensor_pin = A1;
int filter_size = 15;                        //Noise reduction filter size
const int sample_window = 50;                // Sample window width in mS (50 mS = 20Hz)

SignalProcessing input(input_pin, filter_size);

void setup() {
  pinMode(output_pin, OUTPUT);
  #if DEBUG
   Serial.begin(9600);
  #endif
}

void loop() {

  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int sensor_val;
  int output_val;              
  unsigned long start_millis= millis();                       // Start of sample window
  unsigned int signal_max = 0;
  unsigned int signal_min = 1024;
  
  while (millis() - start_millis < sample_window){
      sensor_val = analogRead(sensor_pin);
      if (sensor_val < 1024){  // toss out spurious readings
         if (sensor_val > signal_max){
            signal_max = sensor_val;  // save the max levels
         }
         else if (sample < signal_min){
            signal_min = sensor_val;  // save the min levels
         }
      }
  }
  if(signal_max - signal_min <= 20){            //when there is only background noise, output nothing
      output_val = 0;
  }
  else{ 
      output_val = cutAndMap(signal_max-signal_min, 20, 350, 0, 255);
  }
  analogWrite(output_pin, output_val);
  
  #if DEBUG
   Serial.print(signal_max - signal_min);
   Serial.print(" ");
   Serial.println(output_val);
  #endif
}
