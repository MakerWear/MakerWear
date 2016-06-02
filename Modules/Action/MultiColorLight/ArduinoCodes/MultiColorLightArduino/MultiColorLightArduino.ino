/*
**  MultiColorLightArduino.ino
**  MakerWear MultiColorLight Module's Arduino Program.
**
**  Maps 0-5V to all different colors on the RGB (so only needs one input) with
**  cold colors for low values and hot colors for high values. So if connected
**  to a Temperature sensor, it would have some meaningful colors.
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 3: RGB-LED(R) + 100Ω
**  Arduino Pin 4: RGB-LED(G) + 680Ω
**  Arduino Pin 5: RGB-LED(B) + 100Ω
**  Arduino Pin A0: Module Input
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 8/25/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

int input_pin = A0;                            //module input
int red_pin = 3, green_pin = 4, blue_pin = 5;  //led pins
int filter_size = 15;                          //noise reduction filter size

FilteredAnalogInput input(input_pin, filter_size);

void setup() {
  //Just for debugging:
  //Serial.begin(9600);
  
  //initialize LED pins as OUTPUT:
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

void loop() {
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
  
  //We are only mapping 0-1023 from ADC to 0-255
  int color_code = map(input_val, 0, 1023, 0, 7);
    
  int red = LOW, green = LOW, blue = LOW;
  
  switch(color_code)
  {
    case 0:
      red = LOW, green = LOW, blue = LOW;
    break;
    
    case 1:
      red = LOW, green = LOW, blue = HIGH;
    break;
    
    case 2:
      red = LOW, green = HIGH, blue = HIGH;
    break;
    
    case 3:
      red = LOW, green = HIGH, blue = LOW;
    break;
    
    case 4:
      red = HIGH, green = HIGH, blue = LOW;
    break;
    
    case 5:
      red = HIGH, green = LOW, blue = LOW;
    break;
    
    case 6:
      red = HIGH, green = LOW, blue = HIGH;
    break;
    
    case 7:
      red = HIGH, green = HIGH, blue = HIGH;
    break;
  }
  
  digitalWrite(red_pin, red);
  digitalWrite(green_pin, green);
  digitalWrite(blue_pin, blue);
  
  //Just for debugging:
  //Serial.print(red); Serial.print("-" + green); Serial.print("-" + blue);
  //Serial.println();
}
