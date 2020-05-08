---
layout: default
title: Home
nav_order: 1
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /
---
# Arduino Simple Field Oriented Control (FOC)  

![Library Compile](https://github.com/askuric/Arduino-FOC/workflows/Library%20Compile/badge.svg)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![arduino-library-badge](https://www.ardu-badge.com/badge/Simple%20FOC.svg?)](https://www.ardu-badge.com/badge/Simple%20FOC.svg)

Proper low-cost and low-powert FOC supporting boards are very hard to find these days and even may not exist. Even harder to find is a stable and simple FOC algorithm code capable of running on Arduino devices. 
Therefore this is an attempt to: 
- Demistify FOC algorithm and make a robust but simple Arduino library: [Arduino SimpleFOC library](#arduino-simplefoclibrary)
- Develop a modular BLDCdriver boards: [Arduino SimpleFOC shield](arduino_simplefoc_shield_showcase).

## Arduino <span class="simple">Simple<span class="foc">FOC</span> Shield</span>
<p> <img src="extras/Images/shield_top_v13.png" style="height:300px">   <img src="extras/Images/shield_v13.png" style="height:300px"></p>

### Features
- **Plug & play**: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span> 
- **Low-cost**: Price in the range of \$20-\$40
- **Open Source**: Gerber files and BOM available
- **Stackable**: running 2 motors in the same time

##### If you are interested in this board, find more information on this link: [Arduino Simple FOC Shield](https://askuric.github.io/simplefoc.html)

## Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
<iframe style="height:350px;width:100%; " src="https://www.youtube.com/embed/N_fRYf7Z80k" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

This video demonstrates the Simple FOC library basic usage, electronic connections and shows its capabilities.


### Features
- **Arduino compatibe**: Arduino library code
- **Easy to setup and configure**: 
  - Easy hardware configuration
  - Easy [tuning the control loops](control_loops)
- **Modular**:
  - Supports as many [sensors ,  BLDC motors  and  driver boards](electrical_connections) as possible
  - Supports as many applicaiton requirements as possible
- **Plug & play**: Arduino SimpleFOC shield