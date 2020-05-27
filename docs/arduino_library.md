---
layout: default
title: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 3
permalink: /arduino_simplefoc_library_showcase
---


# Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>

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
  - Easy [tuning the control loops](control_loops)
- **Modular**:
  - Supports as many [sensors ,  BLDC motors  and  driver boards](electrical_connections) as possible
  - Supports as many application requirements as possible
- **Plug & play**: Especially in combination with the Arduino <span class="simple">Simple<span class="foc">FOC</span>Shiled</span>

## YouTube demonstration video
<iframe class="youtube" src="https://www.youtube.com/embed/N_fRYf7Z80k" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

This video demonstrates the <span class="simple">Simple<span class="foc">FOC</span>library</span> basic usage, electronic connections and shows its basic capabilities.

**The video hardware setup consists of:**
- HMBGC V2.2 board <a class="pull-right" href="https://www.ebay.com/itm/HMBGC-V2-0-3-Axle-Gimbal-Controller-Control-Plate-Board-Module-with-Sensor/351497840990?hash=item51d6e7695e:g:BAsAAOSw0QFXBxrZ">Ebay link <span class="fa fa-link"></span></a>
- AMT 103 CUI Encoder 2048ppr <a class="pull-right" href="https://www.mouser.fr/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFaduivK%252B0pk7%2Fn5JVYn0KI22hXp9BVM%2FOAA64YDfmI%2FUQlRWDW0CMgz3WfQ6GDou4mx58%3D">Mouser link <span class="fa fa-link"></span></a>
- BLDC Gimbal Motor  <a class="pull-right" href="https://fr.aliexpress.com/item/32483131130.html?spm=a2g0o.productlist.0.0.6ddd749fFd3u9E&algo_pvid=a67f2ec1-5341-4f97-ba3e-720e24f6c4fb&algo_expid=a67f2ec1-5341-4f97-ba3e-720e24f6c4fb-10&btsid=0b0a187915885172220541390e7eed&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_">Aliexpress link <span class="fa fa-link"></span></a>
 