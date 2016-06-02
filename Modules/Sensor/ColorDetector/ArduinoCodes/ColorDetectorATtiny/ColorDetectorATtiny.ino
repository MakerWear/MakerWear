/*
**  ColorDetectorATtiny.ino
**  MakerWear ColorDetector Module's ATtiny Program.
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
**  Modified on 01/25/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <TinyWireM.h>
#include <ATtinyColorSensor.h>

int output_pin = 1;                          //Pin 6 on ATtiny
int filter_size = 15;                        //Noise reduction filter size
byte gammatable[256];                        //gamma correction table

ATtinyColorSensor sensor = ATtinyColorSensor(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

byte meanRGB[8][3];

int findColorIndex(int rgb_val[])
{
  int dist, min_dist = 9999;
  int best_color;

  for (int i = 0; i < 7; i++)
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

  byte meanBlack[3] = {84, 84, 67};
  byte meanBlue[3] = {47, 70, 117};
  byte meanGreen[3] = {63, 112, 57};
  byte meanYellow[3] = {255, 255, 130};
  byte meanOrange[3] = {235, 85, 55};
  byte meanRed[3] = {165, 58, 60};
  byte meanWhite[3] = {255, 255, 255};

  meanRGB[0][0] = meanBlack[0]; meanRGB[0][1] = meanBlack[1]; meanRGB[0][2] = meanBlack[2];
  meanRGB[1][0] = meanBlue[0];  meanRGB[1][1] = meanBlue[1];  meanRGB[1][2] = meanBlue[2];
  meanRGB[2][0] = meanGreen[0];  meanRGB[2][1] = meanGreen[1];  meanRGB[2][2] = meanGreen[2];
  meanRGB[3][0] = meanYellow[0];  meanRGB[3][1] = meanYellow[1];  meanRGB[3][2] = meanYellow[2];
  meanRGB[4][0] = meanRed[0];  meanRGB[4][1] = meanRed[1];  meanRGB[4][2] = meanRed[2];
  meanRGB[5][0] = meanWhite[0];  meanRGB[5][1] = meanWhite[1];  meanRGB[5][2] = meanWhite[2];

  //Gamma Correction:
  for (int i = 0; i < 256; i++)
  {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    gammatable[i] = x;
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

  int rgb_val[3] = {r, g, b};

  analogWrite(output_pin, output_value);
}
