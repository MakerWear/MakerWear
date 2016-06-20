/*
**  PulseSensorArduino.ino
**  MakerWear PulseSensor Module's Arduino Program.
**
**  Outputs a voltage whenever the users heartbeat is detected. Output
**  is proportional to the input from previous module
**
**  Based off Pulse Sensor Amped 1.4 code by Joel Murphy and Yury Gitman 
**  http://www.pulsesensor.com  
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 9: Module Output
**  Arduino Pin A0: Module Input
**  Arduino Pin A1: Pulse Sensor Input  
**
**  Created on 6/10/15.
**  By Majeed Kazemitabaar
**  Modified on 8/26/15
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

//  Variables
int input_pin = A0;                  // module input
int pulse_pin = A5;                  // Pulse Sensor purple wire connected to analog pin 0
int output_pin = 9;                  // module output
int filter_size = 15;    

SignalProcessing input(input_pin, filter_size);

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

volatile boolean blinkFlag = false;

void setup(){
  pinMode(output_pin,OUTPUT);         // pin that will blink to your heartbeat!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
}


int input_val;
int output_val;
void loop(){
  input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  if (QS == true){      // Quantified Self "QS" true when arduino finds a heartbeat
    QS = false;         // reset the Quantified Self flag for next time    
    if (blinkFlag) {
      blinkFlag = false;


      output_val = cutAndMap(input_val, 0, 1023, 0, 255);
      
      analogWrite(output_pin, output_val);
      delay(100);
      analogWrite(output_pin, 0);
      
    }
  }

}




