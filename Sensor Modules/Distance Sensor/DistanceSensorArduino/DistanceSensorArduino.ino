//int input_pin = null;      //won't be using right now.
int output_pin = 11;
int ir_receiver_pin = A0;


void setup() {
  //Just for debugging:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(ir_receiver_pin);
  float y = 0.000004*x*x*x - 0.0013*x*x + 0.1567*x + 7.9254;
  int out_value = map(y, 7.5, 30, 255, 0);

  if(x>250)
    out_value = 0;

  analogWrite(output_pin, out_value);
  Serial.print(x); Serial.print("---");
  Serial.print(y); Serial.print("---");
  Serial.println(out_value);
}
