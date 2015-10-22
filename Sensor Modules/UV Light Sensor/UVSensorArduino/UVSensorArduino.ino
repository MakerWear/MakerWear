/*
**  UVLightSensorATtiny.ino
**  MakerWear UV Light Sensor Module's Arduino Program.
**
**  Changes voltage output proportional to amount of UV light
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin SDA: Color Sensor SDA
**  Arduino Pin SCK: Color Sensor SCK
**  Arduino Pin 11: Module Output
**
**
**  Created on 10/19/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <Wire.h>
#include "Adafruit_SI1145.h"
#include <FilteredAnalogInput.h>

//int input_pin = 3;                           //Pin 2 on ATtiny
int output_pin = 11;                          //Pin 6 on ATtiny
//int filter_size = 15;                        //Noise reduction filter size

//FilteredAnalogInput input(input_pin, filter_size);


Adafruit_SI1145 uv = Adafruit_SI1145();

void setup() {
  Serial.begin(9600);
  uv.begin();
}

void loop() {
  float UVindex;
  
  UVindex = uv.readUV();
  
  analogWrite(output_pin, (int)UVindex);
  
  Serial.println(UVindex);
}
