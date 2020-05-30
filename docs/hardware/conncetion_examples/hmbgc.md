---
layout: default
title: HMBGC V2.2
parent: Connection examples
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 3
permalink: /hmbgc
grand_parent: Supported Hardware
---


# HMBGC V2.2
To use HMBGC controller for vector control (FOC) you need to connect motor to one of the motor terminals and connect the encoder to the analog pins. Following pictures show the schematic of the HMBGC board necessary connections and the one real example of the connection.

<p>	<img src="extras/Images/hmbgc_connection.png" class="img400"> </p>
 
 
## Encoder
<blockquote class="warning"> <p class="heading">Pinout restriction</p>
HMBGC doesn't have access to the Arduino's external interrupt pins <code>2</code> and <code>3</code>, moreover the only pins we have access to are analog pins <code>A0-A7</code>. 
Therefore we need to read the encoder channels using the software interrupt library, please check the  encoder <a href="encoder">code implementation </a> for more information. </blockquote>

Please see the HMBGC code example (`HMBGC_example.ino`) to test all the functionalities.

- Encoder channels `A` and `B` are connected to the pins `A0` and `A1`.
- Optionally if your encoder has `index` signal you can connect it to any available pin, figure shows pin `A2`.  

## Motor
- Motor phases `a`,`b` and `c` are connected directly to the driver outputs
- Motor terminal `M1` uses Arduino pins `9`,`10`,`11` and `M2` uses `3`,`5`,`6`

<blockquote class="info"> <p class="heading">Alignment</p>
Motor phases <code>a</code>,<code>b</code>,<code>c</code> and encoder channels <code>A</code> and <code>B</code> have to have the same orientation for the algorithm to work. But don't worry about it too much. Connect it initially as you wish and then if the motor locks in place reverse phase <code>a</code> and <code>b</code> of the motor, that should be enough.
</blockquote>


<blockquote class="danger"> HMBGC board doesn't support magnetic sensors because it doesn't have necessary SPI infrastructure.</blockquote>

## Example connection
<p><img src="extras/Images/hmbgc_v22.jpg" class="width80">
</p>