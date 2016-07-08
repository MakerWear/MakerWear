/*
**  ModuleNameATmega.ino
**  MakerWear ModuleName Module's ATmega Program.
**
**  Description
**  Description
**  Description
**
**
**  ATmega328 Pin Configurations:
**
**  Pin 1  (Reset):                          Pin 28  (A5):  
**  Pin 2  (D0/RX):                          Pin 27  (A4):
**  Pin 3  (D1/TX):                          Pin 26  (A3):
**  Pin 4  (D2):                             Pin 25  (A2):
**  Pin 5  (D3/PWM):                         Pin 24  (A1):
**  Pin 6  (D4):                             Pin 23  (A0):       Module Input
**  Pin 7  (PWR):                            Pin 22  (GND):
**  Pin 8  (GND):                            Pin 21  (AREF):
**  Pin 9  (XTAL1):                          Pin 20  (AVCC):
**  Pin 10 (XTAL2):                          Pin 19  (D13):
**  Pin 11 (D5/PWM):                         Pin 18  (D12):
**  Pin 12 (D6/PWM):                         Pin 17  (D11/PWM):
**  Pin 13 (D7):                             Pin 16  (D10/PWM):
**  Pin 14 (D8):                             Pin 15  (D9/PWM):   Module Output
**
**
**  Created on xx/yy/zz.
**  By Akbar Akbari
**  Modified on xx/yy/zz.
**  By Asghar Asghari
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int input_pin = A0;                         //pin 23 on ATmega328
int filter_size = 15;                       //Noise reduction filter size
int output_pin = 9;                         //pin PB1 (OC1A) PWM

SignalProcessing input(input_pin, filter_size);

void setup()
{
  mlx.begin();
}

void loop()
{
    int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);


    int temperature = mlx.readObjectTempF();

    //mapping everything to: 32F - 150F
    
    int output_val = cutAndMap(temperature, 32, 150, 0, 255);
    
    // shouldn't do anything when input voltage is 0
    if(cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023) <= 15)
      analogWrite(output_pin, 0);
    else
      analogWrite(output_pin, output_val);
}
