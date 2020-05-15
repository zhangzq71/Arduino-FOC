---
layout: default
title: Voltage Control loop
parent: Control loops
grand_parent: Code
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /voltage_loop
nav_order: 1
---

### Voltage control loop
This control loop allows you to run the BLDC motor as it is simple DC motor using Park transformation. This mode is enabled by:
```cpp
// voltage control loop
motor.controller = ControlType::voltage;
```
 <a name="foc_image"></a><img src="extras/Images/voltage_loop.png">

You can test this algorithm by running the example `voltage_control.ino`.
The FOC algorithm reads the angle <i>a</i> from the motor and sets appropriate <i>u<sub>a</sub></i>, <i>u<sub>b</sub></i> and <i>u<sub>c</sub></i> voltages such to always have <i>90 degree</i> angle in between the magnetic fields of the permanent magnets in rotor and the stator. What is exactly the principle of the DC motor.
> This control loop will give you the motor which spins freely with the velocity depending on the voltage <i>U<sub>q</sub></i> you set and the disturbance it is facing. *It will turn slower if you try to hold it*.

