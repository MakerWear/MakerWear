/*
**  DistanceSensorATtiny.ino
**  MakerWear Distance Sensor Module's ATtiny Program.
**
**  Changes voltage output proportional to distance of any obstacle that is
**  in front of the sensor. Outputs 0 when very far or there are no obstacles
**  near and outputs 5V when there is something very close.
**
**
**  Arduino Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): IR Receiver           Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 8/26/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

int input_pin = 3;                           //Pin 2 on ATtiny
int ir_pin = 2;                              //Pin 3 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny
int filter_size = 15;                        //Noise reduction filter size

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
    
  //TODO:
  //These values are very inaccurate. When the hardware is finalized
  //and the 3D-Printed case for the IR transmitter/receivers are ready,
  //we need to calculate a non-linear mapping function for a more accuare
  //conversion.
  int ir_value = analogRead(ir_pin);
  int output_value = map(ir_value, 400, 1000, input_val/4, 0);
  
  if(ir_value < 450)
    output_value = input_val;
  else if(ir_value > 950)
    output_value = 0;
  
  analogWrite(output_pin, output_value); 
}
