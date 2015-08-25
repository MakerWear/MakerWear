/**************************************************************************/
/*!
    @file     ATtinyColorSensor.cpp
    @author   KTOWN (Adafruit Industries)
    @author   Modified by Majeed Kazemitabaar (University of Maryland)
    @license  BSD (see license.txt)

    Driver for the TCS34725 digital color sensors.

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section  HISTORY

    v1.0 - First release
*/
/**************************************************************************/
#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include <math.h>

#include "ATtinyColorSensor.h"

/*========================================================================*/
/*                          PRIVATE FUNCTIONS                             */
/*========================================================================*/

/**************************************************************************/
/*!
    @brief  Implements missing powf function
*/
/**************************************************************************/
float powf(const float x, const float y)
{
  return (float)(pow((double)x, (double)y));
}

/**************************************************************************/
/*!
    @brief  Writes a register and an 8 bit value over I2C
*/
/**************************************************************************/
void ATtinyColorSensor::write8 (uint8_t reg, uint32_t value)
{
  TinyWireM.beginTransmission(TCS34725_ADDRESS);

  TinyWireM.send(TCS34725_COMMAND_BIT | reg);
  TinyWireM.send(value & 0xFF);

  TinyWireM.endTransmission();
}

/**************************************************************************/
/*!
    @brief  Reads an 8 bit value over I2C
*/
/**************************************************************************/
uint8_t ATtinyColorSensor::read8(uint8_t reg)
{
  TinyWireM.beginTransmission(TCS34725_ADDRESS);
  TinyWireM.send(TCS34725_COMMAND_BIT | reg);
  TinyWireM.endTransmission();
  TinyWireM.requestFrom(TCS34725_ADDRESS, 1);

  return TinyWireM.receive();
}

/**************************************************************************/
/*!
    @brief  Reads a 16 bit values over I2C
*/
/**************************************************************************/
uint16_t ATtinyColorSensor::read16(uint8_t reg)
{
  uint16_t x; uint16_t t;

  TinyWireM.beginTransmission(TCS34725_ADDRESS);
  TinyWireM.send(TCS34725_COMMAND_BIT | reg);
  TinyWireM.endTransmission();
  TinyWireM.requestFrom(TCS34725_ADDRESS, 2);

  t = TinyWireM.receive();
  x = TinyWireM.receive();

  x <<= 8;
  x |= t;

  return x;
}

/**************************************************************************/
/*!
    Enables the device
*/
/**************************************************************************/
void ATtinyColorSensor::enable(void)
{
  write8(TCS34725_ENABLE, TCS34725_ENABLE_PON);
  delay(3);
  write8(TCS34725_ENABLE, TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN);
}

/**************************************************************************/
/*!
    Disables the device (putting it in lower power sleep mode)
*/
/**************************************************************************/
void ATtinyColorSensor::disable(void)
{
  /* Turn the device off to save power */
  uint8_t reg = 0;
  reg = read8(TCS34725_ENABLE);
  write8(TCS34725_ENABLE, reg & ~(TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN));
}

/*========================================================================*/
/*                            CONSTRUCTORS                                */
/*========================================================================*/

/**************************************************************************/
/*!
    Constructor
*/
/**************************************************************************/
ATtinyColorSensor::ATtinyColorSensor(tcs34725IntegrationTime_t it, tcs34725Gain_t gain)
{
  _tcs34725Initialised = false;
  _tcs34725IntegrationTime = it;
  _tcs34725Gain = gain;
}

/*========================================================================*/
/*                           PUBLIC FUNCTIONS                             */
/*========================================================================*/

/**************************************************************************/
/*!
    Initializes I2C and configures the sensor (call this function before
    doing anything else)
*/
/**************************************************************************/
bool ATtinyColorSensor::begin(void)
{
  TinyWireM.begin();

  /* Make sure we're actually connected */
  uint8_t x = read8(TCS34725_ID);

  if ((x != 0x44) && (x != 0x10))
  {
    return false;
  }
  _tcs34725Initialised = true;

  //Turn on Pin2 on ATtiny85 when connected to the Color Sensor.
  digitalWrite(3, HIGH);

  /* Set default integration time and gain */
  setIntegrationTime(_tcs34725IntegrationTime);
  setGain(_tcs34725Gain);

  /* Note: by default, the device is in power down mode on bootup */
  enable();

  return true;
}


/**************************************************************************/
/*!
    Sets the integration time for the TC34725
*/
/**************************************************************************/
void ATtinyColorSensor::setIntegrationTime(tcs34725IntegrationTime_t it)
{
  if (!_tcs34725Initialised) begin();

  /* Update the timing register */
  write8(TCS34725_ATIME, it);

  /* Update value placeholders */
  _tcs34725IntegrationTime = it;
}

/**************************************************************************/
/*!
    Adjusts the gain on the TCS34725 (adjusts the sensitivity to light)
*/
/**************************************************************************/
void ATtinyColorSensor::setGain(tcs34725Gain_t gain)
{
  if (!_tcs34725Initialised) begin();

  /* Update the timing register */
  write8(TCS34725_CONTROL, gain);

  /* Update value placeholders */
  _tcs34725Gain = gain;
}

/**************************************************************************/
/*!
    @brief  Reads the raw red, green, blue and clear channel values
*/
/**************************************************************************/
void ATtinyColorSensor::getRawData (uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c)
{
  if (!_tcs34725Initialised) begin();

  *c = read16(TCS34725_CDATAL);
  *r = read16(TCS34725_RDATAL);
  *g = read16(TCS34725_GDATAL);
  *b = read16(TCS34725_BDATAL);

  /* Set a delay for the integration time */
  switch (_tcs34725IntegrationTime)
  {
    case TCS34725_INTEGRATIONTIME_2_4MS:
      delay(3);
      break;
    case TCS34725_INTEGRATIONTIME_24MS:
      delay(24);
      break;
    case TCS34725_INTEGRATIONTIME_50MS:
      delay(50);
      break;
    case TCS34725_INTEGRATIONTIME_101MS:
      delay(101);
      break;
    case TCS34725_INTEGRATIONTIME_154MS:
      delay(154);
      break;
    case TCS34725_INTEGRATIONTIME_700MS:
      delay(700);
      break;
  }
}

/**************************************************************************/
/*!
    @brief  Converts the raw R/G/B values to color temperature in degrees
            Kelvin
*/
/**************************************************************************/
uint16_t ATtinyColorSensor::calculateColorTemperature(uint16_t r, uint16_t g, uint16_t b)
{
  float X, Y, Z;      /* RGB to XYZ correlation      */
  float xc, yc;       /* Chromaticity co-ordinates   */
  float n;            /* McCamy's formula            */
  float cct;

  /* 1. Map RGB values to their XYZ counterparts.    */
  /* Based on 6500K fluorescent, 3000K fluorescent   */
  /* and 60W incandescent values for a wide range.   */
  /* Note: Y = Illuminance or lux                    */
  X = (-0.14282F * r) + (1.54924F * g) + (-0.95641F * b);
  Y = (-0.32466F * r) + (1.57837F * g) + (-0.73191F * b);
  Z = (-0.68202F * r) + (0.77073F * g) + ( 0.56332F * b);

  /* 2. Calculate the chromaticity co-ordinates      */
  xc = (X) / (X + Y + Z);
  yc = (Y) / (X + Y + Z);

  /* 3. Use McCamy's formula to determine the CCT    */
  n = (xc - 0.3320F) / (0.1858F - yc);

  /* Calculate the final CCT */
  cct = (449.0F * powf(n, 3)) + (3525.0F * powf(n, 2)) + (6823.3F * n) + 5520.33F;

  /* Return the results in degrees Kelvin */
  return (uint16_t)cct;
}

/**************************************************************************/
/*!
    @brief  Converts the raw R/G/B values to color temperature in degrees
            Kelvin
*/
/**************************************************************************/
uint16_t ATtinyColorSensor::calculateLux(uint16_t r, uint16_t g, uint16_t b)
{
  float illuminance;

  /* This only uses RGB ... how can we integrate clear or calculate lux */
  /* based exclusively on clear since this might be more reliable?      */
  illuminance = (-0.32466F * r) + (1.57837F * g) + (-0.73191F * b);

  return (uint16_t)illuminance;
}


void ATtinyColorSensor::setInterrupt(bool i)
{
  uint8_t r = read8(TCS34725_ENABLE);

  if (i)
  {
    r |= TCS34725_ENABLE_AIEN;
  }
  else
  {
    r &= ~TCS34725_ENABLE_AIEN;
  }

  write8(TCS34725_ENABLE, r);
}


void ATtinyColorSensor::clearInterrupt(void)
{
  TinyWireM.beginTransmission(TCS34725_ADDRESS);
  TinyWireM.send(0x66);
  TinyWireM.endTransmission();
}


void ATtinyColorSensor::setIntLimits(uint16_t low, uint16_t high)
{
   write8(0x04, low & 0xFF);
   write8(0x05, low >> 8);
   write8(0x06, high & 0xFF);
   write8(0x07, high >> 8);
}
