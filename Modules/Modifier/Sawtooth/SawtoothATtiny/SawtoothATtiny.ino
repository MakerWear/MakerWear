/*
**  PulseMeterArduino.ino
**  MakerWear Sawtooth Wave Module's ATtiny Program.
**
**  Amplitude based on input voltage, frequency based on potentiometer.
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): Potentiometer         Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
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
#define pi 3.1415927

int input_pin = 3;                           //Pin 2 on ATtiny
int pot_pin = 2;
int output_pin = 1;                          //Pin 6 on ATtiny
int filter_size = 5;                        //Noise reduction filter size
int i = 0;

SignalProcessing input(input_pin, filter_size);

int sawtooth(){
  static int k;
  if(k >= 60){
    k = 0;
  }
  if(k%60 < 30){
    return 8*(k++);
  }
  else{
    return (-8*(k++) + 472);
  }
}


void setup() {
  pinMode(output_pin, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  
  if(i >= 256){
    i = 0;
  }
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int amplitude = input_val/4;
  int pot_val = analogRead(pot_pin);
  int freq = cutAndMap(pot_val, 0, 1023, 1, 30);
  int output_val = 
  
  analogWrite(output_pin, output_val);
  delay(freq);
}






