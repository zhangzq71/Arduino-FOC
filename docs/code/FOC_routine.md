---
layout: default
title: Field Oriented Control 
parent: Code 
permalink: /foc_routine
nav_order: 4
---

# Field Oriented Control routine 

## Initializing - `setup()`
After the motor and encoder are intialised and the driver and control loops are configured you intialise the FOC algorithm. 
```cpp
// align encoder and start FOC
motor.initFOC();
```
This function aligns encoder and motor zero positions and intialises FOC variables. It is intended to be run in the `setup` function of the Arudino. After the call of this funciton FOC is ready to start following your instructions.

## Real-time execution `loop()`

The real time execution of the Arduino Simple FOC library is govenred by two funcitons `motor.loopFOC()` and `motor.move(float target)`.
```cpp
// iterative setting FOC pahse voltage
// the faster you run this funciton the better
// in arduino loop it should have ~1kHz
// the best would be to be in ~10kHz range
motor.loopFOC();
```
The funciton `loopFOC()` gets the current motor angle from the encoder, turns in into the electrical angle and computes Clarke transfrom to set the desired <i>U<sub>q</sub></i> voltage to the motor. Basically it implements the funcitonality of the [voltage control loop](/voltage_loop).
- The faster you can run this funciton the better 
- In the empty arduino loop it runs at ~1kHz but idealy it would be around ~10kHz


```cpp
// iterative function setting the outter loop target
// velocity, position or voltage
// this funciton can be run at much lower frequency than loopFOC funciton
// it can go as low as ~50Hz
motor.move(target);
```
The `move()` method executes the control loops of the algorihtm. If is governed by the `motor.controller` variable. It executes eigther pure voltage loop, velocity loop or angle loop.

It receives one parameter `BLDCMotor::move(float target)` which is current user define target value.
- If the user runs [velocity loop](/velocity_loop), `move` funciton will interpret `target` as the target velocity <i>v<sub>d</sub></i>.
- If the user runs [angle loop](/angle_loop), `move` will interpret `target` parameter as the target angle<i>a<sub>d</sub></i>. 
- If the user runs the [voltage loop](/voltage_loop), `move` funciton will interpret the `target` parameter as voltage <i>u<sub>d</sub></i>.

