//Pin Configurations
int input_pin = 3;                           //module input, pin 2 on ATtiny
const int LED_COUNT = 4;                     //number of LEDs
int bargraph_led[LED_COUNT] = {4, 0, 1, 2};  //LED pin numbers pin {3, 5, 6, 7} on ATtiny


void setup() {
  //initialize all LEDs as OUTPUT:
  for(int i = 0; i < LED_COUNT; i++)
    pinMode(bargraph_led[i], OUTPUT);
}

void loop() {
  int input_value = analogRead(input_pin);
  
  //We are only mapping 0-1023 from ADC to 0-255
  int on_leds = map(input_value, 0, 1023, 0, LED_COUNT);
  
  for(int i = 0; i < LED_COUNT; i++)
  {
    if(i < on_leds)
      digitalWrite(bargraph_led[i], HIGH);
    else
      digitalWrite(bargraph_led[i], LOW);
  }
}
