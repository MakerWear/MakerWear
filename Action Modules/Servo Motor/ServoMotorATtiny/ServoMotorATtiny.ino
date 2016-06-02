/*
**  ServoMotorATtiny.ino
**  MakerWear Servo Motor Module's ATtiny Program.
**
**  Rotate the LEGO-enabled shaft based on input voltage.
**
**  ATtiny85 Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Servo Motor Control Pin
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): N/U
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 8/25/15.
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>
#include <Adafruit_SoftServo.h>

Adafruit_SoftServo myservo;

int input_pin = 3;                             //pin 2 on ATtiny              
int filter_size = 30;                        //Noise reduction filter size
int servo_pin = 0;  

FilteredAnalogInput input(input_pin, filter_size);


void setup() 
{  
  OCR0A = 0xAF;            // any number is OK
  TIMSK |= _BV(OCIE0A);    // Turn on the compare interrupt (below!)

  myservo.attach(servo_pin);
  myservo.write(0);
  delay(1000);
}

void loop() 
{
    int input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
    if              (input_val < 0)
      input_val = 0;
    else if(input_val > 1023)
      input_val = 1023;
      
    int pos = map(input_val, 0, 1023, 0, 179);

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(250);                       // waits 15ms for the servo to reach the position 
}

volatile uint8_t counter = 0;
SIGNAL(TIMER0_COMPA_vect) {
  // this gets called every 2 milliseconds
  counter += 2;
  // every 20 milliseconds, refresh the servos!
  if (counter >= 20) {
    counter = 0;
    myservo.refresh();
  }
}

