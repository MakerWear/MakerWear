/*
**  LightSensorArduino.ino
**  MakerWear Light Sensor Module's Arduino Program.
**
**  Changes voltage output proportionality response to light (higher voltage
**  means brighter light)
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**  Arduino Pin A1: Photoresistor
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 8/26/15
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

int input_pin = A0;
int photoresistor_pin = A1;
int output_pin = 11;
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{
  //Just for debugging:
  //Serial.begin(9600);
}

void loop() 
{
  int photoresistor_value = analogRead(photoresistor_pin);
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
  
  //We are only mapping 0-1023 from ADC to 0-255
  int output_value = map(photoresistor_value, 0, 1023, input_val, 0);
  
  //Just for debugging:
  //Serial.println(output_value);
  
  analogWrite(output_pin, output_value);
}
