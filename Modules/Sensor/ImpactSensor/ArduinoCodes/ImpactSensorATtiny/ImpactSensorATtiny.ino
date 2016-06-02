/*
**  ImpactSensorATtiny.ino
**  MakerWear ImpactSensor Module's ATtiny Program.
**
**  Changes voltage output (0 or 100%) based it on the sensor's tilt status.
**  If the module is tilted, it would send PWR otherwise, 0 Volts.
**
**  ATtiny Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): Vibration Sensor
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**
**  Modified on 12/24/15
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

//Pin Configurations:
int input_pin = 3;             //Pin 2 on ATtiny
int vibro_sensor_pin = 0;      //Pin 5 on ATtiny
int output_pin = 1;            //Pin 6 on ATtiny
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() {
  //Initialization:  
  pinMode(output_pin, OUTPUT);
}

void loop()
{  
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
  
  if(digitalRead(vibro_sensor_pin) == HIGH)
  {
    //whenever the vibration sensor is hit
    //the output pin would be as high as the input pin for 100ms and then 0 again.
    analogWrite(output_pin, analogRead(input_pin)/4);
    delay(250);
    analogWrite(output_pin, 0);
  }
  else
    analogWrite(output_pin, 0);
}
