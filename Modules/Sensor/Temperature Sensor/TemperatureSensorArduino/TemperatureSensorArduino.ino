/*
**  TemperatureSensorArduino.ino
**  MakerWear Temperature Sensor Module's Arduino Program.
**
**  Changes voltage output proportionality response to Temperature (higher voltage
**  means higher temperature)
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**  Arduino Pin A1: TMP36 Temperature Sensor
**
**
**  Created on 12/23/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

//int input_pin = A0;
int tmp_sensor = A0;
int output_pin = 11;
//int filter_size = 15;                        //Noise reduction filter size

//FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{
  //Just for debugging:
  //Serial.begin(9600);
}

void loop() 
{
  int raw_voltage = analogRead(tmp_sensor);
  //int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(output_value < 0)
    output_value = 0;
  else if(output_value > 150)
    output_value = 150;
  
  int output_value = map(raw_voltage, 0, 150, 0, 255);
    
  analogWrite(output_pin, output_value);
}
