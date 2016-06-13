/***************************************************
  This is a library for the Si1145 UV/IR/Visible Light Sensor

  Designed specifically to work with the Si1145 sensor in the
  adafruit shop
  ----> https://www.adafruit.com/products/1777

  These sensors use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include "ATtinyUVLightSensor.h"

ATtinyUVLightSensor::ATtinyUVLightSensor() {
  _addr = SI1145_ADDR;
}


boolean ATtinyUVLightSensor::begin(void) {
  TinyWireM.begin();

  uint8_t id = read8(SI1145_REG_PARTID);
  if (id != 0x45) return false; // look for SI1145

  reset();

    /***********************************/
  // enable UVindex measurement coefficients!
  write8(SI1145_REG_UCOEFF0, 0x29);
  write8(SI1145_REG_UCOEFF1, 0x89);
  write8(SI1145_REG_UCOEFF2, 0x02);
  write8(SI1145_REG_UCOEFF3, 0x00);

  // enable UV sensor
  writeParam(SI1145_PARAM_CHLIST, SI1145_PARAM_CHLIST_ENUV |
  SI1145_PARAM_CHLIST_ENALSIR | SI1145_PARAM_CHLIST_ENALSVIS |
  SI1145_PARAM_CHLIST_ENPS1);
  // enable interrupt on every sample
  write8(SI1145_REG_INTCFG, SI1145_REG_INTCFG_INTOE);
  write8(SI1145_REG_IRQEN, SI1145_REG_IRQEN_ALSEVERYSAMPLE);

/****************************** Prox Sense 1 */

  // program LED current
  write8(SI1145_REG_PSLED21, 0x03); // 20mA for LED 1 only
  writeParam(SI1145_PARAM_PS1ADCMUX, SI1145_PARAM_ADCMUX_LARGEIR);
  // prox sensor #1 uses LED #1
  writeParam(SI1145_PARAM_PSLED12SEL, SI1145_PARAM_PSLED12SEL_PS1LED1);
  // fastest clocks, clock div 1
  writeParam(SI1145_PARAM_PSADCGAIN, 0);
  // take 511 clocks to measure
  writeParam(SI1145_PARAM_PSADCOUNTER, SI1145_PARAM_ADCCOUNTER_511CLK);
  // in prox mode, high range
  writeParam(SI1145_PARAM_PSADCMISC, SI1145_PARAM_PSADCMISC_RANGE|
    SI1145_PARAM_PSADCMISC_PSMODE);

  writeParam(SI1145_PARAM_ALSIRADCMUX, SI1145_PARAM_ADCMUX_SMALLIR);
  // fastest clocks, clock div 1
  writeParam(SI1145_PARAM_ALSIRADCGAIN, 0);
  // take 511 clocks to measure
  writeParam(SI1145_PARAM_ALSIRADCOUNTER, SI1145_PARAM_ADCCOUNTER_511CLK);
  // in high range mode
  writeParam(SI1145_PARAM_ALSIRADCMISC, SI1145_PARAM_ALSIRADCMISC_RANGE);


  // fastest clocks, clock div 1
  writeParam(SI1145_PARAM_ALSVISADCGAIN, 0);
  // take 511 clocks to measure
  writeParam(SI1145_PARAM_ALSVISADCOUNTER, SI1145_PARAM_ADCCOUNTER_511CLK);
  // in high range mode (not normal signal)
  writeParam(SI1145_PARAM_ALSVISADCMISC, SI1145_PARAM_ALSVISADCMISC_VISRANGE);


/************************/

  // measurement rate for auto
  write8(SI1145_REG_MEASRATE0, 0xFF); // 255 * 31.25uS = 8ms

  // auto run
  write8(SI1145_REG_COMMAND, SI1145_PSALS_AUTO);

  return true;
}

void ATtinyUVLightSensor::reset() {
  write8(SI1145_REG_MEASRATE0, 0);
  write8(SI1145_REG_MEASRATE1, 0);
  write8(SI1145_REG_IRQEN, 0);
  write8(SI1145_REG_IRQMODE1, 0);
  write8(SI1145_REG_IRQMODE2, 0);
  write8(SI1145_REG_INTCFG, 0);
  write8(SI1145_REG_IRQSTAT, 0xFF);

  write8(SI1145_REG_COMMAND, SI1145_RESET);
  delay(10);
  write8(SI1145_REG_HWKEY, 0x17);

  delay(10);
}


//////////////////////////////////////////////////////

// returns the UV index * 100 (divide by 100 to get the index)
uint16_t ATtinyUVLightSensor::readUV(void) {
 return read16(0x2C);
}

// returns visible+IR light levels
uint16_t ATtinyUVLightSensor::readVisible(void) {
 return read16(0x22);
}

// returns IR light levels
uint16_t ATtinyUVLightSensor::readIR(void) {
 return read16(0x24);
}

// returns "Proximity" - assumes an IR LED is attached to LED
uint16_t ATtinyUVLightSensor::readProx(void) {
 return read16(0x26);
}

/*********************************************************************/

uint8_t ATtinyUVLightSensor::writeParam(uint8_t p, uint8_t v) {
  //Serial.print("Param 0x"); Serial.print(p, HEX);
  //Serial.print(" = 0x"); Serial.println(v, HEX);

  write8(SI1145_REG_PARAMWR, v);
  write8(SI1145_REG_COMMAND, p | SI1145_PARAM_SET);
  return read8(SI1145_REG_PARAMRD);
}

uint8_t ATtinyUVLightSensor::readParam(uint8_t p) {
  write8(SI1145_REG_COMMAND, p | SI1145_PARAM_QUERY);
  return read8(SI1145_REG_PARAMRD);
}

/*********************************************************************/

uint8_t  ATtinyUVLightSensor::read8(uint8_t reg) {
  uint16_t val;
    TinyWireM.beginTransmission(_addr);
    TinyWireM.send((uint8_t)reg);
    TinyWireM.endTransmission();

    TinyWireM.requestFrom((uint8_t)_addr, (uint8_t)1);
    return TinyWireM.receive();
}

uint16_t ATtinyUVLightSensor::read16(uint8_t a) {
  uint16_t ret;

  TinyWireM.beginTransmission(_addr); // start transmission to device
  TinyWireM.send(a); // sends register address to read from
  TinyWireM.endTransmission(); // end transmission

  TinyWireM.requestFrom(_addr, (uint8_t)2);// send data n-bytes read
  ret = TinyWireM.receive(); // receive DATA
  ret |= (uint16_t)TinyWireM.receive() << 8; // receive DATA

  return ret;
}

void ATtinyUVLightSensor::write8(uint8_t reg, uint8_t val) {

  TinyWireM.beginTransmission(_addr); // start transmission to device
  TinyWireM.send(reg); // sends register address to write
  TinyWireM.send(val); // sends value
  TinyWireM.endTransmission(); // end transmission
}
