//TODO: Add resistor values in the code

//Pin Configurations
int input_pin = 3;           //Pin 2 on ATtiny
int ir_receiver_pin = 2;   //Pin 3 on ATtiny
int output_pin = 1;          //Pin 6 on ATtiny


void setup() {
}

void loop() {
  int ir_value = analogRead(ir_receiver_pin);
  float metric_value = 0.000003 * pow(ir_value, 3) - 0.0007 * pow(ir_value, 2)
            + 0.1079 * ir_value + 8.2076;
  
  int input_value = analogRead(input_pin);
  
  int out_value = map(metric_value, 7, 41, input_value/4, 0);

  if (out_value < 9)
    out_value = 0;
  
  analogWrite(output_pin, out_value);
}
