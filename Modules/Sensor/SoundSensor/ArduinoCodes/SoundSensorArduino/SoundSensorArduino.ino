/*
**  SoundSensorArduino.ino
**  MakerWear SoundSensor Module's Arduino Program.
**
**  Changes voltage output proportional to sound magnitude (higher voltage
**  means higher sound)
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**  Arduino Pin A1: Sound Sensor
**
**
**  Created on 8/12/15.
**  By Majeed Kazemitabaar
**  Modified on 12/22/15
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

//int input_pin = A0;
int sound_sensor_pin = A0;
int output_pin = 11;
//int filter_size = 15;                 //Noise reduction filter size

//FilteredAnalogInput input(input_pin, filter_size);

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup()
{
  //Just for debugging:
  Serial.begin(9600);
}

void loop()
{
  unsigned long startMillis = millis();  // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level
   
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
   
  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
     sample = analogRead(sound_sensor_pin);
     Serial.println(sample);
     
     if (sample < 1024)  // toss out spurious readings
     {
        if (sample > signalMax)
        {
           signalMax = sample;  // save just the max levels
        }
        else if (sample < signalMin)
        {
           signalMin = sample;  // save just the min levels
        }
     }
  }
  
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 10) / 1024;  // convert to volts
  
/*  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
*/
  
  
  
  int out_value = map(volts, 0.0, 5, 0, 255);
  analogWrite(output_pin, out_value);
  
  //Serial.println(volts);
}

