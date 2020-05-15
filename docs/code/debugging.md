---
layout: default
title: Debugging
parent: Code
nav_order: 5
permalink: /debugging
---


# Debugging

`BLDCMotor` class supports debugging using `Serial` port which is enabled by:
```cpp
motor.useDebugging(Serial);
```
before running `motor.init()`.
The class will output its status during the initialization of the motor and the FOC. Enabling the debugger will not directly influence the real-time performance. By default the class will stop its debugging output once it goes to the main loop.

To debug control loop execution in the examples we added a function `motor.monitor()` which log the motor variables to the serial port. The function logs different variables based for difference control loops.
```cpp
// utility function intended to be used with serial plotter to monitor motor variables
// significantly slowing the execution down!!!!
void BLDCMotor::monitor() {
  if(!debugger) return;
  switch (controller) {
    case ControlType::velocity:
      debugger->print(voltage_q);
      debugger->print("\t");
      debugger->print(shaft_velocity_sp);
      debugger->print("\t");
      debugger->println(shaft_velocity);
      break;
    case ControlType::angle:
      debugger->print(voltage_q);
      debugger->print("\t");
      debugger->print(shaft_angle_sp);
      debugger->print("\t");
      debugger->println(shaft_angle);
      break;
    case ControlType::voltage:
      debugger->print(voltage_q);
      debugger->print("\t");
      debugger->print(shaft_angle);
      debugger->print("\t");
      debugger->println(shaft_velocity);
      break;
  }
}
```
The intention of this method is to be called in main loop function along the `loopFOC()` and `move()` function. The function is going to impair the execution performance and reduce the sampling frequency so therefore take it in consideration when running the code. 

If you wish to implement you own debugging functions or just output the motor variables to the `Serial` terminal here are the public variables of the `BLDCMotor` class.


```cpp

class BLDCMotor
{
  public:
  ...
    // current motor angle
    float shaft_angle;
    // current motor velocity 
    float shaft_velocity;
    // current target velocity
    float shaft_velocity_sp;
    // current target angle
    float shaft_angle_sp;
    // current voltage u_q set
    float voltage_q;
...
}
```
Additionally it is possible to use encoder api directly to get the encoder angle and velocity. 
```cpp

class Encoder{
 public:
    // shaft velocity getter
    float getVelocity();
	// shaft angle getter
    float getAngle();
}
```
As well as magnetic sensor's api, to get the sensor's angle and velocity. 
```cpp

class MagneticSensor{
 public:
    // shaft velocity getter
    float getVelocity();
	// shaft angle getter
    float getAngle();
}
```