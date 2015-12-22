/*
**  TiltSensorATtiny.ino
**  MakerWear Tilt Sensor Module's ATtiny Program.
**
**  Changes voltage output (GND or PWR) based it on the sensor's tilt status.
**  If the module is tilted, it would send PWR otherwise, 0 Volts.
**
**  ATtiny Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): Tilt Sensor
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 10/26/15
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

//#include <FilteredAnalogInput.h>

//int input_pin = 3;
int tilt_sensor = 0;
int output_pin = 1;
//int filter_size = 15;                        //Noise reduction filter size

//FilteredAnalogInput input(input_pin, filter_size);

void setup() {
  pinMode(tilt_sensor, INPUT);
}

void loop() {
  
  //TODO: if HIGH, should read from input, and analogWrite the value 
  //that it reads (divided by 4 to maintain 1024 (10bit) -> 256 (8bit)
  //conversion)
  
  if(digitalRead(tilt_sensor) == HIGH)
    analogWrite(output_pin, 255);
  else
    analogWrite(output_pin, 0);
}                                                                                                                                                                                                                                                                                            
