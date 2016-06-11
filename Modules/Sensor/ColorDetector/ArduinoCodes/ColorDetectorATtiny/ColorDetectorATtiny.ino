/*
**  ColorDetectorArduino.ino
**  MakerWear ColorDetector Module's ATtiny Program.
**
**  Senses color and finds the nearest color between Black, Blue, Cyan, Lime
**  Yellow, Red, Magenta, and White. Each color corresponds to a certain
**  output voltage that could be read by the MultiColorLight (as well as
**  corresponding to the temperature of the color).
**
**  ATtiny85 Pin Configurations:
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
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
#include <TinyWireM.h>
#include <ATtinyColorSensor.h>

int input_pin = 3;                           //Pin 2 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny
ATtinyColorSensor sensor = ATtinyColorSensor(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
byte meanRGB[8][3];
int color_index = 0;  //each color corresponds to an index between 0 to 7.

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

void loop() {
  uint16_t clear, red, green, blue;

  if (digitalRead(input_pin))
  {
    sensor.setInterrupt(false); // turn on LED
    delay(55);  // takes 50ms to read
    sensor.getRawData(&red, &green, &blue, &clear);
    sensor.setInterrupt(true);  // turn off LED

    uint32_t sum = clear;
    float r, g, b;

    r = red; r /= sum;
    g = green; g /= sum;
    b = blue; b /= sum;
    r *= 256; g *= 256; b *= 256;

    int rgb_val[3] = {r, g, b};
    color_index = findColorIndex(rgb_val);
  }
  else
  {
    //color_index will retain its previous value.
    sensor.setInterrupt(true);  // turn off LED
  }

  int output_val = 0;

  if (color_index == 0)
    output_val = 0;
  else if (color_index == 7)
    output_val = 255;
  else
    output_val = color_index * 32 + 16;

  analogWrite(output_pin, output_val);
}
