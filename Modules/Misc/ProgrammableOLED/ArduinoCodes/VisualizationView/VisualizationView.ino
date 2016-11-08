/*
**  ModuleNameATmega.ino
**  MakerWear ModuleName Module's ATmega Program.
**
**  Description
**  Description
**  Description
**
**
**  ATmega328 Pin Configurations:
**
**  Pin 1  (Reset):                          Pin 28  (A5):  
**  Pin 2  (D0/RX):                          Pin 27  (A4):
**  Pin 3  (D1/TX):                          Pin 26  (A3):
**  Pin 4  (D2):                             Pin 25  (A2):
**  Pin 5  (D3/PWM):                         Pin 24  (A1):
**  Pin 6  (D4):                             Pin 23  (A0):       Module Input
**  Pin 7  (PWR):                            Pin 22  (GND):
**  Pin 8  (GND):                            Pin 21  (AREF):
**  Pin 9  (XTAL1):                          Pin 20  (AVCC):
**  Pin 10 (XTAL2):                          Pin 19  (D13):
**  Pin 11 (D5/PWM):                         Pin 18  (D12):
**  Pin 12 (D6/PWM):                         Pin 17  (D11/PWM):
**  Pin 13 (D7):                             Pin 16  (D10/PWM):
**  Pin 14 (D8):                             Pin 15  (D9/PWM):
**
**
**  Created on xx/yy/zz.
**  By Akbar Akbari
**  Modified on xx/yy/zz.
**  By Asghar Asghari
**
**  MakerWear Link:
**  Github Link:      github.com/myjeeed/MakerWear
**
*/

#include <SPI.h>  // Include SPI if you're using SPI
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library
#include <SignalProcessing.h>

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET 9  // Connect RST to pin 9
#define PIN_DC    8  // Connect DC to pin 8
#define PIN_CS    10 // Connect CS to pin 10
#define DC_JUMPER 0

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
MicroOLED oled(PIN_RESET, PIN_DC, PIN_CS); // SPI declaration

const int input_pin = A0;       // pin 23 on ATmega328
const int filter_size = 10;     // Noise reduction filter size                        

SignalProcessing input(input_pin, filter_size);

void setup()
{
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.clear(PAGE); // Clear the buffer.
  
  oled.setFontType(0);  // Set font to type 0
}

void loop()
{
    int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 900, 0, 1023);

    //print input value:
    //works perfectly fine!
//    oled.clear(PAGE);
//    oled.setCursor(0, 0);
//    oled.print("A0: ");
//    oled.print(input_val);
//    oled.display();
//    delay(50);

      //move circle with input:
      oled.clear(PAGE);
      int ball_x = oled.getLCDWidth()/2;
      int ball_y = map(input_val, 0, 1023, 0, oled.getLCDHeight());
      
      oled.circle(ball_x, ball_y, 3);
      oled.display();
      delay(5);     
}
