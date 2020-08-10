---
layout: default
title: Position Sensors
nav_order: 3
parent: Supported Hardware
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /position_sensors
grand_parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
---

# Position sensors
The library currently supports ([version 1.3.1](https://github.com/askuric/Arduino-FOC/releases)) two types of position sensors: 
- [Encoder](#encoders) 
- [Magnetic sensor](#magnetic-sensors--spi--interface).
- *Hall sensors (in development)*
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
<p class="heading">Encoder CPR: Rule of thumb for Arduino UNO</p>
For Arduino UNO, the maximum number of pulses/second should not exceed 20,000. After this value it start to have execution issues. 
Please take this in consideration when choosing the encoder and especially if using more than one motor.<br>
<p class="heading">Example</p>
If your CPR value is 10000, you will be able to spin your motor with max velocity 120rpm - 2 rotations/second 
</blockquote>

      
## Magnetic sensors
Magnetic position sensor has many benefits over the encoders:
- Very efficient position calculation ( no counting ) 
- Time of execution doesn't depend on velocity or number of sensors
- No need for interrupt hardware
- Absolute position value
- Lower price then encoders
- Simple to mount

Magnetic sensors usually come with several different communication protocols:
- ABI (✔️ supported) - *exactly the same as the encoder interface* 
- SPI (✔️ supported)
- I2C (✔️ supported)
- PWM
- SSI 
- Analog (not suitable for FOC)
- UVW (needs a lot of fine tuning - not suggested)

PWM and SSI protocol will be tested for their performance and implemented in following steps. 
Please [let us know](contact) if you would be interested in having some other communication implemented!

Here are some of the supported magnetic sensors:

Examples  | Description | Link | Price
---- | ---- | ---- | ----
[<img src="extras/Images/mag.jpg"  style="height:100px">](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) | AS5047<br> SPI/ABI/PWM/UVW <br> 14bit |  [Mouser](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) | 15$
[<img src="extras/Images/mag2.jpg"  style="height:100px">](https://www.ebay.com/itm/AS5048-Magnetic-Encoder-PWM-SPI-Interface-14-Bit-Precision-For-Brushless-Motor/153636871434?hash=item23c5789d0a:g:oOMAAOSwd-5ddaWQ) | AS5048A<br> SPI/PWM <br> absolute <br> 14bit |  [Ebay](https://www.ebay.com/itm/AS5048-Magnetic-Encoder-PWM-SPI-Interface-14-Bit-Precision-For-Brushless-Motor/153636871434?hash=item23c5789d0a:g:oOMAAOSwd-5ddaWQ) | 10$
[<img src="extras/Images/as5600.jpg"  style="height:100px">](https://www.ebay.com/itm/1PC-New-AS5600-magnetic-encoder-sensor-module-12bit-high-precision/303401254431?hash=item46a41fbe1f:g:nVwAAOSwTJJd8zRK) | AS5600 <br> I2C/PWM <br> 12bit | [Ebay](https://www.ebay.com/itm/1PC-New-AS5600-magnetic-encoder-sensor-module-12bit-high-precision/303401254431?hash=item46a41fbe1f:g:nVwAAOSwTJJd8zRK) | 5$ 


<blockquote class="warning"><p class="heading">I2C Pull-ups</p>
Not all the I2C buses need pull-ups. But in some cases they might be necessary. Especially when using STM32 boards. In those cases, you will not be able to communicate with the sensor. 
To enable communication usually 4.7kOhm resistors will be needed in between 5V/3.3V and SCL and SDA channels. Here is a good stack overflow question about this issue :<a href="https://electronics.stackexchange.com/questions/102611/what-happens-if-i-omit-the-pullup-resistors-on-i2c-lines"> link </a>. 
<br>
In the future versions of the <span class="simple">Simple<span class="foc">FOC</span>Shield</span> I will try to include those pullups as well.
</blockquote>