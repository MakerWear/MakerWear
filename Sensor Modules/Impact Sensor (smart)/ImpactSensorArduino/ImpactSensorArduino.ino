//int input_pin = A1;         //module input
int vibro_sensor_pin = 13;    //photo-resistor's voltage divider output
int output_pin = 6;        //module output

//values:
int fading = 0;
int brightness = 0;

void setup() {
  //Just for debugging:
  //Serial.begin(9600);
  pinMode(13, INPUT);
}

void loop() {
  int sensor_value = digitalRead(vibro_sensor_pin);
  
  if(sensor_value == 0 && fading == 0)
  {
    brightness = 255;
    fading = 1;
  }
  else if(sensor_value == 0 && fading == 1 && brightness < 200)
    brightness += 50;
  else if(sensor_value == 0 && fading == 1 && brightness > 200)
    brightness = 255;
  else if(sensor_value == 1 && fading == 1 && brightness > 1)
    brightness--;
  else if(sensor_value == 1 && fading == 1 && brightness <= 1)
  {
    brightness = 0;
    fading = 0;
  }
  //Serial.println(sensor_value);
  analogWrite(output_pin, brightness);
  delay(10);
}
  
