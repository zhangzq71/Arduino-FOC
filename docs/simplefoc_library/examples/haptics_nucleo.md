---
layout: default
title: Haptic velocity control
parent: Example projects
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 6
permalink: /haptics_nucleo_example
grand_parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span> 
---


# Haptic velocity control <br>using <span class="simple">Simple<span class="foc">FOC</span>Shield</span> and Stm32 Nucleo-64


[Stm32 Nucleo-64](https://www.mouser.fr/ProductDetail/STMicroelectronics/NUCLEO-F446RE?qs=%2Fha2pyFaduj0LE%252BzmDN2WNd7nDNNMR7%2Fr%2FThuKnpWrd0IvwHkOHrpg%3D%3D) | 2x [Arduino <span class="simple">Simple<span class="foc">FOC</span>Shield</span>](arduino_simplefoc_shield_showcase) | 2x[AMT 103 encoder](https://www.mouser.fr/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFaduiAsBlScvLoAWHUnKz39jAIpNPVt58AQ0PVb84dpbt53g%3D%3D) | [GBM5108-120T](https://www.onedrone.com/store/ipower-gbm5108-120t-gimbal-motor.html)  | [IPower GBM4198H-120T](https://www.ebay.com/itm/iPower-Gimbal-Brushless-Motor-GBM4108H-120T-for-5N-7N-GH2-ILDC-Aerial-photo-FPV/254541115855?hash=item3b43d531cf:g:q94AAOSwPcVVo571)
--- | --- | --- | --- | ---
<img src="extras/Images/nucleo.jpg" class="imgtable150"> |  <img src="extras/Images/shield_to_v13.jpg" class="imgtable150">  | <img src="extras/Images/enc1.png" class="imgtable150">  | <img src="extras/Images/bigger.jpg" class="imgtable150"> | <img src="extras/Images/mot.jpg" class="imgtable150"> 


<blockquote class="info"><p class="heading">NOTE</p>
Full documentation will be provided shortly
</blockquote>


## Full Arduino code

```cpp
#include <SimpleFOC.h>

BLDCMotor motor1 = BLDCMotor(9, 6, 5, 11, 7);
Encoder encoder1 = Encoder(A1, A2, 8192);
void doA1(){encoder1.handleA();}
void doB1(){encoder1.handleB();}


BLDCMotor motor2 = BLDCMotor(3, 13, 10, 11, 8);
Encoder encoder2 = Encoder(A3, 2, 500);
void doA2(){encoder2.handleA();}
void doB2(){encoder2.handleB();}

void setup() {

  // initialise encoder hardware
  encoder1.init();
  encoder1.enableInterrupts(doA1,doB1);
  
  encoder2.init();
  encoder2.enableInterrupts(doA2,doB2);
    
  // link the motor to the sensor
  motor1.linkSensor(&encoder1);
  motor2.linkSensor(&encoder2);

  // power supply voltage [V]
  motor1.voltage_power_supply = 12;
  motor2.voltage_power_supply = 12;

  // set control loop type to be used
  motor1.controller = ControlType::voltage;
  motor2.controller = ControlType::velocity;


  motor2.LPF_velocity.Tf = 0.02;
  motor2.PI_velocity.I = 40;

  // use monitoring with serial for motor init
  // monitoring port
  Serial.begin(115200);
  // enable monitoring
  motor1.useMonitoring(Serial);
  motor2.useMonitoring(Serial);

  // initialise motor
  motor1.init();
  motor2.init();
  // align encoder and start FOC
  motor1.initFOC();
  motor2.initFOC();

  Serial.println("Steer by wire ready!");
  _delay(1000);
}


void loop() {
  // iterative setting FOC phase voltage
  motor1.loopFOC();
  motor2.loopFOC();

  // iterative function setting the outter loop target
  motor1.move(10*(motor2.shaft_velocity/10 - motor1.shaft_angle));
  motor2.move(10*dead_zone(motor1.shaft_angle));
  
}

float dead_zone(float x){
  return abs(x) < 0.2 ? 0 : x;
}
```