---
layout: default
title: Microcontrollers
parent: Supported Hardware
nav_order: 4
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /microcontrollers
---

# Supported microcontrollers

At the moment the library in its original form is designed and optimized for Arduino devices. Primarily for Arduino UNO and all the devices which feature ATmega328 chip.

With some minor modifications, mostly in the part of pin assignment, PWM configurations and hardware interrupts the library can be easily ported to STM32 Bluepill, ESP32 boards and similar devices.
The *off-the-shelf* support for these devices is in our [roadmap](roadmap).

Please don't hesitate to [contact](contact) us if you need assistance porting the code.