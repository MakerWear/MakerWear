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

#include <SignalProcessing.h>

#define THRESH_LOW 300  //constants for when a signal is considered HIGH or LOW
#define THRESH_HIGH 700

int input_pin = 3;                           //Pin 2 on ATtiny
int potentiometer_pin = 2;                   //Pin 3 on ATtiny
int output_pin = 1;                          //Pin 6 on ATtiny

int filter_size = 5;                        //Noise reduction filter size

int add_trigger = 0;
int fading = 0;
short brightness = 0;
unsigned int fading_delay = 1;        //initialized at 1 
int can_fade = 0;                     //1 if module is allowed to start fading
int low_detect = 1;                   //1 if low signal has been found


SignalProcessing input(input_pin, filter_size);

void setup() 
{
  pinMode(output_pin, OUTPUT);
}

void loop() 
{
  int pot_value;
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 4, 1023);

  if(input_val > THRESH_HIGH){
    can_fade = 1;
  }
  else if(input_val < THRESH_LOW){
    can_fade = 0;
    low_detect = 1;
  }
  
  input_val /= 4;
  
  int add_value = (int)(0.25 * (float)(input_val));
    
  if(can_fade == 1 && low_detect == 1 && fading == 0){  //start fading   
    fading = 1;
    brightness = input_val;
    pot_value = analogRead(potentiometer_pin);
    fading_delay = cutAndMap(pot_value, 0, 1023, 0, 50000/(4*input_val));           //50000 experimentally determined
  }
  else if(can_fade == 1 && add_trigger == 1 && fading == 1){   //add brightness if HIGH input comes mid-fade
    brightness += add_value;
    add_trigger = 0;
  }
  else if(fading == 1 && brightness >= 1){  //fades           
    if(can_fade == 0){
      add_trigger = 1;
    }
    brightness--;
  }
  else if(fading == 1 && brightness < 1)    //end fade
  {
    add_trigger = 0;
    low_detect = 0;
    brightness = 0;
    fading = 0;
    delay(fading_delay);
  }
  
  analogWrite(output_pin, brightness);
  delay(fading_delay);
 
}
