/*
**  SuperBrightLEDATtiny.ino
**  MakerWear Super Bright LED Module's ATtiny Program.
**
**  LED brightness proportional to voltage input (this module is good for
**  Flashlight Shoes so must be very bright at 5V--perhaps has 2 or even 3
**  LEDs in the one module.)
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): LED + 100Ω
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
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

//Pin Configurations
int input_pin = 3;                           //pin 2 on ATtiny
int led_pin = 1;                             //pin 6 on ATtiny
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{  
  pinMode(led_pin, OUTPUT);
  pinMode(input_pin, INPUT);
  digitalWrite(input_pin, LOW);
}

void loop() 
{
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
    
  int output_val = (1/(1+exp(((input_val/21)-6)*-1)))*1023;
     
  analogWrite(led_pin, output_val);
}

