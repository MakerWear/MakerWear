/*
**  SuperBrightLEDArduino.ino
**  MakerWear Super Bright LED Module's Arduino Program.
**
**  LED brightness proportional to voltage input (this module is good for
**  Flashlight Shoes so must be very bright at 5V--perhaps has 2 or even 3
**  LEDs in the one module.)
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: LED + 100Ω
**  Arduino Pin A0: Module Input
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 8/25/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

int input_pin = A0;                           
int led_pin = 11;                             
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{  
  pinMode(led_pin, OUTPUT);
}

void loop() 
{
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
    
  analogWrite(led_pin, input_val/4);
}

