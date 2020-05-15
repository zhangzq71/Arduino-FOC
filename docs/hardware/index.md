---
layout: default
title: Hardware components
nav_order: 5
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /electrical_connections
has_children: True
---

#  <span class="simple">Simple<span class="foc">FOC</span>library</span> hardware components

The components you need to have in order to run any Field Oriented Control algorithm:

- [BLDC motor](#bldc-motor)
- [BLDC driver](#bldc-motor-driver)
- [Position sensor](#position-sensor)
- Arduino board 

Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>  is made modular and will support most of the hardware combinations out there. 

## BLDC motor 

This library is compatible with any 3 phase BLDC motor out there. Feel free to choose anything that suites your applications. The most tests have been done using gimbal motors (up to 2A).

Examples | Description | Link | Price 
---- | ---- | ---- | ----
[<img src="extras/Images/mot.jpg" style="height:100px">](https://www.ebay.com/itm/iPower-Gimbal-Brushless-Motor-GBM4108H-120T-for-5N-7N-GH2-ILDC-Aerial-photo-FPV/254541115855?hash=item3b43d531cf:g:q94AAOSwPcVVo571) | IPower GBM4198H-120T | [Ebay](https://www.ebay.com/itm/iPower-Gimbal-Brushless-Motor-GBM4108H-120T-for-5N-7N-GH2-ILDC-Aerial-photo-FPV/252025852824?hash=item3aade95398:g:q94AAOSwPcVVo571:rk:2:pf:1&frcectupt=true) | 25$
 [<img src="extras/Images/mot2.jpg" style="height:100px">](https://www.ebay.com/itm/JMT-MT3508-380KV-Motor-Disk-Motor-for-Multi-axis-Aircraft-DIY-Quadcopter-Drone/263422397574?hash=item3d5532cc86:g:31oAAOSw11BcQs6V) | GARTT ML5010 300KV | [Ebay](https://www.ebay.com/itm/GARTT-ML5010-300KV-Brushless-Motor-For-T960-T810-RC-Multirotor-Quadcopter-MT-092/302082779179?hash=item465589682b:g:h00AAOSwmfhX44X2) | 30$
 [<img src="extras/Images/mot3.jpg" style="height:100px">](https://www.ebay.com/itm/Alloy-2208-90KV-Gimbal-Brushless-Motor-for-Gopro3-RC-Drone-Camera-100-200g/223195701385?hash=item33f7802089:g:cjUAAOSw1iVbyccJ) | 2208 90KV Gimbal motor | [Ebay](https://www.ebay.com/itm/Alloy-2208-90KV-Gimbal-Brushless-Motor-for-Gopro3-RC-Drone-Camera-100-200g/223195701385?hash=item33f7802089:g:cjUAAOSw1iVbyccJ) | 15$
 
## BLDC motor driver 
This library will be compatible with the most of the 3 phase BLDC motor drivers. Such as L6234, DRV8305 or L293.  Alternatively, you can find gimbal controller boards with integrated BLDC drivers and microcontroller chips such as HMBGC V2.2 and similar boards.

Examples | Description | Link | Price
---- | ---- | ---- | ---
[<img src="extras/Images/shield_top_v13.png" style="height:100px">](https://askuric.github.io/simplefoc_shield_product)| Arduino Simple FOC shield | [More info](https://askuric.github.io/simplefoc_shield_product) | 35$
[<img src="extras/Images/l6234.jpg" style="height:100px">](https://www.ebay.com/itm/L6234-Breakout-Board/153204519965?hash=item23abb3741d:g:LE4AAOSwe35bctgg) | Dorotek L6234 breakout board| [Drotek](https://store-drotek.com/212-brushless-gimbal-controller-l6234.html), [Ebay](https://www.ebay.fr/itm/L6234-Breakout-Board-/153204519965) | 30$
[<img src="extras/Images/pinout.jpg" style="height:100px">](https://www.ebay.com/itm/HMBGC-V2-0-3-Axle-Gimbal-Controller-Control-Plate-Board-Module-with-Sensor/351497840990?hash=item51d6e7695e:g:BAsAAOSw0QFXBxrZ:rk:1:pf:1) | HMBGC V2.2 | [Ebay](https://www.ebay.com/itm/HMBGC-V2-0-3-Axle-Gimbal-Controller-Control-Plate-Board-Module-with-Sensor/351497840990?hash=item51d6e7695e:g:BAsAAOSw0QFXBxrZ:rk:1:pf:1) | 20$


## Position sensor
This library supports two types of position sensors: 
- [Encoder](#encoders) 
- [Magnetic sensor (AS5048/47)](#magnetic-sensors--spi--interface).

### Encoders
Encoders are by far most popular position sensors, both in industry and in hobby community. The main benefits are the precision, standardization and very low noise level. The main problem with encoders is the code efficiency, since you need to continuously count the impulses in order to have precise position.

Examples  | Description | Link | Price
---- | ---- | ---- | ----
[<img src="extras/Images/enc.jpg"  style="height:100px">](https://www.ebay.com/itm/360-600P-R-Photoelectric-Incremental-Rotary-Encoder-5V-24V-AB-Two-Phases-Shaft/254214673272?hash=item3b30601378:m:mDiuW1F2qXINSH51TqAjhTg)  | Optical encoder<br>2400cpr | [Ebay](https://www.ebay.fr/itm/L6234-Breakout-Board-/153204519965) | 10$
[<img src="extras/Images/enc1.png" style="height:100px">](https://www.ebay.com/itm/HMBGC-V2-0-3-Axle-Gimbal-Controller-Control-Plate-Board-Module-with-Sensor/351497840990?hash=item51d6e7695e:g:BAsAAOSw0QFXBxrZ:rk:1:pf:1) | Optical encoder<br>AMT103 <br>8192cpr |  [Mouser](https://www.mouser.fr/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFaduiAsBlScvLoAWHUnKz39jAIpNPVt58AQ0PVb84dpbt53g%3D%3D)  | 20$
[<img src="extras/Images/mag.jpg"  style="height:100px">](hhttps://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) | Margetic encoder <br> AS5047U <br> 16384cpr |  [Mouser](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D)<br> [Youtube demo](https://www.youtube.com/watch?v=Gl-DiOqXXJ8)   | 15$

      
### Magnetic sensors | SPI  interface
Magnetic position sensor has many benefits over the encoders:
- Very efficient position calculation ( no counting ) 
- Time of execution doesn't depend on velocity or number of sensors
- No need for interrupt hardware
- Absolute position value
- Very low price
- Very simple to mount

Examples  | Description | Link | Price
---- | ---- | ---- | ----
[<img src="extras/Images/mag.jpg"  style="height:100px">](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) | Margetic encoder <br> AS5047<br> absolute <br>16384cpr |  [Mouser](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) | 15$
[<img src="extras/Images/mag2.jpg"  style="height:100px">](https://www.ebay.com/itm/AS5048-Magnetic-Encoder-PWM-SPI-Interface-14-Bit-Precision-For-Brushless-Motor/153636871434?hash=item23c5789d0a:g:oOMAAOSwd-5ddaWQ) | Magnetic encoder <br> AS5048<br> absolute <br>16384cpr |  [Ebay](https://www.ebay.com/itm/AS5048-Magnetic-Encoder-PWM-SPI-Interface-14-Bit-Precision-For-Brushless-Motor/153636871434?hash=item23c5789d0a:g:oOMAAOSwd-5ddaWQ) | 10$

