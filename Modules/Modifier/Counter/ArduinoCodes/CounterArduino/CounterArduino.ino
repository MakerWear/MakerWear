/*
**  CounterArduino.ino
**  MakerWear Counter Module's Arduino Program.
**
**  increases output voltage by a single step (to be read by the Number 
**  module) upon receiving a rising edge on the input pin.
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**
**
**  Created on 06/11/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>
 
int input_pin = A0;
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

}
