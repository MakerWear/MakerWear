/*
**  ThresholdATtiny.ino
**  MakerWear Threhsold Module's ATtiny Program.
**
**  Outputs 0V if under set threshold or 5V if over threshold. To help with
**  transparency, maybe the module should also have a small bargraph that lets
**  the user know what the threshold setting is.
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): Potentiometer         Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 4/25/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

int input_pin = 3;                           //Pin 2 on ATtiny
int potentiometer_pin = 2;                   //Pin 3 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny
int filter_size = 50;                        //Noise reduction filter size

SignalProcessing input(input_pin, filter_size);

void setup() 
{
  pinMode(output_pin, OUTPUT);
}

int state = LOW;
int threshold = 25;
void loop()
{
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int output_val = 0;
  
  /*if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;*/
    
  int pot_val = analogRead(potentiometer_pin);
  pot_val = cutAndMap(pot_val, 0, 1023, 1023, 0);
  
  if(state == LOW && input_val > pot_val+threshold)
  {
    state = HIGH;
    output_val = input_val/4;
  }
  else if(state == HIGH && input_val < pot_val-threshold)
  {
    state = LOW;
    output_val = 0;
  }
  
  digitalWrite(output_pin, output_val);
}
