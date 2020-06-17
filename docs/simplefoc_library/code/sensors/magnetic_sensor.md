---
layout: default
title: Magnetic sensor
parent: Position Sensor
grand_parent: Using the Code
grand_grand_parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 2
permalink: /magnetic_sensor
---


# Magnetic sensor setup
<div class="width60">
<img src="extras/Images/mag0.jpg" style="width:32%;display:inline"><img src="extras/Images/mag.jpg" style="width:32%;display:inline"><img src="extras/Images/mag2.jpg" style="width:32%;display:inline">
</div>

Magnetic sensors implementation in this library is based only on **SPI** communication. If you wish to use the sensor with its **ABI interface** you will use it as any other `Encoder` sensor.

Now in order to use your magnetic position sensor with <span class="simple">Simple<span class="foc">FOC</span>library</span> first create an instance of the `MagneticSensor` class:
```cpp
// MagneticSensor(int cs, float _cpr, int _angle_register)
//  cs              - SPI chip select pin 
//  _cpr            - counts per revolution 
// _angle_register  - (optional) angle read register - default 0x3FFF
MagneticSensor sensor = MagneticSensor(10, 16384, 0x3FFF);
```
The parameters of the class is the `chip_select` pin number you connected your sensor to be used with the SPI communication, the range of your sensor (counter value for full rotation) and your `angle register` number telling the library which register value should it ask the sensor for in order to retrieve the angle value. The default `angle_register` number is set to `0x3FFF` as it is the angle register for most of the low cost AS5048/AS5047 sensors. 

<blockquote class="warning"><p class="heading">Magnetic sensor CPR</p> Usually when talking about magnetic position sensors we don't talk about the counts per revolution (CPR) but about the number of bits in the counter register.  Which means:<ul><li> - 12bit sensor has CPR = 2^12 = 4096</li><li>- 16bit sensor has CPR = 2^14 = 16384</li></ul > </blockquote>

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


## Using magnetic sensor in real-time

There are two ways to use magnetic sensor implemented within this library:
- As motor position sensor for FOC algorithm
- As standalone position sensor

### Position sensor for FOC algorithm

To use the ensor with the FOC algorithm implemented in this library, once when you have initialized `sensor.init()` you just need to link it to the BLDC motor by executing:
```cpp
motor.linkSensor(&sensor);
```

### Standalone sensor 

To get the magnetic sensor angle and velocity at any given time you can use the public methods:
```cpp
class MagneticSensor{
 public:
    // shaft velocity getter
    float getVelocity();
  	// shaft angle getter
    float getAngle();
}
```

Here is a quick example:
```cpp
  
#include <SimpleFOC.h>

// MagneticSensor(int cs, float _cpr, int _angle_register)
//  cs              - SPI chip select pin 
//  _cpr            - counts per revolution 
// _angle_register  - (optional) angle read register - default 0x3FFF
MagneticSensor AS5x4x = MagneticSensor(10, 16384, 0x3FFF);

void setup() {
  // monitoring port
  Serial.begin(115200);

  // initialise magnetic sensor hardware
  AS5x4x.init();

  Serial.println("AS5x4x ready");
  _delay(1000);
}

void loop() {
  // display the angle and the angular velocity to the terminal
  Serial.print(AS5x4x.getAngle());
  Serial.print("\t");
  Serial.println(AS5x4x.getVelocity());
}
```