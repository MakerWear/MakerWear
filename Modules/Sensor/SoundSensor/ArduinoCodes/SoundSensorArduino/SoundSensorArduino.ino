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
int output_pin = 9;                    //pin 17 on ATtiny
//int filter_size = 15;                 //Noise reduction filter size

//FilteredAnalogInput input(input_pin, filter_size);

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup()
{
  //Just for debugging:
  Serial.begin(9600);
  pinMode(output_pin, OUTPUT);
}

void loop()
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
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
   if(peakToPeak > 200)
    peakToPeak = 200;
   if(peakToPeak < 20)
    peakToPeak = 20;
    
   int out_value = map(peakToPeak, 20, 200, 0, 255);
   analogWrite(output_pin, out_value);

   Serial.println(out_value);
}

