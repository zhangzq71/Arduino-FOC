#ifndef MAGNETICSENSORI2C_LIB_H
#define MAGNETICSENSORI2C_LIB_H

#include "Arduino.h"
#include <Wire.h>
#include "FOCutils.h"
#include "Sensor.h"

class MagneticSensorI2C: public Sensor{
 public:
    /**
     * MagneticSensorI2C class constructor
     * @param chip_address  I2C chip address
     * @param cpr  counts per revolution 
     * @param angle_register_msb  angle read register msb
     */
    MagneticSensorI2C(uint8_t chip_address, float cpr, uint8_t angle_register_msb);
    

    /** sensor initialise pins */
    void init();

    // implementation of abstract functions of the Sensor class
    /** get current angle (rad) */
    float getAngle();
    /** get current angular velocity (rad/s) **/
    float getVelocity();
    /**
     *  set current angle as zero angle 
     * return the angle [rad] difference
     */
    float initRelativeZero();
    /**
     *  set absolute zero angle as zero angle
     * return the angle [rad] difference
     */
    float initAbsoluteZero();
    /** returns 1 because it is the absolute sensor */
    int hasAbsoluteZero();
    /** returns 0  maning it doesn't need search for absolute zero */
    int needsAbsoluteZeroSearch();
    

  private:
    float cpr; //!< Maximum range of the magnetic sensor
    // I2C variables
    uint8_t angle_register_msb; //!< I2C angle register to read
    uint8_t chip_address; //!< I2C chip select pins

    // I2C functions
    /** Read one I2C register value */
    word read(uint8_t angle_register_msb);

    word zero_offset; //!< user defined zero offset
    /**
     * Function getting current angle register value
     * it uses angle_register variable
     */
    int getRawCount();

    // total angle tracking variables
    float full_rotation_offset; //!<number of full rotations made
    float angle_data_prev; //!< angle in previous position calculation step

    // velocity calculation variables
    float angle_prev; //!< angle in previous velocity calculation step
    long velocity_calc_timestamp; //!< last velocity calculation timestamp

};


#endif
