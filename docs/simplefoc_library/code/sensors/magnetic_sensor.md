---
layout: default
title: Magnetic sensors
parent: Position Sensors
grand_parent: Using the Code
grand_grand_parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 2
permalink: /magnetic_sensor
---


## Magnetic sensor setup
In order to use your magnetic position sensor with Simple FOC library first create an instance of the `MagneticSensor` class:
```cpp
// MagneticSensor(int cs, float _cpr, int _angle_register)
//  cs              - SPI chip select pin 
//  _cpr            - counts per revolution 
// _angle_register  - (optional) angle read register - default 0x3FFF
MagneticSensor sensor = MagneticSensor(10, 16384, 0x3FFF);
```
The parameters of the class is the `chip_select` pin number you connected your sensor to, the range of your sensor (counter value for full rotation) and your `angle register` number telling the library which register value should it ask the sensor for in order to retrieve the angle value. The default `angle_register` number is set to `0x3FFF` as it is the angle register for most of the low cost AS5x4x sensors. 

Finally after the initialization the only thing you need to do afterwards is to call the `init()` function. This function prepares the SPI interface and initializes the sensor hardware. So your magnetic sensor initialization code will look like:
```cpp
MagneticSensor sensor = MagneticSensor(10, 16384, 0x3FFF);

void loop(){
  ...
  sensor.init();
  ...
}
```

If you wish to use more than one magnetic sensor, make sure you connect their `chip select` pins to different arduino pins and follow the same idea as above, here is a simple example:
```cpp
MagneticSensor sensor1 = MagneticSensor(10, 16384, 0x3FFF);
MagneticSensor sensor1 = MagneticSensor(9, 16384, 0x3FFF);

void loop(){
  ...
  sensor1.init();
  sensor2.init();
  ...
}
```

Please check the `magnetic_sensor_example.ino` example to see more about it.
