/*
**  SoundSensorATtiny.ino
**  MakerWear SoundSensor Module's ATtiny Program.
**
**  Changes voltage output proportionality response to sound (higher voltage
**  means higher sound)
**
**  Programmed with ATtiny (last option in the menu )
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

#include <FilteredAnalogInput.h>
//#include <SoftwareSerial.h>

int input_pin = 3;
int sound_sensor_pin = 2;
int output_pin = 1;
int filter_size = 15;                        //Noise reduction filter size

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
int sample;

FilteredAnalogInput input(input_pin, filter_size);

//const int rx = -1;
//const int tx = 2;

//SoftwareSerial serial(rx, tx);


void setup()
{
  //pinMode(rx, INPUT);
  //pinMode(tx, OUTPUT);
  //serial.begin(9600);
  pinMode(output_pin, OUTPUT);
}

void loop() {
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if (input_val < 0)
    input_val = 0;
  else if (input_val > 1023)
    input_val = 1023;

  long startMillis = millis();  // Start of sample window
  int peakToPeak = 0;   // peak-to-peak level

  int signalMax = 0;
  int signalMin = 1024;

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(sound_sensor_pin);

    //serial.println(sample);

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
  int volts = peakToPeak / 3;

  //   double volts = (peakToPeak * 3.3) / 1024;  // convert to volts



  //int out_value = map(volts, 10, 75, 0, input_val / 4);
  //analogWrite(output_pin, out_value);

  serial.println(volts);
  
  delay(100);
}
