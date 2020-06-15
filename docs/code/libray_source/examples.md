---
layout: default
title: Library Examples
parent: Library Source
nav_order: 3
permalink: /library_examples
grand_parent: Using the Code
---


# Library Examples

This library comes with `17` documented examples showing the basic usage of the library with:
- **different microcontrollers**: 
    - Arduino UNO, Nucleo: everything except `hardware_specific_examples`
    - Bluepill: `bluepill_position_control.ino`
    - HMBGC gimbal controller: `position_control.ino`, `voltage_control.ino`
- **different position sensors**: encoders, magnetic sensors 
- **different motion control**: <br>
  - torque/voltage control: `torque_voltage_control.ino`
  - velocity control:  `velocity_motion_control.ino`
  - position/angle control: `position_motion_control.ino`
- **finding pole pair number** `find_pole_pair_number.ino`
- **sensor testing**:
  - encoder: `encoder_example.ino`, `encoder_software_interrupts_example.ino`
  - magnetic sensor: `magnetic_sensor_example.ino`

## Examples folder structure
```shell
| examples
│   ├─── hardware_specific_examples
│   │   ├─── Bluepill_examples                        # example of STM32 Bluepill code
│   │   │   └─── bluepill_position_control
│   │   └─── HMBGC_example                            # example of HMBGC controller code
│   │       ├─── position_control
│   │       └─── voltage_control
|   |
│   ├─── motion_control
│   │   ├─── position_motion_control                  # example of angle/position motion control loop with configuration
│   │   ├─── torque_voltage_control                   # example of the voltage/torque control loop with configuration
│   │   └─── velocity_motion_control                  # example of velocity motion control loop with configuration
│   │
│   ├─── motor_full_control_serial_examples
│   │
│   └─── utils
│       ├─── find_pole_pair_number                    # simple code example estimating pole pair number of the motor
│       └─── sensor_test
│           ├─── encoder_example                      # simple example of encoder usage
│           ├─── encoder_software_interrupts_example  # simple example of encoder usage with software interrupt library
            └─── magnetic_sensor_example              # simple example of magnetic sensor usage
```
