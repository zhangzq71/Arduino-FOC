---
layout: default
title: Code
nav_order: 6
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /code
has_children: True
---

# Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span> code
The code is organized into a library. The library contains main BLDC motor class `BLDCmotor` and  two sensor classes `Encoder` and `MagneticSensor`. `BLDCmotor` contains all the necessary FOC algorithm functions as well as PI controllers for the velocity and angle control.  `Encoder`  deals with the encoder interrupt functions, calculates motor angle and velocity ( using the [Mixed Time Frequency Method](https://github.com/askuric/Arduino-Mixed-Time-Frequency-Method)). The `Encoder` class will support any type of optical and magnetic encoder. `MagneticEncoder` class deals with all the necessary communication and calculation infrastructure to handle the magnetic position sensors such as AS5048 and similar. 

## <span class="simple">Simple<span class="foc">FOC</span>library</span> source structure:
```shell
│ src
│ │
│ ├─ SimpleFOC.h               # SimpleFOC library include file
│ │   
│ ├─ BLDCMotor.cpp/h           # BLDCMotor class implementing all the FOC operations
│ │ 
│ ├─ Sensor.h                  # Abstract Sensor class that all the sensors implement
│ ├─ Encoder.cpp/h             # Encoder class implementing the Quadrature encoder operations
│ ├─ MagneticSensor.cpp/h      # class implementing SPI angle read and interface for AS5047/8 type sensors
│ │ 
│ └─ FOCutils.cpp/h            # Utility functions 
```

