/*
**  VibtroMotorArduino.ino
**  MakerWear Vibro Motor Module's Arduino Program.
**
**  Vibrates a motor corresponding to voltage value (higher voltage 
**  for more vibration)
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Vibro Motor + 100Ω
**  Arduino Pin A0: Module Input
**
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
int vibro_pin = 11;                             
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{  
  pinMode(vibro_pin, OUTPUT);
}

void loop() 
{
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
    
  analogWrite(vibro_pin, input_val/4);
}
