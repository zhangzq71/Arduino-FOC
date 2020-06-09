---
layout: default
title: Control loops
parent: Code
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /control_loops
nav_order: 3
has_children: True
---

# Control loops
The SimpleFOC library gives you the choice of using 4 different plug and play control loops: 
- voltage control loop
- velocity control loop
- angle control loop

You set it by changing the `motor.controller` variable. If you want to control the motor angle you will set the `controller` to `ControlType::angle`, if you seek the DC motor behavior behavior by controlling the voltage use `ControlType::voltage`, if you wish to control motor angular velocity `ControlType::velocity`. 
```cpp
// set FOC loop to be used
// ControlType::voltage
// ControlType::velocity
// ControlType::angle
motor.controller = ControlType::angle;
```