/*
**  FadeATtiny.ino
**  MakerWear Fade Module's ATtiny Program.
**
**  After receiving an input (say above >3V), outputs a fading 5V to 0V signal
**  for a settable time (based on knob)
**
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): Potentiometer         Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
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

int input_pin = 3;                           //Pin 2 on ATtiny
int potentiometer_pin = 2;                   //Pin 3 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny

int filter_size = 15;                        //Noise reduction filter size

int on_trigger = 0;
int fading = 0;                              //if it is in fading phase
int brightness = 0;
int on_threshold = 10;                       //from 1023

FilteredAnalogInput input(input_pin, filter_size);

void setup() 
{
  pinMode(output_pin, OUTPUT);
}

void loop() 
{
  int pot_value = analogRead(potentiometer_pin);
  int fading_delay = map(pot_value, 0, 1023, 4, 40);
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  
  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;
  
  if(input_val > on_threshold)
    on_trigger = 1;
  else
    on_trigger = 0;
  
  input_val /= 4;
  
  int upper_threshold = (int)(0.75 * (float)(input_val));
  int add_value = (int)(0.25 * (float)(input_val));
  
  if(fading == 0 && input_val > 25)
  {
    fading = 1;
    brightness = 255;
  }
  
  if(fading == 1)
  {
    brightness--;
    if(brightness == 0)
      fading = 0;
  }
  
  analogWrite(output_pin, brightness);
  
  delay(fading_delay);
  
    /*
  if(on_trigger == 1 && fading == 0)
  {
    //TODO: need to add debouncing here:
    fading = 1;
    brightness = input_val;
  }
  else if(on_trigger == 1 && fading == 1 && brightness > upper_threshold)
    brightness = input_val;
  //TODO: The next if statement is not working because of debouncing.
  else if(on_trigger == 1 && fading == 1 && brightness < upper_threshold)
    brightness += add_value;
  else if(on_trigger == 0 && fading == 1 && brightness >= 1)
    brightness--;
  else if(on_trigger == 0 && fading == 1 && brightness < 1)
  {
    brightness = 0;
    fading = 0;
  }
  */
}
