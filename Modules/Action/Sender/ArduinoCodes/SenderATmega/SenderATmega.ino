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

#include <SignalProcessing.h>
#include <IRremote.h>

int input_pin = A0;                              //pin 23 on ATmega328
int filter_size = 25;                        //Noise reduction filter size                        
//Library automatically uses D3 to send signal

SignalProcessing input(input_pin, filter_size);

IRsend irsend;

void setup()
{
  //Serial.begin(9600);
}

void loop()
{
 int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
    
   if(input_val < 128)
    sendIR(0x111);
   else if(input_val > 128 && input_val <= 256)
    sendIR(0x222);
   else if(input_val > 256 && input_val <= 384)
    sendIR(0x444);
   else if(input_val > 384 && input_val <= 512)
    sendIR(0x666);
   else if(input_val > 512 && input_val <= 640)
    sendIR(0x888);
   else if(input_val > 640 && input_val <= 768)
    sendIR(0xAAA);
   else if(input_val > 768 && input_val <= 896)
    sendIR(0xCCC);
   else if(input_val > 896)
    sendIR(0xEEE);
}

void sendIR(unsigned int hex){
    const int nbits = 12;
    for(int i = 0; i<3; i++){
      irsend.sendSony(hex,nbits);
      delay(40);
    }
  
}
