---
layout: default
title: BLDC Motor
nav_order: 2
parent: Using the Code
permalink: /motor_initialization
---

# Motor setup


## Motor initialization
To initialism the motor you need to input the `pwm` pins, number of `pole pairs` and optionally driver `enable` pin.
```cpp
//  BLDCMotor( int phA, int phB, int phC, int pp, int en)
//  - phA, phB, phC - motor A,B,C phase pwm pins
//  - pp            - pole pair number
//  - enable pin    - (optional input)
BLDCMotor motor = BLDCMotor(9, 10, 11, 11, 8);
```
If you are not sure what your `pole_paris` number is I included an example code to estimate your `pole_paris` number in the examples `find_pole_pairs_number.ino`. I hope it helps. 

To finalize the motor setup the sensor is added to the motor and the `init` function is called.
```cpp
// link the motor to the sensor
// either Encoder class or MagneticSensor class
motor.linkSensor(&sensor);
// initialize motor
motor.init();
```


## Power supply voltage
The default  `voltage_power_supply`  value is set to `12V`. If you set your power supply to some other value, change it here for the control loops to adapt.
```cpp
// power supply voltage
motor.voltage_power_supply = 12;
```
The `voltage_power_supply` value tells the FOC algorithm what is the maximum voltage it can output. Additionally since the FOC algorithm implemented in the Simple FOC library uses sinusoidal voltages the magnitudes of the sine waves exiting the Driver circuit is going to be  `[-voltage_power_supply/2, voltage_power_supply/2]`.

<img src="../extras/Images/sine_foc.png" >

