---
layout: default
title: Angle Control loop
parent: Control loops
grand_parent: Code
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 3
permalink: /angle_loop
---

### Angle control loop
This control loop allows you to move your BLDC motor to the desired angle in real time.   This mode is enabled by:
```cpp
// angle control loop
motor.controller = ControlType::angle;
```

<img src="extras/Images/angle_loop.png">

You can test this algorithm by running the example `angle_control.ino`.
The angle control loop is done by adding one more control loop in cascade on the velocity control loop like showed on the figure above. The loop is closed by using simple P controller. The controller reads the angle <i>a</i> from the motor and determines which velocity <i>v<sub>d</sub></i> the motor should move to reach desire angle <i>a<sub>d</sub></i> set by the user. And then the velocity controller reads the current filtered velocity from the motor <i>v<sub>f</sub></i> and sets the voltage <i>u<sub>q</sub></i> that is needed to reach the velocity <i>v<sub>d</sub></i>, set by the angle loop. 

#### Controller parameters
To tune this control loop you can set the parameters to both angle P controller and velocity PI controller. 
``` csharp
// controller configuration based on the control type 
// velocity PI controller parameters
// default P=0.5 I = 10
motor.PI_velocity.P = 0.2;
motor.PI_velocity.I = 20;
//default voltage_power_supply/2
motor.PI_velocity.voltage_limit = 6;
// jerk control using voltage voltage ramp
// default value is 300 volts per sec  ~ 0.3V per millisecond
motor.PI_velocity.voltage_ramp = 1000;

// velocity low pass filtering
// default 5ms - try different values to see what is the best. 
// the lower the less filtered
motor.LPF_velocity.Tf = 0.01;

// angle P controller 
// default P=20
motor.P_angle.P = 20;
//  maximal velocity of the position control
// default 20
motor.P_angle.velocity_limit = 4;
```
It is important to parameter both velocity PI and angle P controller to have the optimal performance.
The velocity PI controller is parametrized by updating the `motor.PI_velocity` structure as explained before. 
- Rough rule should be to lower the proportional gain `P` in order to achieve less vibrations.
- You probably wont have to touch the `I` value.
  
The angle P controller can be updated by changing the `motor.P_angle` structure. 
- Roughly proportional gain `P` will make it more responsive, but too high value will make it unstable.
  
For the angle control you will be able to see the influence of the velocity LPF filter as well. But the `Tf` value should not change much form the velocity control. So once you have it tuned for the velocity loop you can leave it as is.

Additionally you can configure the `velocity_limit` value of the controller. This value prevents the controller to set too high velocities $v_d$ to the motor. 
- If you make your `velocity_limit` very low your motor will be moving in between desired positions with exactly this velocity. If you keep it high, you will not notice that this variable even exists. :D  

Finally, each application is a bit different and the chances are you will have to tune the controller values a bit to reach desired behavior.
