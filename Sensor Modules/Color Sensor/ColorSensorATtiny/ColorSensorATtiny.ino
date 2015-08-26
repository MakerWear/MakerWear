#include <ATtinyColorSensor.h>

#include <TinyWireM.h>
#include "ATtinyColorSensor.h"

/*
** ATtiny Pin 1 = (RESET) N/U                      ATtiny Pin 2 = isInitialized?
** ATtiny Pin 3 = N/U                              ATtiny Pin 4 = GND
** ATtiny Pin 5 = SDA                              ATtiny Pin 6 = Green!
** ATtiny Pin 7 = SCK                              ATtiny Pin 8 = VCC (2.7-5.5V)
*/


//const int redpin = 3;
const int greenpin = 1;
//const int bluepin = 6;

// set to false if using a common cathode LED
#define commonAnode false

// our RGB -> eye-recognized gamma color
byte gammatable[256];

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

}
