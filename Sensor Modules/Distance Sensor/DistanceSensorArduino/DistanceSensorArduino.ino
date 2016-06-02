/*
**  DistanceSensorArduino.ino
**  MakerWear Distance Sensor Module's Arduino Program.
**
**  Changes voltage output proportional to distance of any obstacle that is
**  in front of the sensor. Outputs 0 when very far or there are no obstacles
**  near and outputs 5V when there is something very close.
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**  Arduino Pin A1: IR Receiver
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

int input_pin = A0;
int ir_pin = A1;
int output_pin = 11;
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
  //we need to calculate a polynomial mapping function for a more accuare
  //conversion.
  int ir_value = analogRead(ir_pin);
  int output_value = map(ir_value, 400, 1000, input_val/4, 0);
  
  if(ir_value < 450)
    output_value = input_val;
  else if(ir_value > 950)
    output_value = 0;
  
  analogWrite(output_pin, output_value); 
}
