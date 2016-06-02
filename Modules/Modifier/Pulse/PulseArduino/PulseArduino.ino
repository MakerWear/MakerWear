/*
**  PulseArduino.ino
**  MakerWear Pulse Module's Arduino Program.
**
**  Pulses 5V in a frequency proportional to voltage input (higher voltage
**  equals higher pulse rate)
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
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
 
int input_pin = A0;
int output_pin = 13;
int filter_size = 15;                        //Noise reduction filter size
int min_period = 25;
int max_period = 1000;

FilteredAnalogInput input(input_pin, filter_size);

void setup() {

  pinMode(output_pin, OUTPUT);
  
  //Just For Debugging:
  Serial.begin(9600);

}

void loop() {
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int period;
  
  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;

  period = map(input_val, 0, 1023, max_period, min_period);
  digitalWrite(output_pin, HIGH);

  delay(period);

  period = map(input_val, 0, 1023, max_period, min_period);
  digitalWrite(output_pin, LOW);

  delay(period);
}
