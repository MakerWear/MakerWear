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
#include <FilteredAnalogInput.h>

int input_pin = 3;                           //Pin 2 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);


ATtinyUVLightSensor uv = ATtinyUVLightSensor();

void setup() {

}

void loop() {
  float UVindex;
  
  UVindex = uv.readUV();
  
  analogWrite(output_pin, (int)UVindex);
}
