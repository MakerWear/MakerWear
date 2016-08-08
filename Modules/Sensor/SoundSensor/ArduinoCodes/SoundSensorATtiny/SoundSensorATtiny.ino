/*
**  SoundSensorArduino.ino
**  MakerWear Sound Sensor Module's ATtiny Program.
**
**  A microphone/sound sensor that detects sound levels and outputs voltage accordingly.
**
**
**  ATtiny Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
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

//Pin Configurations:
int output_pin = 1;
int input_pin = A3;
int sensor_pin = A2;
int filter_size = 15;                        //Noise reduction filter size

SignalProcessing input(input_pin, filter_size);

void setup() {
  //Initialization:
  pinMode(output_pin, OUTPUT);
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
}
