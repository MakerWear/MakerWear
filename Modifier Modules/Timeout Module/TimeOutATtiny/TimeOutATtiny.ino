/* 
** MakerWear Timeout Module
** 
** Written & Last Modified by Majeed Kazemitabaar
** Friday, August 11th, 2015
*/
 
//Pin Configurations:
int input_pin = 3;             //Pin 2 on ATtiny
int potentiometer_pin = 2;      //Pin 3 on ATtiny
int output_pin = 1;            //Pin 6 on ATtiny

//values
int on_trigger = 0;
int fading = 0;
int brightness = 0;

//Constants
int on_threshold = 10; //from 1023


void setup() {
  pinMode(output_pin, OUTPUT);
}

void loop() {
  int input_value = analogRead(input_pin)/4;
  int pot_value = analogRead(potentiometer_pin);
  int fading_delay = map(pot_value, 0, 1023, 2, 30);
  
  if(input_value > on_threshold)
    on_trigger = 1;
  else
    on_trigger = 0;
    
  int upper_threshold = (int)(0.75 * (float)(input_value));
  int add_value = (int)(0.25 * (float)(input_value));
    
  if(on_trigger == 1 && fading == 0)
  {
    //TODO: need to add debouncing here:
    fading = 1;
    brightness = input_value;
  }
  else if(on_trigger == 1 && fading == 1 && brightness > upper_threshold)
    brightness = input_value;
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
  
  analogWrite(output_pin, brightness);
  
  delay(fading_delay);
}
