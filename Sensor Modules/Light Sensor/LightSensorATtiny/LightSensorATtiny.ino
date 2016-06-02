/*
**  LightSensorATtiny.ino
**  MakerWear Light Sensor Module's ATtiny Program.
**
**  Changes voltage output proportionality response to light (higher voltage
**  means brighter light)
**
**
**  ATtiny Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): Photoresistor         Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 8/26/15
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

int input_pin = 3;
int photoresistor_pin = 2;
int output_pin = 1;
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{
}

void loop() {
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
 
  int photoresistor_value = analogRead(photoresistor_pin);

  if(photoresistor_value < 150)
    photoresistor_value = 150;
  else if(photoresistor_value > 800)
    photoresistor_value = 800;
    
  //We are only mapping 0-1023 from ADC to 0-255
  int output_value = map(photoresistor_value, 150, 850, 0, input_val/4);
  
  analogWrite(output_pin, output_value);
}
