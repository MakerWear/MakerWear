/*
**  MultiColorLightATtiny.ino
**  MakerWear MultiColorLight Module's ATtiny Program.
**
**  Maps 0-5V to all different colors on the RGB (so only needs one input) with
**  cold colors for low values and hot colors for high values. So if connected
**  to a Temperature sensor, it would have some meaningful colors.
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   RGB-LED(B) + 100Ω
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): RGB-LED(G) + 680Ω
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): RGB-LED(R) + 100Ω
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Last modified and tested on 6/21/16.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SignalProcessing.h>

int input_pin = 3;                             //pin 2 on ATtiny
int red_pin = 0, green_pin = 1, blue_pin = 2;  //pin {5, 6, 7} on ATtiny
int filter_size = 25;                          //noise reduction filter size

SignalProcessing input(input_pin, filter_size);

void setup() 
{  
  //initialize the RGB-LED pins as OUTPUT:
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

int state = 0;
int threshold = 10;
  
void loop() {
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
    
  int red = LOW, green = LOW, blue = LOW;
  
  //We are only mapping 0-1023 from ADC to 0-255
  
  //int input_val = analogRead(input_pin);
  
  if(state == 0 && input_val > 128 + threshold)
    state = 1;
  else if(state == 1 && input_val < 128 - threshold)
    state = 0;
  else if(state == 1 && input_val > 256 + threshold)
    state = 2;
  else if(state == 2 && input_val < 256 - threshold)
    state = 1;
  else if(state == 2 && input_val > 384 + threshold)
    state = 3;
  else if(state == 3 && input_val < 384 - threshold)
    state = 2;
  else if(state == 3 && input_val > 512 + threshold)
    state = 4;
  else if(state == 4 && input_val < 512 - threshold)
    state = 3;
  else if(state == 4 && input_val > 640 + threshold)
    state = 5;
  else if(state == 5 && input_val < 640 - threshold)
    state = 4;
  else if(state == 5 && input_val > 768 + threshold)
    state = 6;
  else if(state == 6 && input_val < 768 - threshold)
    state = 5;
  else if(state == 6 && input_val > 896 + threshold)
    state = 7;
  else if(state == 7 && input_val < 896 - threshold)
    state = 6;
  
  switch(state)
  {
    case 0://black
      red = LOW, green = LOW, blue = LOW;
    break;
    
    case 1://blue
      red = LOW, green = LOW, blue = HIGH;
    break;
    
    case 2://cyan
      red = LOW, green = HIGH, blue = HIGH;
    break;
    
    case 3://green
      red = LOW, green = HIGH, blue = LOW;
    break;
    
    case 4://yellow
      red = HIGH, green = HIGH, blue = LOW;
    break;
    
    case 5://red
      red = HIGH, green = LOW, blue = LOW;
    break;
    
    case 6://magenta
      red = HIGH, green = LOW, blue = HIGH;
    break;
    
    case 7://white
      red = HIGH, green = HIGH, blue = HIGH;
    break;    
  }
    
  digitalWrite(red_pin, red);
  digitalWrite(green_pin, green);
  digitalWrite(blue_pin, blue);
}
