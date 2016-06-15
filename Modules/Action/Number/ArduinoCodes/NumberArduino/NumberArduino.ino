/* Pin delcarations for segments A through G */
int display[7] = {2,3,4,5,6,7,8};

/* Input from other module */
int input = A0;

/* segment patterns to display 0 - 9 */
const bool digit_patterns[10][7] = {
  {1,1,1,1,1,1,0},  // 0 
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6 
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
}; 

void setup() {
  // initialize digital pin 13 as an output.
  for (int i = 0; i < 7; i++) {
    pinMode(display[i], OUTPUT);
  }
  pinMode(input, INPUT);
  Serial.begin(9600);
}


unsigned int number = 0;
unsigned int value = 0;
// the loop function runs over and over again forever
void loop() {
  value = analogRead(input);
  number = (value*10/1024);
  Serial.print(value);
  Serial.print(" ");
  Serial.println(number);
 
  write_digit(number);
}

void write_digit(int digit) {
  write_pattern(digit_patterns[digit]);
}

void write_pattern(const bool* segments) {
  for (int i = 0; i < 7; i++) {
    if (segments[i] == true) {
      digitalWrite(display[i], HIGH);
    } else {
      digitalWrite(display[i], LOW);
    }
  }
}

