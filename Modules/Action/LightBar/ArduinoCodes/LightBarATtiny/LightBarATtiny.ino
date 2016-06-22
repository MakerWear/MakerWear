/*
**  LightBarATtiny.ino
**  MakerWear LightBar Module's ATtiny Program.
**
**  Lights up the LEDS proportional to voltage input.
**  Could be used for all sorts of things from serving as a visualization
**  for how loud sound is currently to how much the person is moving to
**  simply helping a child debug their MakerWear design.
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   LED4
**  Pin 3 (D4/A2): LED2                  Pin 6 (D1/PWM/MISO): LED3
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): LED1
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Last modified and tested on 6/22/16
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

//Pin Configurations:
int input_pin = 3;                           //module input, pin 2 on ATtiny
const int LED_COUNT = 4;                     //number of LEDs
int filter_size = 25;                        //noise reduction filter size
int bargraph_led[LED_COUNT] = {0, 4, 1, 2};  //LED pin numbers pin {3, 5, 6, 7} on ATtiny

const uint8_t PROGMEM gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

SignalProcessing input(input_pin, filter_size);

void setup() 
{
  //initialize all LEDs as OUTPUT:
  for(int i = 0; i < LED_COUNT; i++)
    pinMode(bargraph_led[i], OUTPUT);
}

int state = 0;
int threshold = 10;

void loop()
{
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int led_val;
  /*if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;*/
  
  if(state == 0 && input_val > 256 + 196 + threshold)
    state = 1;
  else if(state == 1 && input_val < 256 + 196 - threshold)
    state = 0;
  else if(state == 1 && input_val > 512 + 196 + threshold)
    state = 2;
  else if(state == 2 && input_val < 512 + 196 - threshold)
    state = 1;
  else if(state == 2 && input_val > 768 + 196 + threshold)
    state = 3;
  else if(state == 3 && input_val < 768 + 196 - threshold)
    state = 2;


  switch(state)
  {
    case 0:
      if(input_val < 256)
        led_val = pgm_read_byte(&gamma[input_val]);
      else
        led_val = 255;
      
      analogWrite(bargraph_led[0], led_val);
      digitalWrite(bargraph_led[1], LOW);
      digitalWrite(bargraph_led[2], LOW);
      digitalWrite(bargraph_led[3], LOW);
      break;

    case 1:
      analogWrite(bargraph_led[0], 255);
      digitalWrite(bargraph_led[1], HIGH);
      digitalWrite(bargraph_led[2], LOW);
      digitalWrite(bargraph_led[3], LOW);
      break;
      
    case 2:
      analogWrite(bargraph_led[0], 255);
      digitalWrite(bargraph_led[1], HIGH);
      digitalWrite(bargraph_led[2], HIGH);
      digitalWrite(bargraph_led[3], LOW);
      break;
      
    case 3:
      analogWrite(bargraph_led[0], 255);
      digitalWrite(bargraph_led[1], HIGH);
      digitalWrite(bargraph_led[2], HIGH);
      digitalWrite(bargraph_led[3], HIGH);
      break;
  }
}

