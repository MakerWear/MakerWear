//Pin Configurations
//int input_pin = 3;           //Pin 2 on ATtiny
int ir_receiver_pin = 2;   //Pin 3 on ATtiny
int output_pin = 1;          //Pin 6 on ATtiny


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
}

void loop() {
  int x = analogRead(ir_receiver_pin);
  float y = .000003*x*x*x - 0.0007*x*x + 0.1079*x + 8.2076;
  int out_value = map(y, 7, 41, 255, 0);

  if (out_value < 9)
    out_value = 0;
  
  analogWrite(output_pin, out_value);
  //Serial.println(out_value);
}
