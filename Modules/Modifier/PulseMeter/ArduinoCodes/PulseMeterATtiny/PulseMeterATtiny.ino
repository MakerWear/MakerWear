/*
**  PulseMeterArduino.ino
**  MakerWear Pulse Meter Module's ATtiny Program.
**
**  Changes output voltage based on input frequency. Measures frequency
**  of HIGH pulses for last 10 seconds.
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

#define THRESH_LOW 300    //0-300 is LOW
#define THRESH_HIGH 500   //700-1023 is HIGH
#define WINDOWSIZE 20
#define sampleRate 100    //time between samples in milliseconds

int input_pin = 3;                           //Pin 2 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny

int filter_size = 15;                        //Noise reduction filter size

unsigned int counter=0;
uint8_t wavelengths[WINDOWSIZE]={0};
unsigned long pulseStart;
short temp = 0;                      //when temp=0, we are on first run after startup: array is still being filled
short freq = 0;

SignalProcessing input(input_pin, filter_size);

short processArray(){
  int i,j=0;
  for(i = 0; i<WINDOWSIZE; i++){
    if(wavelengths[i] == 1)
      j++;
  }
  return j;
}
void setup()
{
  pinMode(output_pin, OUTPUT);
}

void loop() 
{
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
 
  if((input_val > THRESH_HIGH)){     //checks if HIGH
    wavelengths[counter++] = 1;
  }
  else if((input_val < THRESH_LOW)){       //checks if LOW
    wavelengths[counter++] = 0;
  }
  
  if(counter == WINDOWSIZE){               //makes sure counter does not get too high
    if(temp == 0){
      temp = 1;
    }                                  
    counter = 0;  
  }
  
  freq = processArray();
  analogWrite(output_pin, cutAndMap(freq, 0, WINDOWSIZE, 0, 255));
  delay(sampleRate);
}
