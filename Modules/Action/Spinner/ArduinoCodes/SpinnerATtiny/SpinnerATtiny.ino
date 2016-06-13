/*
**  SpinnerATtiny.ino
**  MakerWear Spinner Module's ATtiny Program.
**
**  This is a special module that spins along the same axis as 
**  attachment (see Rotate Cubelet). We could include either 
**  velcro here or a magnet or both to allow kids to attach 
**  their own spinnable things. Could also have LEGO pegs.
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): DCMotor
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 06/2/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

int input_pin = 3;                             //pin 2 on ATtiny              
int motor_pin = 1;                             
int filter_size = 15;                        //Noise reduction filter size

SignalProcessing input(input_pin, filter_size);

void setup() 
{  
  pinMode(motor_pin, OUTPUT);
}

void loop() 
{
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  /*if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;*/
    
  analogWrite(motor_pin, input_val/4);
}
