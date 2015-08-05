//Pin Configurations
int input_pin = 3; //Pin 2 on ATtiny
int output_pin = 1; //Pin 6 on ATtiny

//Constants
int min_period = 25;
int max_period = 1000;

void setup() {
  pinMode(output_pin, OUTPUT);
  
  //Just For Debugging:
  //Serial.begin(9600);
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
