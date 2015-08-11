//Resistor Configurations
//red: 100 ohms
//green: 680 ohms
//blue: 100 ohms

//Pin Configurations
int input_pin = 3; //pin 2 on ATtiny
int red_pin = 0, green_pin = 1, blue_pin = 2;  //pin {5, 6, 7} on ATtiny

void setup() {  
  //initialize LED pins as OUTPUT:
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

void loop() {
  int input_value = analogRead(input_pin);
  
  //We are only mapping 0-1023 from ADC to 0-255
  int color_code = map(input_value, 0, 1023, 0, 7);
    
  int red = LOW, green = LOW, blue = LOW;
  
  switch(color_code)
  {
    case 0:
      red = LOW, green = LOW, blue = LOW;
    break;
    
    case 1:
      red = LOW, green = LOW, blue = HIGH;
    break;
    
    case 2:
      red = LOW, green = HIGH, blue = HIGH;
    break;
    
    case 3:
      red = LOW, green = HIGH, blue = LOW;
    break;
    
    case 4:
      red = HIGH, green = HIGH, blue = LOW;
    break;
    
    case 5:
      red = HIGH, green = LOW, blue = LOW;
    break;
    
    case 6:
      red = HIGH, green = LOW, blue = HIGH;
    break;
    
    case 7:
      red = HIGH, green = HIGH, blue = HIGH;
    break;
  }
  
  digitalWrite(red_pin, red);
  digitalWrite(green_pin, green);
  digitalWrite(blue_pin, blue);
}
