---
layout: default
title: Position Sensors
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /sensors
nav_order: 1
parent: Code
has_children: True
---

# Position Sensors 
This library supports two types of position sensors: 
- [Encoder](encoder)    
    - optical (ex. [AMT103 CUI](https://www.mouser.fr/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFaduiAsBlScvLoAWHUnKz39jAIpNPVt58AQ0PVb84dpbt53g%3D%3D))
    - magnetic (ex. [AS5047U](https://www.mouser.fr/ProductDetail/ams/AS5X47U-TS_EK_AB?qs=sGAEpiMZZMve4%2FbfQkoj%252BBDLPCj82ZLyYIPEtADg0FE%3D) - using ABI)
- [Magnetic sensor (AS5048/47)](magnetic_sensor).
    - SPI interface (ex. [AS5048A](https://www.ebay.com/itm/AS5048-Magnetic-Encoder-PWM-SPI-Interface-14-Bit-Precision-For-Brushless-Motor/153636871434?hash=item23c5789d0a:g:oOMAAOSwd-5ddaWQ))

Both classes of sensors are implemented in generic way in order to support as many of their versions as possible