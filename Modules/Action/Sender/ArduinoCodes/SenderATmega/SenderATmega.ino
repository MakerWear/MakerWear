
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
//TODO: this needs to be fixed!
int filter_size = 7;                        //Noise reduction filter size                        
//Library automatically uses D3 to send signal

SignalProcessing input(input_pin, filter_size);

IRsend irsend;

void setup()
{
  //Serial.begin(9600);
}

int state = 0;
int prev_state = 0;
int threshold = 15;
int code = 0;

void loop()
{
   int input_val = cutAndMap(input.filteredAnalogRead(AVERAGE), 50, 975, 0, 1023);
   
  if(state == 0 && input_val > 128 + threshold)
    state = 1;
  else if(state == 1 && input_val < 128 - threshold)
    state = 0;
  else if(state == 1 && input_val > 256 + threshold)
    state = 2;
  else if(state == 2 && input_val < 256 - threshold)
    state = 1;
  else if(state == 2 && input_val > 384 + threshold)
    state = 3;
  else if(state == 3 && input_val < 384 - threshold)
    state = 2;
  else if(state == 3 && input_val > 512 + threshold)
    state = 4;
  else if(state == 4 && input_val < 512 - threshold)
    state = 3;
  else if(state == 4 && input_val > 640 + threshold)
    state = 5;
  else if(state == 5 && input_val < 640 - threshold)
    state = 4;
  else if(state == 5 && input_val > 768 + threshold)
    state = 6;
  else if(state == 6 && input_val < 768 - threshold)
    state = 5;
  else if(state == 6 && input_val > 896 + threshold)
    state = 7;
  else if(state == 7 && input_val < 896 - threshold)
    state = 6;
  
  switch(state)
  {
    case 0:
      code = 0x111;
    break;
    
    case 1:
      code = 0x222;
    break;
    
    case 2:
      code = 0x444;
    break;
    
    case 3:
      code = 0x666;
    break;
    
    case 4:
      code = 0x888;
    break;
    
    case 5:
      code = 0xAAA;
    break;
    
    case 6:
      code = 0xCCC;
    break;
    
    case 7:
      code = 0xEEE;
    break;    
  }
//
//  if(prev_state != state)
//  {
//    prev_state = state;
//    
//  }

  sendIR(code);
}

void sendIR(unsigned int hex){
    const int nbits = 12;
    
    for(int i = 0; i < 3; i++)
    {
      irsend.sendSony(hex,nbits);
      delay(40);
    }
}
