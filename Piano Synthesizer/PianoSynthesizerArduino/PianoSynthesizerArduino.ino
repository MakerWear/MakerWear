#include "Pitches.h"

//Pin Configurations
int input_pin = A0;
int buzzer_pin = 6;

//Piano Notes
int notes[] = {NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6, NOTE_C7};

void setup() {
  //Just For Debugging:
  //Serial.begin(9600);
}

void loop() {
  int input_value = analogRead(input_pin);
  int buzzer_value = notes[0];
  
  if (input_value <= 128  && input_value > 0){
    buzzer_value = notes[0];
  } else if (input_value <= 256  && input_value > 128){
    buzzer_value = notes[1];
  } else if (input_value <= 384 && input_value > 256){
    buzzer_value = notes[2];
  } else if (input_value <= 512 && input_value > 384){
    buzzer_value = notes[3];
  } else if (input_value <= 640 && input_value > 512){
    buzzer_value = notes[4];
  } else if (input_value <= 768 && input_value > 640){
    buzzer_value = notes[5];
  } else if (input_value <= 896 && input_value > 768){
    buzzer_value = notes[6];
  } else if (input_value <= 1024 && input_value > 896){
    buzzer_value = notes[7];
  }
  
  tone(buzzer_pin, buzzer_value);
  
  //Just For Debugging:
  //Serial.println(buzzer_value);
}
