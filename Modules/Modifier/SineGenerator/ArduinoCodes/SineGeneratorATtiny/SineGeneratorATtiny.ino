/*
**  PulseMeterArduino.ino
**  MakerWear Sine Wave Module's ATtiny Program.
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
**  Created on 06/30/16.
**  By Alexander Jiao
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/
#include <SignalProcessing.h>

const uint8_t PROGMEM sinTable[] = {
127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,
217,219,221,223,225,227,229,231,233,234,236,238,239,240,242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254,
254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,221,219,
217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,
127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,78,76,73,70,67,64,62,59,56,54,51,49,46,44,42,39,37,35,33,31,29,27,25,23,
21,20,18,16,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,16,18,20,21,23,25,27,29,31,
33,35,37,39,42,44,46,49,51,54,56,59,62,64,67,70,73,76,78,81,84,87,90,93,96,99,102,105,108,111,115,118,121,124
};                                            //table holding all sine values

int input_pin = 3;                           //Pin 2 on ATtiny
int pot_pin = 2;
int output_pin = 1;                          //Pin 6 on ATtiny
int filter_size = 5;                        //Noise reduction filter size
int i = 0;
unsigned long interval = 1000;
unsigned long previousMillis = 0;
int min_period = 25;
int max_period = 1000;
int output_val = 0;

SignalProcessing input(input_pin, filter_size);

void setup() {
  pinMode(output_pin, OUTPUT);
  //Serial.begin(57600);
}

void loop() {
  
  if(i >= 256){                  //table has 256 values, reset i to 0 to simulate periodicity
    i = 0;
  }
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int pot_val = analogRead(pot_pin);

  int amplitude = input_val/4;
  interval = map(pot_val, 0, 1023, max_period, min_period);   //need second map because input_val is used below
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval){
    output_val = cutAndMap(pgm_read_byte(&sinTable[i++]), 0, 254, 0, amplitude);     //get next value from table and output it.  254 because that is the largest value in the table
    previousMillis = currentMillis;                             // save the last time you changed values
  }
  //if it is not time to change values, output will remain the same
  analogWrite(output_pin, output_val);
}






