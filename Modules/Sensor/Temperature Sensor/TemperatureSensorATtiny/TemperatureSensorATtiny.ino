/*
**  TemperatureSensorATtiny.ino
**  MakerWear Temperature Sensor Module's ATtiny Program.
**
**  Changes voltage output proportionality response to Temperature (higher voltage
**  means higher temperature)
**
**
**  ATtiny Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): LM35                  Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 1/28/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

//#include <FilteredAnalogInput.h>

//int input_pin = 3;
int tmp_sensor = 2;
int output_pin = 1;
//int filter_size = 15;                        //Noise reduction filter size

//FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{
}

void loop() {
  int temp_value = analogRead(tmp_sensor);
  //int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
  if(temp_value < 0)
    temp_value = 0;
  else if(temp_value > 150)
    temp_value = 150;
    
  //We are only mapping 0-1023 from ADC to 0-255
  int output_value = map(temp_value, 0, 150, 0, 255);
  
  analogWrite(output_pin, output_value);
}
