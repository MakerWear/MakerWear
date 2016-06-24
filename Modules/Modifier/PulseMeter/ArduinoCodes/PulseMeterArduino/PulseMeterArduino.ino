/*
**  PulseMeterArduino.ino
**  MakerWear Pulse Meter Module's Arduino Program.
**
**  Changes output voltage based on input frequency. Measures frequency
**  of HIGH pulses for last 10 seconds.
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
#define THRESH_HIGH 500
#define WINDOWSIZE 20
#define sampleRate 100    //time between samples in milliseconds

int input_pin = A0;
int output_pin = 11;
int filter_size = 5;                        //Noise reduction filter size

unsigned int counter=0;
uint8_t wavelengths[WINDOWSIZE]={0};
unsigned long pulseStart;
short temp = 0;
short freq = 0;

SignalProcessing input(input_pin, filter_size);

int average(){
  uint8_t i;
  int total=0;
  for(i=0; i<((temp == 0)?counter:WINDOWSIZE); i++){
    total += wavelengths[i];
  }
  
  return (int)(total/((temp == 0)?counter:WINDOWSIZE));
}
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
  //Just For Debugging:
  //Serial.begin(9600);
}

void loop() 
{
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
 
  /*if((input_val > THRESH_HIGH) && (countable == 1)){           //starts measuring from first HIGH pulse
    pulseStart = millis();
    countable = 0;   
  }*/
  if((input_val > THRESH_HIGH)){     //checks if HIGH
    wavelengths[counter++] = 1;
    //pulseStart = millis();
    //countable = 0;
    //avg = average();
  }
  else if((input_val < THRESH_LOW)){       //checks if LOW
    wavelengths[counter++] = 0;
  }
  
  if(counter == WINDOWSIZE){
    if(temp == 0){
      temp = 1;
    }                                  
    counter = 0;  
  }
  
  freq = processArray();
  //Serial.println(avg);
  analogWrite(output_pin, cutAndMap(freq, 0, WINDOWSIZE, 0, 255));
  delay(sampleRate);
}
