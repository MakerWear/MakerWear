/*
**  SoundMakerArduino.ino
**  MakerWear SoundMaker Module's ATtiny Program.
**
**  Similar to Piezzo Buzzer but a more melodic sound (far less cacophonous).
**  Plays a scale based on input level. If you hooked up more than one, you
**  could start to play chords. Instead (or in addition to) the piano, could
**  have other instruments like a saxaphone or flute. The key is it should 
**  sound nice to the ears in contrast to the piezo.
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Buzzer
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**  Programming Options (Arduino as ISP):
**  Bootloader: ATtiny85 @ 1MHz Internal Oscillator, BOD Disabled
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Last modified and tested on 6/21/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>
#include "Pitches.h"

//Pin Configurations
int input_pin = 3;                           //pin 2 on ATtiny
int buzzer_pin = 1;                          //pin 6 on ATtiny
int filter_size = 25;                        //Noise reduction filter size

SignalProcessing input(input_pin, filter_size);

void setup() 
{  
  pinMode(buzzer_pin, OUTPUT);
}

int state = 0;
int threshold = 18;

void loop() 
{
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(state == 0 && input_val > 114 + threshold)
    state = 1;
  else if(state == 1 && input_val < 114 - threshold)
    state = 0;
  else if(state == 1 && input_val > 227 + threshold)
    state = 2;
  else if(state == 2 && input_val < 227 - threshold)
    state = 1;
  else if(state == 2 && input_val > 341 + threshold)
    state = 3;
  else if(state == 3 && input_val < 341 - threshold)
    state = 2;
  else if(state == 3 && input_val > 454 + threshold)
    state = 4;
  else if(state == 4 && input_val < 454 - threshold)
    state = 3;
  else if(state == 4 && input_val > 567 + threshold)
    state = 5;
  else if(state == 5 && input_val < 567 - threshold)
    state = 4;
  else if(state == 5 && input_val > 681 + threshold)
    state = 6;
  else if(state == 6 && input_val < 681 - threshold)
    state = 5;
  else if(state == 6 && input_val > 794 + threshold)
    state = 7;
  else if(state == 7 && input_val < 794 - threshold)
    state = 6;
  else if(state == 7 && input_val > 908 + threshold)
    state = 8;
  else if(state == 8 && input_val < 908 - threshold)
    state = 7;
    
  switch(state)
  {
    case 0:
      noTinyTone();
      break;
    
    case 1:
      tinyTone(Note_C, 6);
      break;

    case 2:
      tinyTone(Note_D, 6);
      break;

    case 3:
      tinyTone(Note_E, 6);
      break;

    case 4:
      tinyTone(Note_F, 6);
      break;

    case 5:
      tinyTone(Note_G, 6);
      break;

    case 6:
      tinyTone(Note_A, 6);
      break;

    case 7:
      tinyTone(Note_B, 6);
      break;

    case 8:
      tinyTone(Note_C, 7);
      break;
  }
}

void tinyTone(unsigned char divisor, unsigned char octave)
{
  TCCR1 = 0x90 | (8-octave); // for 1MHz clock
  //TCCR1 = 0x90 | (11-octave); // for 8MHz clock
  OCR1C = divisor-1;         // set the OCR
}

void noTinyTone()
{
  TCCR1 = 0x90;
}
