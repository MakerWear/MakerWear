
/*
* Getting Started example sketch for nRF24L01+ radios
* This is a very basic example of how to send data from one node to another
* Updated: Dec 2014 by TMRh20
*/

#include <SPI.h>
#include "RF24.h"

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/

byte addresses[][6] = {"Pipe1"};


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
  radio.openWritingPipe(addresses[0]);
  
  // Start the radio listening for data
  radio.stopListening();
}

int input_val = 0;

void loop() {
  
  input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 900, 0, 1023);  
  
//   input_val++;

   if (!radio.write( &input_val, sizeof(int) )){
     //print failed
   }
   //otherwise success

  delay(1);
} // Loop

