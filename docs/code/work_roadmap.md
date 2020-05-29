---
layout: default
title: Work roadmap
nav_order: 8
parent: Code
permalink: /roadmap
---

##  Roadmap
## In progress
#### Usability 
- [ ] VIDEO: Publish a video tutorial for using the library and the samples  
- [ ] VIDEO: Coding setup and procedure video
- [ ] VIDEO: Two motors running on HMBGC example

#### Features
- [ ] Implement support for MOSFET control low and high pairs
- [ ] FOC using IMU - encoderless control for camera gimbal and similar applications
- [ ] Support for fully open-loop operation (no sensor)
- [ ] Device specific code separation: Easier porting in between devices
- [ ] Device specific: STM32 Nucleo support
- [ ] Device specific: STM32 BLuepill support

## Completed Work
#### Usability 
- [x] Make the library accessible in the Arduino Library Manager 
- [x] Make minimal version of the arduino code - all in one arduino file
- [x] Documentation separation from README
- [x] Proper introduction of the Arduino <span class="simple">Simple<span class="foc">FOC</span>Shield</span>
- [x] VIDEO: Initial video with simple demonstration

#### Features
- [x] Encoder index proper implementation
- [x] Enable more driver types 
- [x] Make support for magnetic encoder AS5048 ABI
- [x] Make support for magnetic encoder AS5048 SPI
- [x] Add support for acceleration ramping
- [x] Velocity Low pass filter
- [x] Timer interrupt execution rather than in the `loop()`: ❌ No real performance improvement
- [x] Sine wave lookup table implementation
- [X] Implement Space Vector Modulation method : Pure SVM
- [x] Implement Space Vector Modulation method : PWM SVM