/*
Resistor for reciever: 10M
Resistor ir sender: 10
*/

//Pin Configurations
int input_pin = A3;           //Pin 2 on ATtiny
int ir_receiver_pin = A0;   //Pin 3 on ATtiny
int knob_pin = 12;
int output_pin = 11;          //Pin 6 on ATtiny
int intervals = 10;            // controls intensity of change between loops
float distance, knob;

void setup() {
  Serial.begin(9600);
  pinMode(output_pin, OUTPUT);
  pinMode(ir_receiver_pin, INPUT);
  pinMode(input_pin, INPUT);
  pinMode(knob_pin, OUTPUT);
}

float process() {
  float x = analogRead(ir_receiver_pin);
  float y = 0.0008*x*x - 0.6421*x + 134.31;
  Serial.println(x);
  return y;
}

void loop() {
  
  distance = process();
  digitalWrite(knob_pin, HIGH);
    knob = analogRead(input_pin)/4;
  digitalWrite(knob_pin, LOW);

  int out_value = map(distance, 5, 22.5, knob, 0);
    
  if (out_value < 0) {
    out_value = 0;
  } else if (out_value > knob) {
    out_value = knob;   
  }
  
  analogWrite(output_pin, out_value);
}
