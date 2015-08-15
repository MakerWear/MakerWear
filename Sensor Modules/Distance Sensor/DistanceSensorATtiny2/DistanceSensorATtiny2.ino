//Pin Configurations:
int input_pin = 3;
int output_pin = 1;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int input_value = analogRead(input_pin);
  int output_value = map(input_value, 400, 1000, 255, 0);
  
  if(input_value < 450)
    output_value = 255;
  else if(input_value > 950)
    output_value = 0;
  /*
  Serial.print("IN: ");
  Serial.print(input_value);
  Serial.print("  OUT: ");
  Serial.println(output_value);
  */
  
  analogWrite(output_pin, output_value); 
}
