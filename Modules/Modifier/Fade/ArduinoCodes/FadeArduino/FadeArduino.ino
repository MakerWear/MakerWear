/*
**  FadeArduino.ino
**  MakerWear Fade Module's Arduino Program.
**
**  After receiving an input (say above >3V), outputs a fading 5V to 0V signal
**  for a settable time (based on knob)
**
**
**  Arduino Pin Configurations:  
**
**  Arduino Pin 11: Module Output
**  Arduino Pin A0: Module Input
**  Arduino Pin A1: Potentiometer
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

int input_pin = A0;
int potentiometer_pin = A1;
int output_pin = 11;

int filter_size = 15;                        //Noise reduction filter size

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
  //Just For Debugging:
  //Serial.begin(9600);
}

void loop() {
  int pot_value;
  int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 4, 1023);

  if(input_val > THRESH_HIGH){
    can_fade = 1;
  }
  else{
    can_fade = 0;
    low_detect = 1;
  }
  
  input_val /= 4;
  
  int add_value = (int)(0.25 * (float)(input_val));
    
  if(can_fade == 1 && low_detect == 1 && fading == 0){     //&& temp = 0 && brightness > upper_threshold
    fading = 1;
    brightness = input_val;
    pot_value = analogRead(potentiometer_pin);
    fading_delay = cutAndMap(pot_value, 0, 1023, 0, 10000/input_val);           //50000 experimentally determined
  }
  else if(can_fade == 1 && add_trigger == 1 && fading == 1){
    brightness += add_value;
    add_trigger = 0;
  }
  else if(fading == 1 && brightness >= 1){               //&& temp = 1
    if(can_fade == 0){
      add_trigger = 1;
    }
    brightness--;
  }
  else if(fading == 1 && brightness < 1)
  {
    add_trigger = 0;
    low_detect = 0;
    brightness = 0;
    fading = 0;
    delay(fading_delay);
  }
  
 /* 
  Serial.print("trig: ");  
  Serial.print(add_trigger);
  Serial.print(" fade: ");
  Serial.print(fading);
  Serial.print(" temp: ");
  Serial.print(temp);
  Serial.print(" bright:");
  Serial.print(brightness);
  Serial.print(" up_thr: ");
  Serial.print(upper_threshold);
  //Serial.print(" add_v: ");
  //Serial.print(add_value);
  Serial.print(" inp_v: ");
  Serial.print(input_val);
  Serial.print(" delay: ");
  Serial.print(fading_delay);
  Serial.print(" pot: ");
  Serial.print(pot_value);
  */
  
  analogWrite(output_pin, brightness);
  delay(fading_delay);
  //delay(10);
}
