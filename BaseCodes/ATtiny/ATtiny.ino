/*
**  ModuleNameATtiny.ino
**  MakerWear ModuleName Module's ATtiny Program.
**
**  Description
**  Description
**  Description
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
**  Created on xx/yy/zz.
**  By Akbar Akbari
**  Modified on xx/yy/zz, xx/yy/zz
**  By Asghar Asghari
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

//Pin Configurations:
int input_pin = 3;                           //module input, pin 2 on ATtiny
int filter_size = 15;                        //noise reduction filter size
int output_pin = 1;

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{
}

void loop()
{
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
}

