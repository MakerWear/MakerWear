/*
**  ThermalCameraATtiny.ino
**  MakerWear Thermal Camera Sensor Module's ATtiny Program.
**
**  Changes voltage output proportional to amount of Object's Temperature.
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
#include <TinyThermometer.h>
//#include <FilteredAnalogInput.h>
#include <SoftwareSerial.h>

const int rx = -1;
const int tx = 1;

SoftwareSerial serial(rx, tx);

//int input_pin = 3;                           //Pin 2 on ATtiny
//int output_pin = 1;                            //Pin 6 on ATtiny
//int filter_size = 15;                        //Noise reduction filter size
//int output_value = 0;

TinyThermometer temp = TinyThermometer(); // Create an IRTherm object called temp

//FilteredAnalogInput input(input_pin, filter_size);

void setup() {
  TinyWireM.begin();
  pinMode(tx, OUTPUT);
  serial.begin(9600);
  
  serial.println("Hi");
  
  temp.begin(); // Initialize I2C library and the MLX90614
  
  serial.println("Con");
}

void loop()
{
  serial.print("Ambient = "); serial.print(temp.readAmbientTempC()); 
  serial.print("*C\tObject = "); serial.print(temp.readObjectTempC()); serial.println("*C");
  serial.print("Ambient = "); serial.print(temp.readAmbientTempF()); 
  serial.print("*F\tObject = "); serial.print(temp.readObjectTempF()); serial.println("*F");
  
  serial.println();
  delay(500);
}
