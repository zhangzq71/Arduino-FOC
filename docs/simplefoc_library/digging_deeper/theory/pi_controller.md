---
layout: default
title: PI controller theory
parent: Theory corner
grand_parent: Digging deeper
grand_grand_parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 3
permalink: /pi_controller
---

 
# PI controller theory
Transfer function of the PI controller this library implements is:

<p><img src="./extras/Images/cont_PI.png" /></p>

Continuos PI is transformed to the discrete domain using Tustin transformation. The final discrete equation becomes:

<p><img src="./extras/Images/dis_PI.png" /></p>

Where the <i>u(k)</i> is the control signal (voltage <i>U<sub>q</sub></i> in our case) in moment <i>k</i>, <i>e(k),e(k-1)</i> is the tracking error in current moment <i>k</i> and previous step <i>k-1</i>. Tracking error presents the difference in between the target velocity value <i>v<sub>d</sub></i> and measured velocity <i>v</i>. 

<p><img src="./extras/Images/track.png" /></p>


## Implementation details

The `BLDMotor` class has implemented generic PI controller function called `controllerPI()`.
```cpp
// PI controller function
float BLDCMotor::controllerPI(float tracking_error, PI_s& cont){
  float Ts = (_micros() - cont.timestamp) * 1e-6;

  // quick fix for strange cases (micros overflow)
  if(Ts <= 0 || Ts > 0.5) Ts = 1e-3; 

  // u(s) = (P + I/s)e(s)
  // Tustin transform of the PI controller ( a bit optimized )
  // uk = uk_1  + (I*Ts/2 + P)*ek + (I*Ts/2 - P)*ek_1
  float tmp = cont.I*Ts*0.5;
  float voltage = cont.voltage_prev + (tmp + cont.P) * tracking_error + (tmp - cont.P) * cont.tracking_error_prev;

  // antiwindup - limit the output voltage_q
  if (abs(voltage) > cont.voltage_limit) voltage = voltage > 0 ? cont.voltage_limit : -cont.voltage_limit;
  // limit the acceleration by ramping the the voltage
  float d_voltage = voltage - cont.voltage_prev;
  if (abs(d_voltage)/Ts > cont.voltage_ramp) voltage = d_voltage > 0 ? cont.voltage_prev + cont.voltage_ramp*Ts : cont.voltage_prev - cont.voltage_ramp*Ts;


  cont.voltage_prev = voltage;
  cont.tracking_error_prev = tracking_error;
  cont.timestamp = _micros();
  return voltage;
}
```
The PI controller is configured with `motor.PI_velocity` structure:
```cpp
// PI controller configuration structure
struct PI_s{
  float P; // Proportional gain 
  float I; // Integral gain 
  float voltage_limit; // Voltage limit of the controller output
  float voltage_ramp;  // Maximum speed of change of the output value 
  long timestamp;  // Last execution timestamp
  float voltage_prev;  // last controller output value 
  float tracking_error_prev;  // last tracking error value
};
```
