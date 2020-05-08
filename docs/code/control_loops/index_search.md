---
layout: default
title: Index Search loop 
parent: Control loops
grand_parent: Code
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 4
permalink: /index_search_loop
---

### Index search routine
Finding the encoder index is performed only if the constructor of the `Encoder` class has been provided with the `index` pin. The search is performed by setting a constant velocity of the motor until it reaches the index pin. To set the desired searching velocity alter the paramterer:
```cpp
// index search velocity - default 1rad/s
motor.index_search_velocity = 2;
```

This velocity control loop is implemented exaclty the same as [velocity control loop](/velocity_loop) but it has different contorller paramters which can be set by:
```cpp
// index search PI contoller parameters
// default K=0.5 Ti = 0.01
motor.PI_velocity_index_search.P = 0.1;
motor.PI_velocity_index_search.I = 0.01;
motor.PI_velocity_index_search.voltage_limit = 3;
// jerk control using voltage voltage ramp
// default value is 100 volts per sec  ~ 0.1V per millisecond
motor.PI_velocity_index_search.voltage_ramp = 300;
```
If you are having problems during the finding procedure, try tuning the PI controller constants. The same parameters as the `PI_velocity` should work well, but you can put it a bit more conservative to avoid high jumps.
