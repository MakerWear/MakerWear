/*
**  ColorDetectorArduino.ino
**  MakerWear ColorDetector Module's Arduino Program.
**  
**  Senses color and finds the nearest color between Black, Blue, Cyan, Lime
**  Yellow, Red, Magenta, and White. Each color corresponds to a certain 
**  output voltage that could be read by the MultiColorLight (as well as 
**  corresponding to the temperature of the color).
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin D2: Module Input
**
**
**  Created on 01/25/16.
**  By Majeed Kazemitabaar
**  Modified on 06/07/16  
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>
#include <Adafruit_TCS34725.h>
#include "Adafruit_TCS34725.h"
#include <Wire.h>

int input_pin = 2;
int output_pin = 11;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
byte meanRGB[8][3];
int filter_size = 15;                        //Noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

int findColorIndex(int rgb_val[])
{
  int dist, min_dist = 9999;
  int best_color;

  for (int i = 0; i < 8; i++)
  {
    dist = sqrt(pow(abs(meanRGB[i][0] - rgb_val[0]), 2) +
                pow(abs(meanRGB[i][1] - rgb_val[1]), 2) +
                pow(abs(meanRGB[i][2] - rgb_val[2]), 2));

    if (dist < min_dist)
    {
      min_dist = dist;
      best_color = i;
    }
  }

  return best_color;
}

void setup() {
  pinMode(input_pin, INPUT);
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }

  //initialize color mean values:
  byte black[3] = {85, 85, 65};
  byte blue[3] = {45, 75, 120};
  byte cyan[3] = {55, 130, 135};
  byte lime[3] = {60, 120, 60};
  byte yellow[3] = {255, 255, 100};
  byte red[3] = {165, 55, 60};
  byte magenta[3] = {130, 55, 100};
  byte white[3] = {255, 255, 255};

  meanRGB[0][0] = black[0]; meanRGB[0][1] = black[1]; meanRGB[0][2] = black[2];
  meanRGB[1][0] = blue[0];  meanRGB[1][1] = blue[1];  meanRGB[1][2] = blue[2];
  meanRGB[2][0] = cyan[0];  meanRGB[2][1] = cyan[1];  meanRGB[2][2] = cyan[2];
  meanRGB[3][0] = lime[0];  meanRGB[3][1] = lime[1];  meanRGB[3][2] = lime[2];
  meanRGB[4][0] = yellow[0];  meanRGB[4][1] = yellow[1];  meanRGB[4][2] = yellow[2];
  meanRGB[5][0] = red[0];  meanRGB[5][1] = red[1];  meanRGB[5][2] = red[2];
  meanRGB[6][0] = magenta[0];  meanRGB[6][1] = magenta[1];  meanRGB[6][2] = magenta[2];
  meanRGB[7][0] = white[0];  meanRGB[7][1] = white[1];  meanRGB[7][2] = white[2];
}
int index;


void loop() {
  uint16_t clear, red, green, blue;

  if (digitalRead(input_pin))
  {
    // turn on LED
    tcs.setInterrupt(false);
    // takes some time to read
    delay(55);  
    tcs.getRawData(&red, &green, &blue, &clear);
    // turn off LED
    tcs.setInterrupt(true);  
    
    uint32_t sum = clear;
    float r, g, b;
    r = red; r /= sum;
    g = green; g /= sum;
    b = blue; b /= sum;
    r *= 256; g *= 256; b *= 256;
    
    int rgb_val[3] = {r, g, b};
    index = findColorIndex(rgb_val);
  }
  else
    tcs.setInterrupt(true);  // turn off LED

  switch (index)
  {
    case 0:
      Serial.println("Black");
      break;
    case 1:
      Serial.println("Blue");
      break;
    case 2:
      Serial.println("Cyan");
      break;
    case 3:
      Serial.println("Lime");
      break;
    case 4:
      Serial.println("Yellow");
      break;
    case 5:
      Serial.println("Red");
      break;
    case 6:
      Serial.println("Magenta");
      break;
    case 7:
      Serial.println("White");
      break;
  }
}
