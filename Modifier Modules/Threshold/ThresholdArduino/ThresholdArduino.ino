/*
**  ThresholdArduino.ino
**  MakerWear Threhsold Module's Arduino Program.
**
**  Outputs 0V if under set threshold or 5V if over threshold. To help with
**  transparency, maybe the module should also have a small bargraph that lets
**  the user know what the threshold setting is.
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**  Arduino Pin A1: Potentiometer
**
**
**  Created on 8/25/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>
 
int input_pin = A0;
int potentiometer_pin = A1;
int output_pin = 11;
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup()
{
  pinMode(output_pin, OUTPUT);
  
  //Just For Debugging:
  //Serial.begin(9600);
}

void loop() 
{
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
    
  int pot_val = analogRead(potentiometer_pin);
  
  if(input_val >= pot_val)
    digitalWrite(output_pin, HIGH);
  else
    digitalWrite(output_pin, LOW);
}
