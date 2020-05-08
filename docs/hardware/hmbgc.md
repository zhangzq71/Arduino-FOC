---
layout: default
title: HMBGC V2.2
parent: Hardware components
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 3
permalink: /hmbgc
---


## HMBGC V2.2
To use HMBGC controller for vector control (FOC) you need to connect motor to one of the motor terminals and connect the Encoder. The shema of connection is shown on the figures above, I also took a (very bad) picture of my setup.

<p>
	<img src="extras/Images/hmbgc_connection.png" style="height:">
	<img src="extras/Images/hmbgc_v22.jpg" style="height:500px">
</p>
 
 
### Encoder
Since HMBGC doesn't have acces to the arduinos external interrupt pins `2` and `3` and additionally we only have acces to the analog pins, we need to read the encoder using the software interrupt. To show the functionallity we provide one example of the HMBGC code (`HMBGC_example.ino`) using the [PciManager library](https://github.com/prampec/arduino-pcimanager).

- Encoder channels `A` and `B` are connected to the pins `A0` and `A1`.
- Optionally if your encoder has `index` signal you can connect it to any available pin, figure shows pin `A2`.  
### Motor
- Motor phases `a`,`b` and `c` are connected directly to the driver outputs
- Motor phases `a`,`b`,`c` and encoder channels `A` and `B` have to be oriented right for the algorightm to work. But don't worry about it too much. Connect it in initialy as you wish and then if it doesnt move reverse pahse `a` and `b` of the motor, that should be enogh.

> HMBGC board doesn't support magnetic sensors because it doesn't have necessary SPI infrastructure.
