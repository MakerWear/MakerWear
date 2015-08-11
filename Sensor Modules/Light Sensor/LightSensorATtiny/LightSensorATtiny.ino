//Pin Configurations
int input_pin = 3;           //Pin 2 on ATtiny
int photoresistor_pin = 2;   //Pin 3 on ATtiny
int output_pin = 1;          //Pin 6 on ATtiny

void setup() {
}

void loop() {
  int photoresistor_value = analogRead(photoresistor_pin);
  int input_value = analogRead(input_pin);
  
  //We are only mapping 0-1023 from ADC to 0-255
  int output_value = map(photoresistor_value, 0, 1023, input_value/4, 0);
  
  analogWrite(output_pin, output_value);
}
