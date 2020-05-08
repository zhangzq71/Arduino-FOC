---
layout: default
title: Arduino UNO + L6234 + Encoder
parent: Arduino UNO + L6234
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 1
permalink: /arduino_l6234_encoder
grand_parent: Electrical connections
---

## Arduino UNO + L6234 driver + Encoder
<p>
 <img src="extras/Images/arduino_connection.png" >
 <img src="extras/Images/uno_l6234.jpg" style="max-height:500px">
</p>  

### Encoder
- Encoder channels `A` and `B` are connected to the Arduino's external intrrupt pins `2` and `3`. 
- Optionally if your encoder has `index` signal you can connect it to any available pin, figure shows pin `4`.
  - For Arudino UNO and similar broads which dont have 3 hardware interrupts, if you can choose, preferably connect index pin to pins `A0-A5` due to the interrupt rutine, it will have better performance (but any other pin will work as well).  
  - Othervise if you are using different board and have 3 hardware interrupt pins connect the index pin to one of them.
### L6234 breakout board 
- Connected to the arduino pins `9`,`10` and `11` (you can use also pins `5` and `6`).  
- Additionally you can connect the `enable` pin to the any digital pin of the arduino the picture shows pin `8` but this is optional. You can connect the driver enable directly to 5v. 
- Make sure you connect the common ground of the power supply and your Arduino
### Motor
- Motor phases `a`, `b` and `c` are connected directly to the driver outputs
- Motor phases `a`,`b`,`c` and encoder channels `A` and `B` have to be oriented right for the algorightm to work. But don't worry about it too much. Connect it in initialy as you wish and then if it doesnt move reverse pahse `a` and `b` of the motor, that should be enogh.
