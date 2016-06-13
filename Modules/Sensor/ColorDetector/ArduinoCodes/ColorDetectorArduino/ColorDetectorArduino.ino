/*
**  ColorDetectorArduino.ino
**  MakerWear ColorDetector Module's Arduino Program.
**
**  Senses color in red, green & blue but creates a single output
**  using 8-bit representation of color. This is the same color 
**  representation used by the RGB LED action module.
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin SDA: Color Sensor SDA
**  Arduino Pin SCK: Color Sensor SCK
**  Arduino Pin 11: Module Output
**
**
**  Created on 08/26/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <Wire.h>
#include "Adafruit_TCS34725.h"
//#include <FilteredAnalogInput.h>

int input_pin = A0;
int output_pin = 11;
byte gammatable[256];                        //gamma correction table
int filter_size = 15;                        //Noise reduction filter size
uint16_t clear, red, green, blue;

//FilteredAnalogInput input = FilteredAnalogInput(input_pin, filter_size);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
 
void setup() 
{
  Serial.begin(9600);
  Serial.println("Color View Test!");
  
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
  
  //initialize RGB Gamma conversion table:
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;
      
    gammatable[i] = x;      
  }
 
  tcs.setInterrupt(false);                 // turn on LED
 
  delay(60);                               // takes 50ms to read 
  
  tcs.getRawData(&red, &green, &blue, &clear);
 
  tcs.setInterrupt(true);                  // turn off LED
  
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);
 
  // Figure out some basic hex code for visualization
  uint32_t sum = red;
  sum += green;
  sum += blue;
  sum += clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
  Serial.print("\t");
  Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
  Serial.println();
 
  Serial.print((int)r ); Serial.print(" "); Serial.print((int)g);Serial.print(" ");  Serial.println((int)b );
//  colorWipe(strip.Color(gammatable[(int)r], gammatable[(int)g], gammatable[(int)b]), 0);
}
 
void loop() {
  
  //loop is empty because it only takes the color reading once on power up! Turn the scarf off and on again to change the color.
  tcs.getRawData(&red, &green, &blue, &clear);
  
  //TODO: read filtered input
  //TODO: convert RGB to 8 bit color representation
  /*
  
  byte red = (originalColor.red * 8) / 256;
  byte green = (originalColor.green * 8) / 256;
  byte blue = (originalColor.blue * 4) / 256;
  
  byte eightBitColor = (red << 5) | (green << 2) | blue;
  
  https://en.wikipedia.org/wiki/8-bit_color
  
  */
  
  //TODO: need to change the single output value, to a less noisy
  //bit representation
  
    
  uint32_t sum = red;
  sum += green;
  sum += blue;
  sum += clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
  //Serial.print("\t");
  //Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
  //Serial.println();
 
  Serial.print((int)r ); Serial.print(" "); Serial.print((int)g);Serial.print(" ");  Serial.println((int)b );
}

