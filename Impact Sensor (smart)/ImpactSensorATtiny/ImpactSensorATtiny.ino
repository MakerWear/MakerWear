//Pin Configurations
int input_pin = 3;           //Pin 2 on ATtiny
int vibro_sensor_pin = 0;      //Pin 5 on ATtiny
int output_pin = 1;            //Pin 6 on ATtiny

//values:
int fading = 0;
int brightness = 0;

void setup() {
  pinMode(vibro_sensor_pin, INPUT);
  digitalWrite(vibro_sensor_pin, HIGH); //enable internal pull-up resistor
}

void loop() {
  int sensor_value = digitalRead(vibro_sensor_pin);
  int input_value = analogRead(input_pin)/4;
  
  if(sensor_value == 0 && fading == 0)
  {
    brightness = input_value;
    fading = 1;
  }
  else if(sensor_value == 0 && fading == 1 && brightness < input_value*0.75)//200)
    brightness += input_value*0.25;//50;
  else if(sensor_value == 0 && fading == 1 && brightness > input_value*0.75)//200)
    brightness = input_value;//255;
  else if(sensor_value == 1 && fading == 1 && brightness > 1)
    brightness--;
  else if(sensor_value == 1 && fading == 1 && brightness <= 1)
  {
    brightness = 0;
    fading = 0;
  }

  analogWrite(output_pin, brightness);
  delay(10);
}
  
