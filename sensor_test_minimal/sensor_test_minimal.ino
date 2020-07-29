#include "MagneticSensorSPI.h"
#include "MagneticSensorI2C.h"


// Choose magnetic sensor type of communication to use
// SPI - MagneticSensorSPI class
// I2C - MagneticSensorI2C class
// ABI - Encoder class

// MagneticSensorI2C(uint8_t _chip_address, float _cpr, uint8_t _angle_register_msb)
//  @param _chip_address  I2C chip address
//  @param _cpr  counts per revolution 
//  @param _angle_register_msb  angle read register
// 
// make sure to read the chip address and the chip magnitude/angle register msb value from the datasheet
MagneticSensorI2C sensor = MagneticSensorI2C(0x36, 12, 0x0E, 4);


// MagneticSensorSPI(int cs, float _cpr, int _angle_register)
//  cs              - SPI chip select pin 
//  _cpr            - count per revolution 
// _angle_register  - (optional) angle read register - default 0x3FFF
//
// most of the sensors have the same angle register but please do check in the datasheet of your sensor
// the default value is the 0x3FFF
// MagneticSensorSPI sensor = MagneticSensorSPI(10, 16384, 0x3FFF);

void setup() {
  // monitoring port
  Serial.begin(115200);

  // initialise magnetic sensor hardware
  sensor.init();

  Serial.println("Magnetic sensor ready");
  _delay(1000);
}

void loop() {
  // display the angle and the angular velocity to the terminal
  Serial.print((uint16_t)sensor.getAngle(),BIN);
  Serial.print("\t");
  Serial.print(sensor.getAngle());
  Serial.print("\t");
  Serial.println(sensor.getVelocity());
}
