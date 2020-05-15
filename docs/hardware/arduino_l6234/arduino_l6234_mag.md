---
layout: default
title: Arduino UNO + L6234 + Magnetic AS5048
parent: Arduino UNO + L6234
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 2
permalink: /arduino_l6234_magnetic
grand_parent: Electrical connections
---

## Arduino UNO + L6234 driver + Magnetic sensor  AS5048

<p>
 <img src="extras/Images/arduino_connection_magnetic.png">
</p>  

### Magnetic sensor
- Magnetic sensor's (AS5048) SPI interface signals `SCK`, `MISO` and `MOSI` are connected to the Arduino's `SPI` pins (Arduino UNO `13`,`12` and `11`). 
  - If the application requires more than one sensor all of them are connected to the same pins of the Arduino.
- The `chip select` pin is connected to the desired pin. Each sensor connected to the same Arduino has to have unique chip select pin.
### L6234 breakout board 
- Connected to the arduino pins `3`,`5` and `6` (you can use also pin `9` and `10`, pin `11` is taken by the SPI interface).  
- Additionally you can connect the `enable` pin to the any digital pin of the arduino the picture shows pin `2` but this is optional. You can connect the driver enable directly to 5v. 
- Make sure you connect the common ground of the power supply and your Arduino
### Motor
- Motor phases `a`, `b` and `c` are connected directly to the driver outputs
- Motor phases `a`,`b`,`c` and the magnetic sensor counting direction have to be oriented right for the algorithm to work. But don't worry about it too much. Connect it initially as you wish and then if the motor locks in place inverse `a` and `b` line of the motor.

