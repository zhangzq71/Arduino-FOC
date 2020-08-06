---
layout: default
title: Steer by wire
parent: Example projects
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 7
permalink: /haptics_arduino_example
grand_parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span> 
---


# Steer by wire <br>using <span class="simple">Simple<span class="foc">FOC</span>Shield</span> and Arduino UNO

[Arduino UNO](https://store.arduino.cc/arduino-uno-rev3) | 2x[Arduino <span class="simple">Simple<span class="foc">FOC</span>Shield</span>](arduino_simplefoc_shield_showcase) | [AMT 103 encoder](https://www.mouser.fr/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFaduiAsBlScvLoAWHUnKz39jAIpNPVt58AQ0PVb84dpbt53g%3D%3D) | [AS5600](https://www.ebay.com/itm/1PC-New-AS5600-magnetic-encoder-sensor-module-12bit-high-precision/303401254431?hash=item46a41fbe1f:g:nVwAAOSwTJJd8zRK) | 2x[IPower GBM4198H-120T](https://www.ebay.com/itm/iPower-Gimbal-Brushless-Motor-GBM4108H-120T-for-5N-7N-GH2-ILDC-Aerial-photo-FPV/254541115855?hash=item3b43d531cf:g:q94AAOSwPcVVo571)
--- | --- | --- | --- | --- 
<img src="extras/Images/arduino_uno.jpg" class="imgtable150"> |  <img src="extras/Images/shield_to_v13.jpg" class="imgtable150">  | <img src="extras/Images/enc1.png" class="imgtable150"> | <img src="extras/Images/as5600.jpg" class="imgtable150">  | <img src="extras/Images/mot.jpg" class="imgtable150"> 



<blockquote class="info"><p class="heading">NOTE</p>
Full documentation will be provided shortly
</blockquote>


## Full Arduino code

```cpp
#include <SimpleFOC.h>
// software interrupt library
#include <PciManager.h>
#include <PciListenerImp.h>

BLDCMotor motor1 = BLDCMotor(3, 10, 6, 11, 7);
Encoder encoder1 = Encoder(A2, 2, 500, A0);
void doA1(){encoder1.handleA();}
void doB1(){encoder1.handleB();}
void doI1(){encoder1.handleIndex();}

// encoder interrupt init
PciListenerImp listenerA(encoder1.pinA, doA1);
PciListenerImp listenerB(encoder1.pinB, doB1);
PciListenerImp listenerI(encoder1.index_pin, doI1);

BLDCMotor motor2 =  BLDCMotor(9, 11, 5, 11, 8);
MagneticSensorI2C sensor2 = MagneticSensorI2C(0x36, 12, 0x0E, 4);

void setup() {

  // initialise encoder hardware
  encoder1.init();  
  // interrupt initialization
  PciManager.registerListener(&listenerA);
  PciManager.registerListener(&listenerB);
  PciManager.registerListener(&listenerI);
  
  // link the motor to the sensor
  motor1.linkSensor(&encoder1);
  // set control loop type to be used
  motor1.controller = ControlType::voltage;
  // initialise motor
  motor1.init();
  // align encoder and start FOC
  motor1.initFOC();
  
  // initialise magnetic sensor hardware
  sensor2.init();
  // link the motor to the sensor
  motor2.linkSensor(&sensor2);
  // set control loop type to be used
  motor2.controller = ControlType::voltage;
  // initialise motor
  motor2.init();
  // align encoder and start FOC
  motor2.initFOC();
  
  Serial.println("Steer by wire ready!");
  _delay(1000);
}

void loop() {
  // iterative setting FOC phase voltage
  motor1.loopFOC();
  motor2.loopFOC();

  motor1.move( 5*(motor2.shaft_angle - motor1.shaft_angle));
  motor2.move( 5*(motor1.shaft_angle - motor2.shaft_angle));
  
}
```