/*
**  VibrationATtiny.ino
**  MakerWear Vibration Module's ATtiny Program.
**
**  Vibrates a motor corresponding to voltage value (higher voltage 
**  for more vibration)
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Vibro Motor + 100Ω
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 6/21/16.
**  By Jason McPeak
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

int input_pin = 3;                             //pin 2 on ATtiny              
int vibro_pin = 1;                             
int filter_size = 15;                        //Noise reduction filter size

SignalProcessing input(input_pin, filter_size);

void setup() 
{  
  pinMode(vibro_pin, OUTPUT);
}

void loop() 
{
  /* map the value from 170 to 1023, because motor does not turn on until 170 */
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 170, 1023);
  analogWrite(vibro_pin, input_val/4);
}
