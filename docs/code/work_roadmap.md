---
layout: default
title: Work roadmap
nav_order: 8
parent: Code
permalink: /roadmap
---

##  Roadmap
### In progress
#### Usability 
- [ ] Proper introduction of the **Arudino FOC Shield**
- [ ] VIDEO: Publish a video tutorial fir using the library and the samples  
- [x] VIDEO: Initial video with simple demonstration
- [ ] VIDEO: Coding setup and procedure video
- [ ] VIDEO: Two motors running on HMBGC example

#### Features
- [ ] Implement Space Vector Modulation method : Pure SVM
- [x] Implement Space Vector Modulation method : PWM SVM
- [ ] Implement support for MOSFET control low and high pairs

### Completed Work
- [x] Make the library accesible in the Arduino Library Manager 
- [x] Make minimal version of the arduino code - all in one arduino file
- [x] Encoder index proper implementation
- [x] Enable more dirver types 
- [x] Make support for magnetic encoder AS5048 ABI
- [x] Make support for magnetic encoder AS5048 SPI
- [x] Add support for acceleration ramping
- [x] Velocity Low pass filter
- [x] Timer interrupt execution rather than in the `loop()`
  - FAIL: Perfromance not improved
- [x] Sine wave lookup table implementation
- [x] Documentation separation from README