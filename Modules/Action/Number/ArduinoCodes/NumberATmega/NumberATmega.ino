/*
**  NumberATmega.ino
**  MakerWear Number Module's ATtmega Program.
**
**  Display the current voltage from 0-9 on seven segment display
**
**  ATmega Pin Configurations:
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
**  Pin 11 (D5/PWM): SEG-B                   Pin 18  (D12):
**  Pin 12 (D6/PWM): SEG-A                   Pin 17  (D11/PWM): SEG-G
**  Pin 13 (D7): SEG-C                       Pin 16  (D10/PWM):  SEG-F
**  Pin 14 (D8): SEG-D                       Pin 15  (D9/PWM): SEG-E
**
**
**  Created on 6/13/16.
**  By Jason McPeak
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

int display[7] = {6,5,7,8,9,10,11};           // Pins for Segments A-G
int input_pin = A0;                           // pin 23 on ATmega328
int filter_size = 15;                         // Noise reduction filter size

SignalProcessing input(input_pin, filter_size);

/* segment patterns to display 0 - 9 */
const bool digit_patterns[10][7] = {
  {1,1,1,1,1,1,0},  // 0 
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6 
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
}; 


void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(display[i], OUTPUT);
  }
  pinMode(input_pin, INPUT);
}

int input_val;
int number; 
// the loop function runs over and over again forever
void loop() {
  input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int pos = cutAndMap(input_val, 0, 1023, 0, 180);

  number = cutAndMap(input_val, 0, 1023, 0, 9);
  write_digit(number);
}

void write_digit(int digit) {
  write_pattern(digit_patterns[digit]);
}

void write_pattern(const bool* segments) {
  for (int i = 0; i < 7; i++) {
    if (segments[i] == true) {
      digitalWrite(display[i], HIGH);
    } else {
      digitalWrite(display[i], LOW);
    }
  }
}

