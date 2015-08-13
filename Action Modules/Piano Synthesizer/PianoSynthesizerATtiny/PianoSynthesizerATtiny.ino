#include "Pitches.h"

//Pin Configurations
int input_pin = 3; //pin 2 on ATtiny
int buzzer_pin = 1; //pin 6 on ATtiny

void setup() {  
  //Just For Debugging:
  //Serial.begin(9600);
}

void loop() {
  int input_value = analogRead(input_pin);
  //int buzzer_value = Note_C;
  
  if (input_value <= 128  && input_value > 0){
     tinyTone(Note_C, 6);
  } else if (input_value <= 256  && input_value > 128){
     tinyTone(Note_D, 6);
  } else if (input_value <= 384 && input_value > 256){
    tinyTone(Note_E, 6);
  } else if (input_value <= 512 && input_value > 384){
    tinyTone(Note_F, 6);
  } else if (input_value <= 640 && input_value > 512){
    tinyTone(Note_G, 6);
  } else if (input_value <= 768 && input_value > 640){
    tinyTone(Note_A, 6);
  } else if (input_value <= 896 && input_value > 768){
    tinyTone(Note_B, 6);
  } else if (input_value <= 1024 && input_value > 896){
    tinyTone(Note_C, 7);
  }
    
  //Just For Debugging:
  //Serial.println(buzzer_value);
}

void tinyTone(unsigned char divisor, unsigned char octave)
{
  //TCCR1 = 0x90 | (8-octave); // for 1MHz clock
  TCCR1 = 0x90 | (11-octave); // for 8MHz clock
  OCR1C = divisor-1;         // set the OCR
}

void noTinyTone()
{
  TCCR1 = 0x90;
}

