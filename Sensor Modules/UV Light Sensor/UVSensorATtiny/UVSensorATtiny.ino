/*
**  UVLightSensorATtiny.ino
**  MakerWear Color Sensor Module's ATtiny Program.
**
**  Changes voltage output proportional to amount of UV light
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   SCK
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): SDA
**
**
**  Created on 10/19/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <TinyWireM.h>
#include <ATtinyUVLightSensor.h>
//#include <FilteredAnalogInput.h>

//int input_pin = 3;                           //Pin 2 on ATtiny
int output_pin = 1;                            //Pin 6 on ATtiny
//int filter_size = 15;                        //Noise reduction filter size
//int output_value = 0;

//FilteredAnalogInput input(input_pin, filter_size);

ATtinyUVLightSensor uv = ATtinyUVLightSensor();

void setup() {

  while (!uv.begin())
  {
    analogWrite(output_pin, 255);
    delay(1000);
    analogWrite(output_pin, 0);
    delay(1000);
  }
  
  for(int i = 0; i < 5; i++)
  {
    analogWrite(output_pin, 255);
    delay(250);
    analogWrite(output_pin, 0);
    delay(250);
  }  
}

void loop() {
  
  float UVindex = uv.readUV()/100;
  
  int output_value = map((int)UVindex, 0, 12, 0, 255);
  analogWrite(output_pin, output_value);
  
  /*
  for(int i = 0; i < 5; i++)
  {
    analogWrite(output_pin, 0);
    delay(250);
    analogWrite(output_pin, 250);
    delay(250);
  }
  */
}
