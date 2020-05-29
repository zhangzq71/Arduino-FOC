---
layout: default
title: Position Sensors
nav_order: 3
parent: Supported Hardware
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /position_sensors
---

# Position sensors
The library currently supports ([version 1.2.0](https://github.com/askuric/Arduino-FOC/releases)) two types of position sensors: 
- [Encoder](#encoders) 
- [Magnetic sensor (AS5048/47)](#magnetic-sensors--spi--interface).
- *IMU (in development)*

## Encoders
Encoders are by far most popular position sensors, both in industry and in hobby community. The main benefits are the precision, standardization and very low noise level. The <span class="simple">Simple<span class="foc">FOC</span>library</span> support just about any type of encoder you can find.  Here is nice short video which explains the main working principles of encoders: [YouTube video](https://www.youtube.com/watch?v=qT6FdvcEsMs)

The encoder position tracking (pulse counting) algorithm code efficiency, and especially its implementation on Arduino devices, is one of the main limitations for both performance and smoothness of the FOC algorithm. There is a clear tradeoff in between encoder precision and execution efficiency, therefore it very is important to find a suitable encoder to your application.

Examples  | Description | Link | Price
---- | ---- | ---- | ----
[<img src="extras/Images/enc.jpg"  style="height:100px">](https://www.ebay.com/itm/360-600P-R-Photoelectric-Incremental-Rotary-Encoder-5V-24V-AB-Two-Phases-Shaft/254214673272?hash=item3b30601378:m:mDiuW1F2qXINSH51TqAjhTg)  | Optical encoder<br>2400cpr | [Ebay](https://www.ebay.fr/itm/L6234-Breakout-Board-/153204519965) | 10$
[<img src="extras/Images/enc1.png" style="height:100px">](https://www.ebay.com/itm/HMBGC-V2-0-3-Axle-Gimbal-Controller-Control-Plate-Board-Module-with-Sensor/351497840990?hash=item51d6e7695e:g:BAsAAOSw0QFXBxrZ:rk:1:pf:1) | Optical encoder<br>AMT103 <br> configurable cpr 48-8192 |  [Mouser](https://www.mouser.fr/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFaduiAsBlScvLoAWHUnKz39jAIpNPVt58AQ0PVb84dpbt53g%3D%3D)  | 20$
[<img src="extras/Images/mag.jpg"  style="height:100px">](hhttps://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) | Margetic encoder <br> AS5047U <br> 16384cpr |  [Mouser](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D)<br> [Youtube demo](https://www.youtube.com/watch?v=Gl-DiOqXXJ8)   | 15$



<blockquote class="warning">
<p class="heading">Encoder CPR: Rule of thumb</p>
For Arduino UNO, the maximum number of pulses/second should not exceed 20,000. After this value it start to have execution issues. 
Please take this in consideration when choosing the encoder and especially if using more than one motor.<br>
<p class="heading">Example</p>
If your CPR value is 10000, you will be able to spin your motor with max velocity 120rpm - 2 rotations/second 
</blockquote>

      
## Magnetic sensors | SPI  interface
Magnetic position sensor has many benefits over the encoders:
- Very efficient position calculation ( no counting ) 
- Time of execution doesn't depend on velocity or number of sensors
- No need for interrupt hardware
- Absolute position value
- Very low price
- Very simple to mount

In the case of the <span class="simple">Simple<span class="foc">FOC</span>library</span> ([version 1.2.0](https://github.com/askuric/Arduino-FOC/releases)) we support SPI and ABI interface to the magnetic sensors. Please [let us know](contact) if you would be interested in having hte I2C interface implemented as well. 

Examples  | Description | Link | Price
---- | ---- | ---- | ----
[<img src="extras/Images/mag.jpg"  style="height:100px">](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) | Margetic encoder <br> AS5047<br> absolute <br>16384cpr |  [Mouser](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) | 15$
[<img src="extras/Images/mag2.jpg"  style="height:100px">](https://www.ebay.com/itm/AS5048-Magnetic-Encoder-PWM-SPI-Interface-14-Bit-Precision-For-Brushless-Motor/153636871434?hash=item23c5789d0a:g:oOMAAOSwd-5ddaWQ) | Magnetic encoder <br> AS5048<br> absolute <br>16384cpr |  [Ebay](https://www.ebay.com/itm/AS5048-Magnetic-Encoder-PWM-SPI-Interface-14-Bit-Precision-For-Brushless-Motor/153636871434?hash=item23c5789d0a:g:oOMAAOSwd-5ddaWQ) | 10$

