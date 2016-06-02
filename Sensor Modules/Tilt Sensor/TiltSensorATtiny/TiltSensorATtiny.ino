/*
**  TiltSensorATtiny.ino
**  MakerWear Tilt Sensor Module's ATtiny Program.
**
**  Changes voltage output (GND or PWR) based it on the sensor's tilt status.
**  If the module is tilted, it would send PWR otherwise, 0 Volts.
**
**  ATtiny Pin Configurations:  
**
**  Pin 1 (Reset): N/U                   Pin 8 (PWR):         5V
**  Pin 2 (D3/A3): Module Input          Pin 7 (D2/A1/SCK):   N/U
**  Pin 3 (D4/A2): N/U                   Pin 6 (D1/PWM/MISO): Module Output
**  Pin 4 (GND):   GND                   Pin 5 (D0/PWM/MOSI): Tilt Sensor
**
**
**  Created on 8/10/15.
**  By Majeed Kazemitabaar
**  Modified on 10/26/15
**  By Majeed Kazemitabaar
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <FilteredAnalogInput.h>

int input_pin = 3;
int tilt_sensor = 0;
int output_pin = 1;
int filter_size = 5;                        //Noise reduction filter size

// these variables will change:
int sensorReading;      // variable to store the value read from the sensor pin
int ledState = LOW;       // variable used to store the last LED status, to toggle the light
int tiltState;            // the current reading from the input pin
int lastTiltState = HIGH; // the previous reading from the input pin

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

FilteredAnalogInput input(input_pin, filter_size);

int input_val;

void setup() {
  pinMode(tilt_sensor, INPUT);
  pinMode(output_pin, OUTPUT);
}

void loop() {
  for(int i = 0; i < 5; i++)
    input_val = map(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);

  if(input_val < 0)
    input_val = 0;
  else if(input_val > 1023)
    input_val = 1023;

  if(ledState == HIGH)
    analogWrite(output_pin, input_val/4);
  else if(ledState == LOW)
    analogWrite(output_pin, 0);
    
  sensorReading = digitalRead(tilt_sensor);
  
  if (sensorReading != lastTiltState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    
    // if the button state has changed:
    if (sensorReading != tiltState)
    {
      tiltState = sensorReading;
      
      // if the sensor reading is low
      if (sensorReading == LOW) {
        // make the status of the output_pin to go on:
        ledState = HIGH;   
        analogWrite(output_pin, input_val/4);
          
        // dalay the LED on for one second:
        delay(500);
      }
      // otherwise if it is high
      else if (sensorReading == HIGH){
        // make the status of the output_pin to stay off:
        ledState = LOW;
        analogWrite(output_pin, 0);
      }
    }
   }
   
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastTiltState = sensorReading; 
  
  // delay to avoid overloading the serial port buffer:
  delay(100);
}                                                                                                                                                                                                                                                                                            
