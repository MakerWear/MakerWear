//Getting good values with a 4.7K resistor
//Between 900 (adc output) in room lighting and around 10-20 in total darkness
//Making a shade using your hand would also get it to around ~450


//Pin Configurations
int input_pin = A1;          //module input
int photoresistor_pin = A0;  //photo-resistor's voltage divider output
int output_pin = 11;         //module output

void setup() {
  //Just for debugging:
  //Serial.begin(9600);
}

void loop() {
  int photoresistor_value = analogRead(photoresistor_pin);
  int input_value = analogRead(input_pin);
  
  //We are only mapping 0-1023 from ADC to 0-255
  int output_value = map(photoresistor_value, 0, 1023, input_value/4, 0);
  
  //Just for debugging:
  //Serial.println(output_value);
  
  analogWrite(output_pin, output_value);
}
