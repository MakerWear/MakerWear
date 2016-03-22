/*
**  PianoSynthesizerArduino.ino
**  MakerWear Piano Synthesizer Module's ATtiny Program.
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
**  Modified on 8/25/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>
#include "Pitches.h"

//Pin Configurations
int input_pin = 3;                           //pin 2 on ATtiny
int buzzer_pin = 1;                          //pin 6 on ATtiny
int filter_size = 25;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{  
  pinMode(buzzer_pin, OUTPUT);
}

void loop() 
{
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
    
  //TODO: Change it to a map function + switch/case to make it more scalable.
  
  if (input_val < 100){
     noTinyTone();
  } else if (input_val > 128 && input_val < 256){
     tinyTone(Note_C, 6);
  } else if (input_val > 256 && input_val < 384){
    tinyTone(Note_D, 6);
  } else if (input_val > 384 && input_val < 512){
    tinyTone(Note_E, 6);
  } else if (input_val > 512 && input_val < 640){
    tinyTone(Note_F, 6);
  } else if (input_val > 640 && input_val < 768){
    tinyTone(Note_G, 6);
  } else if (input_val > 768 && input_val < 896){
    tinyTone(Note_A, 6);
  } else if (input_val > 920){
    tinyTone(Note_B, 7);
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
