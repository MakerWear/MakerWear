
/*
* Getting Started example sketch for nRF24L01+ radios
* This is a very basic example of how to send data from one node to another
* Updated: Dec 2014 by TMRh20
*/

#include <SPI.h>
#include "RF24.h"

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 0;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};


#include <SignalProcessing.h>

const int input_pin = A0;       // pin 23 on ATmega328
const int filter_size = 10;     // Noise reduction filter size                        

SignalProcessing input(input_pin, filter_size);

void setup() {
  
  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
  // Open a writing and reading pipe on each radio, with opposite addresses
  if(radioNumber){
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  }else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
  
  // Start the radio listening for data
  radio.stopListening();
}

int input_val;

void loop() {

  input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 900, 0, 1023);  
  

     if (!radio.write( &input_val, sizeof(int) )){
       //print failed
     }
     //otherwise success

  delay(50);
} // Loop

