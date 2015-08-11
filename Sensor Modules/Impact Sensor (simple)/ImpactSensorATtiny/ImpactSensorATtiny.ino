//Pin Configurations:
int input_pin = 3;             //Pin 2 on ATtiny
int vibro_sensor_pin = 0;      //Pin 5 on ATtiny
int output_pin = 1;            //Pin 6 on ATtiny

void setup() {
  //Initialization:
  pinMode(vibro_sensor_pin, INPUT);
  digitalWrite(vibro_sensor_pin, HIGH);
  
  pinMode(output_pin, OUTPUT);
  analogWrite(output_pin, 0);
}

void loop() {
  
  if(digitalRead(vibro_sensor_pin) == LOW)
  {
    //whenever the vibration sensor is hit
    //the output pin would be as high as the input pin for 100ms and then 0 again.
    analogWrite(output_pin, analogRead(input_pin)/4);
    delay(100);
    analogWrite(output_pin, 0);
  }
}
