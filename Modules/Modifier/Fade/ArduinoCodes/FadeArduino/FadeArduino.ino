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

int input_pin = A0;
int potentiometer_pin = A1;
int output_pin = 11;
int filter_size = 15;                        //Noise reduction filter size
int on_trigger = 0;
int fading = 0;
int brightness = 0;
int on_threshold = 10;                       //from 1023
int temp = 0;                                //if 1, currently fading. if 0 not fading

SignalProcessing input(input_pin, filter_size);

void setup() 
{ 
  pinMode(output_pin, OUTPUT);
  //Just For Debugging:
  //Serial.begin(9600);
}

void loop() {
  int pot_value = analogRead(potentiometer_pin);
  int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
  int fading_delay = map(pot_value, 0, 1023, 0, 50000/input_val);           //50000 experimentally determined
  
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
    
  if(on_trigger == 1 && fading == 0)
  {
    fading = 1;
    brightness = input_val;
  }
  else if(on_trigger == 1 && fading == 1 && brightness > upper_threshold && temp == 0){
    brightness = input_val;
    temp = 1;
  }
  else if(on_trigger == 1 && fading == 1 && brightness < upper_threshold && temp == 0)
    brightness += add_value;
  else if(on_trigger == 1 && fading == 1 && brightness >= 1 && temp == 1)
    brightness--;
  else if(on_trigger == 1 && fading == 1 && brightness < 1)
  {
    on_trigger = 0;
    brightness = 0;
    fading = 0;
    temp = 0;
    delay(fading_delay);
  }
  
  /*
  Serial.print("trig: ");  
  Serial.print(on_trigger);
  Serial.print(" fade: ");
  Serial.print(fading);
  Serial.print(" bright:");
  Serial.print(brightness);
  Serial.print(" up_thr: ");
  Serial.print(upper_threshold);
  Serial.print(" add_v: ");
  Serial.print(add_value);
  Serial.print(" inp_v: ");
  Serial.print(input_val);
  Serial.print(" delay: ");
  Serial.print(fading_delay);
  Serial.print(" pot: ");
  Serial.println(pot_value);
  */
  
  analogWrite(output_pin, brightness);
  
  delay(fading_delay);
  //delay(10);
}
