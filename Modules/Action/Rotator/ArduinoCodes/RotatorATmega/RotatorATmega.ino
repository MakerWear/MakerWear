
/*
**  RotatorATmega.ino
**  MakerWear Rotator Module's ATtmega Program.
**
**  Rotate the LEGO-enabled shaft based on input voltage.
**
**  ATtiny85 Pin Configurations:
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
**  Pin 13 (D7):                             Pin 16  (D10/PWM):  Servo Control
**  Pin 14 (D8):                             Pin 15  (D9/PWM):
**
**
**  Created on 6/02/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/
#include <Servo.h>
#include <SignalProcessing.h>

Servo myservo;

int input_pin = A0;                              //pin 23 on ATmega328
int filter_size = 15;                        //Noise reduction filter size
int servo_pin = 10; //D10

SignalProcessing input(input_pin, filter_size);

void setup()
{
  myservo.attach(servo_pin);
}

void loop()
{
    int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
    /*if (input_val < 0)
      input_val = 0;
    else if(input_val > 1023)
      input_val = 1023;*/

    int pos = cutAndMap(input_val, 0, 1023, 0, 180);

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
}
