/*
**  ColorSensorATtiny.ino
**  MakerWear Color Sensor Module's ATtiny Program.
**
**  Senses color in red, green & blue but creates a single output using 8-bit representation of color. This is the same color representation used by the RGB LED action module.
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   SCK
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): SDA
**
**
**  Created on 8/26/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <TinyWireM.h>
#include <ATtinyColorSensor.h>
#include <FilteredAnalogInput.h>


//const int redpin = 3;
const int greenpin = 1;
//const int bluepin = 6;
int input_pin = 3;                           //Pin 2 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny
int filter_size = 15;                        //Noise reduction filter size
byte gammatable[256];                        //gamma correction table

FilteredAnalogInput input(input_pin, filter_size);

// set to false if using a common cathode LED
#define commonAnode false


ATtinyColorSensor sensor = ATtinyColorSensor(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {

  //Gamma Correction:
  for (int i=0; i<256; i++) 
  {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;
      
    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;      
    }
  }
}

void loop() {
  uint16_t clear, red, green, blue;

  sensor.setInterrupt(false);      // turn on LED

  delay(55);  // takes 50ms to read 
  
  sensor.getRawData(&red, &green, &blue, &clear);

  sensor.setInterrupt(true);  // turn off LED

  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  //analogWrite(redpin, gammatable[(int)r]);
  analogWrite(greenpin, gammatable[(int)g]);
  //analogWrite(bluepin, gammatable[(int)b]);
  
  //TODO: read filtered input
  //TODO: convert RGB to 8 bit color representation
  /*
  
  byte red = (originalColor.red * 8) / 256;
  byte green = (originalColor.green * 8) / 256;
  byte blue = (originalColor.blue * 4) / 256;
  
  byte eightBitColor = (red << 5) | (green << 2) | blue;
  
  https://en.wikipedia.org/wiki/8-bit_color
  
  */

}
