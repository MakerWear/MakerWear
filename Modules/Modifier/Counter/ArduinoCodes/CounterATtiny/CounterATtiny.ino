/*
**  CounterATtiny.ino
**  MakerWear Counter Module's ATtiny Program.
**
**  increases output voltage by a single step (to be read by the Number 
**  module) upon receiving a rising edge on the input pin.
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 06/11/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

int input_pin = 3;                           //Pin 2 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny
int filter_size = 15;                        //Noise reduction filter size

SignalProcessing input(input_pin, filter_size);

void setup()
{
  pinMode(output_pin, OUTPUT);
}

void loop() 
{
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
  /*if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;*/

}
