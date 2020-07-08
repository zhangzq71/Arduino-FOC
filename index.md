---
layout: default
title: Home
nav_order: 1
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /
---
# Arduino Simple Field Oriented Control (FOC) project

![Library Compile](https://github.com/askuric/Arduino-FOC/workflows/Library%20Compile/badge.svg)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![arduino-library-badge](https://www.ardu-badge.com/badge/Simple%20FOC.svg?)


Proper low-cost and low-power FOC supporting boards are very hard to find today and even may not exist. Even harder to find is a stable and simple FOC algorithm code capable of running on Arduino devices. 
Therefore this is an attempt to: 
- Demystify FOC algorithm and make a robust but simple Arduino library: [Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span> ](#arduino-simplefoclibrary)
- Develop a modular BLDC driver board: [Arduino <span class="simple">Simple<span class="foc">FOC</span>Shiled</span> ](arduino_simplefoc_shield_showcase).


> ***UPDATE:*** Arduino *SimpleFOClibrary* now supports high performance DRV8302 driver boards (60V, 15A, 30$). [YouTube link](https://www.youtube.com/watch?v=RI4nNMF608I).
> You can find the board by clicking on [Aliexpress link](https://bit.ly/2BZZ5fG) and the  Arduino code example in the examples folder!

## Arduino <span class="simple">Simple<span class="foc">FOC</span>Shield</span>
<iframe class="youtube"  src="https://www.youtube.com/embed/G5pbo0C6ujE" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

### Features
- **Plug & play**: In combination with Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span> 
- **Low-cost**: Price of €20 - [Check the pricing](https://www.simplefoc.com/simplefoc_shield_product) 
- **Open Source**: Fully available fabrication files - [how to make it yourself](arduino_simplefoc_shield_fabrication)
- **Stackable**: running 2 motors in the same time
- **Encoder interface**: Integrated 3kOhm pullups (configurable)
- **Configurable pinout**: Hardware configuration - soldering connections
- **Arduino headers**: Arduino UNO, Arduino MEGA, STM32 Nucleo boards...

##### If you are interested in this board as a product, find more information on this link: [Arduino Simple FOC Shield](https://simplefoc.com/simplefoc_shield_product)

<p><img src="extras/Images/simple_foc_shield_v13_small.gif" class="img200" ><img src="extras/Images/shield_to_v13.jpg" class="img200 img_half" ><img src="extras/Images/shield_bo_v13.jpg" class="img200 img_half" ></p>

## Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
<iframe class="youtube"  src="https://www.youtube.com/embed/Y5kLeqTc6Zk" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
This video demonstrates the Simple FOC library basic usage, electronic connections and shows its capabilities.


### Features
- **Arduino compatible**: Arduino library code
- **Easy to setup and configure**: 
  - Easy hardware configuration
  - Easy [tuning the control loops](motion_control)
- **Modular**:
  - Supports as many [sensors ,  BLDC motors  and  driver boards](supported_hardware) as possible
  - Supports as many application requirements as possible
  - Supports multiple [MCU architectures](microcontrollers):
     - Arduino: UNO, MEGA, any board with ATMega328 chips
     - STM32 boards: [Nucleo](https://www.st.com/en/evaluation-tools/stm32-nucleo-boards.html) and [Bluepill](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html)
- **Plug & play**: Arduino <span class="simple">Simple<span class="foc">FOC</span>Shield</span> 


## Alternative FOC supporting projects
These are some of the alternative FOC supporting projects which provide hardware and software solutions. 

<a href="https://odriverobotics.com/" >Odrive</a> | <a href="https://www.youtube.com/watch?v=g2BHEdvW9bU">Trinamic</a> | <a href="https://www.infineon.com/cms/en/product/evaluation-boards/bldc_shield_tle9879/" >Infineon</a> | <a href="https://github.com/gouldpa/FOC-Arduino-Brushless">FOC-Arduino-Brushless</a>
------------ | ------------- | ------------ | -------------
<img src="https://static1.squarespace.com/static/58aff26de4fcb53b5efd2f02/t/5c2c766921c67c143049cbd3/1546417803031/?format=1200w" style="width:100%;max-width:250px"  > | <img src="https://i3.ytimg.com/vi/g2BHEdvW9bU/maxresdefault.jpg" style="width:100%;max-width:250px"  > | <img src="https://www.infineon.com/export/sites/default/_images/product/evaluation-boards/BLDC_Motor_Shild_with_TLE9879QXA40.jpg_1711722916.jpg" style="width:100%;max-width:250px"  >| <img src="https://hackster.imgix.net/uploads/attachments/998086/dev_kit_89eygMekks.jpg?auto=compress%2Cformat&w=1280&h=960&fit=max" style="width:100%;max-width:250px"  >
✔️ Open Source | ❌ Open Source | ❌ Open Source | ✔️ Open Source
✔️Simple to use | ✔️ Simple to use | ✔️Simple to use | ❌ Simple to use
❌ Low cost ($100) | ❌ Low cost ($100) | ✔️Low cost ($40) | ✔️ Low cost
❌ Low power (>50A) | ✔️ Low power  | ✔️  Low power | ✔️ Low power