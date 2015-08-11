//Pin Configurations
int input_pin = A0;                          //module input
const int LED_COUNT = 4;                     //number of LEDs
int bargraph_led[LED_COUNT] = {2, 3, 4, 5};  //LED pin numbers

void setup() {
  //Just for debugging:
  //Serial.begin(9600);
  
  //initialize all LEDs as OUTPUT:
  for(int i = 0; i < LED_COUNT; i++)
    pinMode(bargraph_led[i], OUTPUT);
}

void loop() {
  int input_value = analogRead(input_pin);
  
  //We are only mapping 0-1023 from ADC to 0-255
  int on_leds = map(input_value, 0, 1023, 0, LED_COUNT);
  
  //Just for debugging:
  //Serial.print(on_leds);
  //Serial.print("--");
  //Serial.println(input_value);
  
  for(int i = 0; i < LED_COUNT; i++)
  {
    if(i < on_leds)
      digitalWrite(bargraph_led[i], HIGH);
    else
      digitalWrite(bargraph_led[i], LOW);
  }
}
