---
layout: default
title: BLDC drivers
parent: Supported Hardware
nav_order: 2
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /bldc_drivers
---

# BLDC motor drivers
This library will be compatible with the most of the 3 phase BLDC motor drivers. Such as [<i class="fa fa-file"></i> L6234](https://www.st.com/en/motor-drivers/l6234.html), [<i class="fa fa-file"></i> DRV8305](https://www.ti.com/product/DRV8305), [<i class="fa fa-file"></i> DRV8313](https://www.ti.com/product/DRV8313)  or even [<i class="fa fa-file"></i> L293](http://www.ti.com/lit/ds/symlink/l293.pdf). 

At this moment, a low-cost BLDC driver board is still reasonably hard to find making our choice of hardware is quiet restricted. This is the one of the motivations to develop the <span class="simple">Simple<span class="foc">FOC</span>Shield</span>, a versatile and simple BLDC driver. Fortunately, the community is starting to gain momentum in this direction and it is probably a matter of time before BLDC motors become a standard in the hobby community as well.

Here are some BLDC driver boards that work with the library *off-the-shelf*. 

Examples | Description | Specifications | Link | Price
---- | ---- | ---- | ---
[<img src="extras/Images/hor_cad_shield.jpg" style="height:100px">](https://simplefoc.com/simplefoc_shield_product)| Arduino <span class="simple">Simple<span class="foc">FOC</span>Shield</span>| - L6234 chip <br> - 1 motor <br>- Arduino Shield <br> - Encoder Pullups | [More info](https://simplefoc.com/simplefoc_shield_product) | 20€
[<img src="extras/Images/l6234.jpg" style="height:100px">](https://www.ebay.com/itm/L6234-Breakout-Board/153204519965?hash=item23abb3741d:g:LE4AAOSwe35bctgg) | Drotek L6234<br> breakout board | - L6234 chip <br> - 1 motor <br> - 25x25mm | [Drotek](https://store-drotek.com/212-brushless-gimbal-controller-l6234.html)<br> [Ebay](https://www.ebay.fr/itm/L6234-Breakout-Board-/153204519965) | 30€

Alternatively, you can find gimbal controller boards with integrated BLDC drivers and microcontroller chips such as HMBGC V2.2 and BGC 3.0 similar boards.

Examples | Description | Specifications | Link | Price
---- | ---- | ---- | ---
[<img src="extras/Images/pinout.jpg" style="height:100px">](https://www.ebay.com/itm/HMBGC-V2-0-3-Axle-Gimbal-Controller-Control-Plate-Board-Module-with-Sensor/351497840990?hash=item51d6e7695e:g:BAsAAOSw0QFXBxrZ:rk:1:pf:1) | HMBGC V2.2 | - 4599 mosfet<br> - 2 motors  <br> - 50x30mm <br> - Atmega328 | [Ebay](https://www.ebay.com/itm/HMBGC-V2-0-3-Axle-Gimbal-Controller-Control-Plate-Board-Module-with-Sensor/351497840990?hash=item51d6e7695e:g:BAsAAOSw0QFXBxrZ:rk:1:pf:1) | 20€
[<img src="extras/Images/bgc_30.jpg" style="height:100px">](https://fr.aliexpress.com/item/4000411471994.html?spm=a2g0o.productlist.0.0.5d047d57y4zGC4&algo_pvid=861ada4b-b12f-4019-be84-fae9870a12ed&algo_expid=861ada4b-b12f-4019-be84-fae9870a12ed-1&btsid=0ab6f83a15906954691168349e30d7&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_) | BGC 3.0 | - 4599 mosfet<br> - 2 motors  <br> - 50x50mm <br> - Atmega328 | [Aliexpress](https://fr.aliexpress.com/item/4000411471994.html?spm=a2g0o.productlist.0.0.5d047d57y4zGC4&algo_pvid=861ada4b-b12f-4019-be84-fae9870a12ed&algo_expid=861ada4b-b12f-4019-be84-fae9870a12ed-1&btsid=0ab6f83a15906954691168349e30d7&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_) | 10€

