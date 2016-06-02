/*
**  ServoMotorArduino.ino
**  MakerWear Servo Motor Module's Arduino Program.
**
**  Rotate the LEGO-enabled shaft based on input voltage.
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 9: Servo Motor Control Pin
**  Arduino Pin A0: Module Input
**
**
**
**  Created on 02/01/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

//#include <FilteredAnalogInput.h>
#include <Servo.h>

Servo myservo;

int pos = 0;

int input_pin = A0;                           
int servo_pin = 11;                             
//int filter_size = 15;                        //Noise reduction filter size

//FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{  
  myservo.attach(servo_pin);
}

void loop() 
{
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
}
