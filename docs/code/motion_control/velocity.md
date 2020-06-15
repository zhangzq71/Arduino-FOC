---
layout: default
title: Velocity Control
parent: Motion Control
grand_parent: Using the Code
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /velocity_loop
nav_order: 2
---

# Velocity control loop
This control loop allows you to spin your BLDC motor with desired velocity.  This mode is enabled by:
```cpp
// velocity control loop
motor.controller = ControlType::velocity;
```

<img src="extras/Images/velocity_loop.png" >

You can test this algorithm by running the example `velocity_control.ino`.
The velocity control is created by adding a PI velocity controller. This controller reads the motor velocity <i>v</i>, filters it to <i>v<sub>f</sub></i> and sets the <i>u<sub>q</sub></i> voltage to the motor in a such manner that it reaches and maintains the target velocity <i>v<sub>d</sub></i>, set by the user. 
## PI controller parameters
To change the parameters of your PI controller to reach desired behavior you can change `motor.PI_velocity` structure:
```cpp
// controller configuration based on the control type 
// velocity PI controller parameters
// default P=0.5 I = 10
motor.PI_velocity.P = 0.2;
motor.PI_velocity.I = 20;
//default voltage_power_supply
motor.PI_velocity.voltage_limit = 8;
// jerk control using voltage voltage ramp
// default value is 300 volts per sec  ~ 0.3V per millisecond
motor.PI_velocity.voltage_ramp = 1000;

// velocity low pass filtering
// default 5ms - try different values to see what is the best. 
// the lower the less filtered
motor.LPF_velocity.Tf = 0.01;
```
The parameters of the PI controller are proportional gain `P`, integral gain `I`, voltage limit `voltage_limit`  and `voltage_ramp`. 
- The `voltage_limit` parameter is intended if, for some reason, you wish to limit the voltage that can be sent to your motor.  
- In general by raising the proportional gain `P`  your motor controller will be more reactive, but too much will make it unstable. Setting it to `0` will disable the proportional part of the controller.
- The same goes for integral gain `I` the higher it is the faster motors reaction to disturbance will be, but too large value will make it unstable. Setting it to `0` will disable the integral part of the controller.
- The `voltage_ramp` value it intended to reduce the maximal change of the voltage value which is sent to the motor. The higher the value the PI controller will be able to change faster the <i>U<sib>q</sub></i> value. The lower the value the smaller the possible change and the less responsive your controller becomes. The value of this parameter is set to be `Volts per second[V/s` or in other words how many volts can your controller raise the voltage in one time unit. If you set your `voltage_ramp` value to `10 V/s`, and on average your control loop will run each `1ms`. Your controller will be able to change the <i>U<sib>q</sub></i> value each time `10[V/s]*0.001[s] = 0.01V` what is not a lot.

Additionally, in order to smooth out the velocity measurement Simple FOC library has implemented the velocity low pass filter. [Low pass filters](https://en.wikipedia.org/wiki/Low-pass_filter) are standard form of signal smoothing, and it only has one parameter - filtering time constant `Tf`.
- The lower the value the less influence the filter has. If you put `Tf` to `0` you basically remove the filter completely. The exact `Tf` value for specific implementation is hard guess in advance, but in general the range of values of `Tf` will be somewhere form `0` to `0.5` seconds.

In order to get optimal performance you will have to fiddle a bit with with the parameters. :)
