/*
**  SoundSensorATtiny.ino
**  MakerWear Sound Sensor Module's ATtiny Program.
**
**  A microphone/sound sensor that detects sound levels and outputs voltage accordingly.
**
**
**  ATtiny Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): Sound Sensor          Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**
**  Created on 8/8/16.
**  By Alex Jiao
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/
#include "SignalProcessing.h"

int output_pin = 1;                          //Pin 6 on ATtiny
int input_pin = A3;                          //Pin 2  
int sensor_pin = A2;                         //Pin 3
int filter_size = 15;                        //Noise reduction filter size
const int sample_window = 50;                // Sample window width in mS (50 mS = 20Hz)

SignalProcessing input(input_pin, filter_size);

void setup() {
  pinMode(output_pin, OUTPUT);  
}

void loop() {

  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int sensor_val;
  int output_val;              
  unsigned long start_millis= millis();                       // Start of sample window
  unsigned int signal_max = 0;
  unsigned int signal_min = 1024;


  while (millis() - start_millis < sample_window){
      sensor_val = analogRead(sensor_pin);
      if (sensor_val < 1024){  // toss out spurious readings
         if (sensor_val > signal_max){
            signal_max = sensor_val;  // save the max levels
         }
         else if (sensor_val < signal_min){
            signal_min = sensor_val;  // save the min levels
         }
      }
  }
  if(signal_max - signal_min <= 10){            //when there is only background noise, output nothing
      output_val = 0;
  }
  else if(signal_max - signal_min <=100){
    output_val = cutAndMap(signal_max-signal_min, 10, 100, input_val/36, input_val/5);
  }
  else{ 
      output_val = cutAndMap(signal_max-signal_min, 100, 350, input_val/5, input_val/4);
  }
  analogWrite(output_pin, output_val);

}
