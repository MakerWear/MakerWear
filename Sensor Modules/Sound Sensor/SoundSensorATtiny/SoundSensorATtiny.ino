/*
**  SoundSensorATtiny.ino
**  MakerWear Sound Sensor Module's ATtiny Program.
**
**  Changes voltage output proportionality response to sound (higher voltage
**  means higher sound)
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
**  Created on 12/22/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

//#include <FilteredAnalogInput.h>

//int input_pin = 3;
int sound_sensor_pin = 2;
int output_pin = 1;
//int filter_size = 15;                        //Noise reduction filter size

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

//FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{
}

void loop() {
  
  unsigned long startMillis = millis();  // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level
   
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
   
  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
     sample = analogRead(sound_sensor_pin);
     
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
  
  
  //TODO: add windowing filter to make the output signal smoother and be more stable.
  int out_value = map(volts, 0.0, 10, 0, 255);
  analogWrite(output_pin, out_value);
}
