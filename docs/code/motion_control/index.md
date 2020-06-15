---
layout: default
title: Motion Control
parent: Using the Code
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /motion_control
nav_order: 3
has_children: True
has_toc: False
---

# Motion control
The SimpleFOC library gives you the choice of using 3 different control strategies: 
- [torque control loop using voltage](voltage_loop)
- [position/angle motion control](angle_loop)
- [velocity motion control](velocity_loop)
<blockquote class="info"> Index search uses also uses velocity control loop, but has some additional parameters, see <a href="index_search_loop">index search</a></blockquote>


You set it by changing the `motor.controller` variable. If you want to control the motor angle you will set the `controller` to `ControlType::angle`, if you seek the DC motor behavior behavior by controlling the voltage use `ControlType::voltage`, if you wish to control motor angular velocity `ControlType::velocity`. 
```cpp
// set FOC loop to be used
// ControlType::voltage
// ControlType::velocity
// ControlType::angle
motor.controller = ControlType::angle;
```

For more information about the source code implementation of the motion control strategies check the [library source code documentation](motion_control_implementation)