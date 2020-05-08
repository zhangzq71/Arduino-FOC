---
layout: default
title: Arduino <span class="simple">Simple<span class="foc">FOC</span> Shield</span> 
parent: Hardware components
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 1
permalink: /arduino_simplefoc_shield
---


## Arduino <span class="simple">Simple<span class="foc">FOC</span> Shield</span> example
The SimpleFOC shiled, being Arduino UNO shield, is compatible with any type of board with the same headers.
Essentially, it is a L6234 chip breakout board made in a form of Arduino Shield.

<p> <img src="extras/Images/shield_top_v13.png" style="height:300px">   <img src="extras/Images/shield_v13.png" style="height:300px">
</p>

### Connector types
 - Terminal connectors 
    - motor pahse lines `a`,`b` and `c`
    - power supply cables (12V to 24V)
 - Encoder connector
    - Integrated configurable pull-ups

More information on this link: [Arduino Simple FOC Shield](arduino_simplefoc_shield_showcase).


## Component connection schematic
<img src="extras/Images/foc_shield_v13.png" >

### Encoder 
- Channels `A` and `B` are connected to the encoder connector `P_ENC`, terminals `A` and `B`. 
- If your encoder has `index` signal you can connect it to the encoder connector as well, terminal `I`.

### Motor
- Motor phases `a`, `b` and `c` are connected directly the motor terminal connector `TB_M1`
- `a`,`b`,`c` and encoder channels `A` and `B` have to be oriented right for the algorightm to work. But don't worry about it too much. Connect it in initialy as you wish and then if it doesnt move reverse pahse `a` and `b` of the motor, that should be enogh.


## Arduino SimpleFOC Shield V1.2 example
<img src="extras/Images/foc_shield_v12.jpg" style="height:500px">