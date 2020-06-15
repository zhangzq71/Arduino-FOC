---
layout: default
title: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 3
permalink: /arduino_simplefoc_library_showcase
---


# Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>

![Library Compile](https://github.com/askuric/Arduino-FOC/workflows/Library%20Compile/badge.svg)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![arduino-library-badge](https://www.ardu-badge.com/badge/Simple%20FOC.svg?)

This Arduino library implements Field Oriented Control (FOC) algorithm for BLDC motors. FOC algorithm produces incomparably smooth operation and high degree of torque, velocity and position control.
The library is intended both for: 
- Beginners searching for a simple and *user-friendly* way to learn how to control BLDC motors 
- Advanced users ready to dig deeper into the FOC algorithm and optimize the code for their particular application/hardware.

## Features
- **Arduino compatible**: Arduino library code version 
  - Arduino Library Manager integration
- **Open-Source**: Full code and documentation available on github
- **Easy to setup and configure**: 
  - Easy hardware configuration ([sensors](sensors), [BLDC motors](motor_initialization))
  - Easy [tuning the control loops](motion_control)
- **Modular**:
  - Supports as many [sensors ,  BLDC motors  and  driver boards](supported_hardware) as possible
  - Supports as many application requirements as possible
- **Plug & play**: Especially in combination with the Arduino <span class="simple">Simple<span class="foc">FOC</span>Shield</span>

### YouTube demonstration video
<iframe class="youtube" src="https://www.youtube.com/embed/Y5kLeqTc6Zk" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

This video demonstrates the <span class="simple">Simple<span class="foc">FOC</span>library</span> basic usage, electronic connections and shows its basic capabilities.

**The video hardware setup consists of:**
<ul class="width60">
<li> 
HMBGC V2.2 board <a class="pull-right" href="https://www.ebay.com/itm/HMBGC-V2-0-3-Axle-Gimbal-Controller-Control-Plate-Board-Module-with-Sensor/351497840990?hash=item51d6e7695e:g:BAsAAOSw0QFXBxrZ">Ebay link <span class="fa fa-link"></span></a>
</li>
<li>
AMT 103 CUI Encoder 2048ppr <a class="pull-right" href="https://www.mouser.fr/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFaduivK%252B0pk7%2Fn5JVYn0KI22hXp9BVM%2FOAA64YDfmI%2FUQlRWDW0CMgz3WfQ6GDou4mx58%3D">Mouser link <span class="fa fa-link"></span></a>
</li>
<li>
BLDC Gimbal Motor  <a class="pull-right" href="https://fr.aliexpress.com/item/32483131130.html?spm=a2g0o.productlist.0.0.6ddd749fFd3u9E&algo_pvid=a67f2ec1-5341-4f97-ba3e-720e24f6c4fb&algo_expid=a67f2ec1-5341-4f97-ba3e-720e24f6c4fb-10&btsid=0b0a187915885172220541390e7eed&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_">Aliexpress link <span class="fa fa-link"></span></a>
</li>
</ul> 



## Getting started
Here are some basic links where you can find more information how to get started with the <span class="simple">Simple<span class="foc">FOC</span>library</span>.

## Installation
There are two ways to install this Arduino library, depending of your plans with the code and your particular application.
- [Full library installation](library_download) - for plug & play functionality with many examples 
- [Minimal sketch installation](minimal_download) - Arduino sketch with integrated complete library
    - Easier experimentation and interaction with the library code directly
<p><img src="extras/Images/alm.gif" class="width50"></p>  


## Supported hardware
Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span> is made modular and will support most of the motor + sensor combinations out there, as well as many low-cost bldc driver boards.
Please see the [supported hardware documentation](supported_hardware) to learn more!
<p><img src="extras/Images/connection.gif" class="width50"></p>

## Using the code
This library code is written in a way to be as simple sa possible to use and to leave a lot of space for configuration and fine tuning for specific applications. 
Please see the api [code documentation](code) to learn how simple it is to use!

## Project Examples 
We are very happy to provide you with several projects multiple hardware configurations and fully documented and explained code!
Go see the [examples](examples)!
<p style="width:100%">
<a href="position_control_example"><img src="extras/Images/position_control_example.jpg" class="img200 img_half"></a><a href="velocity_control_example"><img src="extras/Images/hmbgc_v22_velocity_control.jpg" class="img200 img_half"></a><a href="simplefoc_pendulum"><img src="extras/Images/foc_pendulum.jpg" class="img200 img_half"></a>
</p>