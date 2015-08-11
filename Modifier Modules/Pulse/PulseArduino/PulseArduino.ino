/* 
** MakerWear Pulse Module
** 
** Written & Last Modified by Majeed Kazemitabaar
** Friday, July 31th, 2015
*/
 
//Pin Configurations
int input_pin = A0;
int output_pin = 13;

//Constants
int min_period = 25;
int max_period = 1000;

void setup() {

  pinMode(output_pin, OUTPUT);
  
  //Just For Debugging:
  Serial.begin(9600);

}

void loop() {
  int input_value = analogRead(input_pin);
  int period = map(input_value, 0, 1023, max_period, min_period);
  
  digitalWrite(output_pin, HIGH);
  delay(period);
  period = map(input_value, 0, 1023, max_period, min_period);
  digitalWrite(output_pin, LOW);
  delay(period);
}

/*
** Changelog 
**
*/
