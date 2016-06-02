/*
**  SpinnerArduino.ino
**  MakerWear Spinner Module's Arduino Program.
**
**  This is a special module that spins along the same axis as 
**  attachment (see Rotate Cubelet). We could include either 
**  velcro here or a magnet or both to allow kids to attach 
**  their own spinnable things. Could also have LEGO pegs.
**
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
int motor_pin = 11;                             
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{  
  pinMode(motor_pin, OUTPUT);
}

void loop() 
{
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
    
  analogWrite(motor_pin, input_val/4);
}
