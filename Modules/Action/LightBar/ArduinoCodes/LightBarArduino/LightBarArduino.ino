/*
**  LightBarATtiny.ino
**  MakerWear LightBar Module's Arduino Program.
**
**  Lights up the LEDS proportional to voltage input.
**  Could be used for all sorts of things from serving as a visualization
**  for how loud sound is currently to how much the person is moving to
**  simply helping a child debug their MakerWear design.
**
**
**  Pin Configurations:  
**
**  Arduino Pin 2: LED1
**  Arduino Pin 3: LED2
**  Arduino Pin 4: LED3
**  Arduino Pin 5: LED4
**  Arduino Pin A0: Module Input
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 8/24/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

//Pin Configurations
int input_pin = A0;                            //module input
const int LED_COUNT = 4;                       //number of LEDs
int filter_size = 15;                          //noise reduction filter size
int bargraph_led[LED_COUNT] = {2, 3, 4, 5};    //LED pin numbers

FilteredAnalogInput input(input_pin, filter_size);

void setup() {
  //Just for debugging:
  //Serial.begin(9600);
  
  //initialize all LEDs as OUTPUT:
  for(int i = 0; i < LED_COUNT; i++)
    pinMode(bargraph_led[i], OUTPUT);
}

void loop() {
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
