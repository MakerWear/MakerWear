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
**  Modified on 8/24/15, 3/26/16
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

//Pin Configurations:
int input_pin = 3;                           //module input, pin 2 on ATtiny
const int LED_COUNT = 4;                     //number of LEDs
int filter_size = 15;                        //noise reduction filter size
int bargraph_led[LED_COUNT] = {0, 4, 1, 2};  //LED pin numbers pin {3, 5, 6, 7} on ATtiny


FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{
  //initialize all LEDs as OUTPUT:
  for(int i = 0; i < LED_COUNT; i++)
    pinMode(bargraph_led[i], OUTPUT);
}

void loop()
{
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
  
  if(input_val < 256)
  {
    analogWrite(bargraph_led[0], (1/(1+exp(((input_val/21)-6)*-1)))*256);
  }
  else
  {
    int on_leds = map(input_val, 0, 1023, 0, LED_COUNT);

    for(int i = 0; i < LED_COUNT; i++)
    {
      if(i < on_leds)
        digitalWrite(bargraph_led[i], HIGH);
      else
        digitalWrite(bargraph_led[i], LOW);
    }
  }
}

