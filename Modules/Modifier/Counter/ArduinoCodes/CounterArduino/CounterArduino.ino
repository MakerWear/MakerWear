/*
**  CounterArduino.ino
**  MakerWear Counter Module's Arduino Program.
**
**  increases output voltage by a single step (to be read by the Number 
**  module) upon receiving a rising edge on the input pin.
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**
**
**  Created on 06/11/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

//0-300 is LOW
//700-1023 is HIGH

#define THRESH_LOW 300
#define THRESH_HIGH 700

int input_pin = A0;
int output_pin = 11;
int filter_size = 15;                        //Noise reduction filter size
short countable = 1; 
unsigned int counter;

SignalProcessing input(input_pin, filter_size);

void setup()
{
  pinMode(output_pin, OUTPUT);
  
  //Just For Debugging:
  Serial.begin(9600);
}

void loop() 
{
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
 
  if((input_val > THRESH_HIGH) && (countable == 1)){
    (counter==9)?(counter=0):(counter++);
    countable = 0;   
  }
  else if((input_val < THRESH_LOW) && (countable == 0)){
    countable = 1;
  }
  Serial.print("Countable: ");
  (countable==1)?Serial.print("YES  "):Serial.print("NO  ");
  Serial.print("Count: ");
  Serial.println(counter);
  analogWrite(output_pin, cutAndMap(counter, 0, 9, 0, 255));
  delay(1);
}
