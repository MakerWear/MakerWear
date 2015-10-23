int input_pin = A1;           //module input
int vibro_sensor_pin = 13;    //photo-resistor's voltage divider output
int output_pin = 6;           //module output

void setup() {
  //Just for debugging:
  //Serial.begin(9600);
  pinMode(13, INPUT);
}

void loop() {
  int sensor_value = digitalRead(vibro_sensor_pin);

  if(sensor_value == LOW)
  {
    analogWrite(output_pin, analogRead(input_pin)/4);
    delay(100);
    analogWrite(output_pin, 0);
  }
}
  
