---
layout: default
title: BLDC motors
nav_order: 1
parent: Supported Hardware
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /bldc_motors
---

# BLDC motors 

The Field Oriented Control algorithm doesn't really change too much in between low KV (higher resistance ~10 Ohm) gimbal motors and high KV (lower resistance <1 Ohm ) high power motors. Therefore in general this library can be used with any 3 phase BLDC motor there is.

But, since this library does not implement current control loop ([version 1.2.0](https://github.com/askuric/Arduino-FOC/releases)) and since it is primarily intended to be used with low-cost, low-power [BLDC motor drivers](bldc_drivers) we suggest 
you to use it with gimbal motors with no more than 5Amp peak current. 

Here are some examples of the different price range motors that have been successfully tested with this library.

Examples | Description | Link | Price 
---- | ---- | ---- | ----
[<img src="extras/Images/mot.jpg" style="height:100px">](https://www.ebay.com/itm/iPower-Gimbal-Brushless-Motor-GBM4108H-120T-for-5N-7N-GH2-ILDC-Aerial-photo-FPV/254541115855?hash=item3b43d531cf:g:q94AAOSwPcVVo571) | IPower GBM4198H-120T | [Ebay](https://www.ebay.com/itm/iPower-Gimbal-Brushless-Motor-GBM4108H-120T-for-5N-7N-GH2-ILDC-Aerial-photo-FPV/252025852824?hash=item3aade95398:g:q94AAOSwPcVVo571:rk:2:pf:1&frcectupt=true) | 25$
 [<img src="extras/Images/mot2.jpg" style="height:100px">](https://www.ebay.com/itm/JMT-MT3508-380KV-Motor-Disk-Motor-for-Multi-axis-Aircraft-DIY-Quadcopter-Drone/263422397574?hash=item3d5532cc86:g:31oAAOSw11BcQs6V) | GARTT ML5010 300KV | [Ebay](https://www.ebay.com/itm/GARTT-ML5010-300KV-Brushless-Motor-For-T960-T810-RC-Multirotor-Quadcopter-MT-092/302082779179?hash=item465589682b:g:h00AAOSwmfhX44X2) | 30$
 [<img src="extras/Images/mot3.jpg" style="height:100px">](https://www.ebay.com/itm/Alloy-2208-90KV-Gimbal-Brushless-Motor-for-Gopro3-RC-Drone-Camera-100-200g/223195701385?hash=item33f7802089:g:cjUAAOSw1iVbyccJ) | 2208 90KV Gimbal motor | [Ebay](https://www.ebay.com/itm/Alloy-2208-90KV-Gimbal-Brushless-Motor-for-Gopro3-RC-Drone-Camera-100-200g/223195701385?hash=item33f7802089:g:cjUAAOSw1iVbyccJ) | 15$
 [<img src="extras/Images/bigger.jpg" style="height:100px">](https://www.onedrone.com/store/ipower-gbm5108-120t-gimbal-motor.html) | GBM5108-120T | [Onedrone](https://www.onedrone.com/store/ipower-gbm5108-120t-gimbal-motor.html) | 90$
 [<img src="extras/Images/big.jpg" style="height:100px">](https://fr.aliexpress.com/item/32483131130.html?spm=a2g0o.productlist.0.0.6ddd749fFd3u9E&algo_pvid=a67f2ec1-5341-4f97-ba3e-720e24f6c4fb&algo_expid=a67f2ec1-5341-4f97-ba3e-720e24f6c4fb-10&btsid=0b0a187915885172220541390e7eed&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_) | GBM8017-120T | [Aliexpress](https://fr.aliexpress.com/item/32483131130.html?spm=a2g0o.productlist.0.0.6ddd749fFd3u9E&algo_pvid=a67f2ec1-5341-4f97-ba3e-720e24f6c4fb&algo_expid=a67f2ec1-5341-4f97-ba3e-720e24f6c4fb-10&btsid=0b0a187915885172220541390e7eed&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_) | 150$

## Choice of motors  
Before running any BLDC motor with the <span class="simple">Simple<span class="foc">FOC</span>library</span> please make sure your hardware can handle the currents your motor requires. 

The simplest way to do it is by checking the motor phase resistance `R`. Either check the datasheet of your motor and search for the resistance value or measure it yourself using a multimeter. Then check the value of your power supply voltage `V_dc` and once when you have the values you can find the maximum current `I_max` value by calculating:
```cpp
I_max = V_dc/R
```
Finally check the value of the maximum current `I_max` with the datasheet of your driver board. If the `I_max` is too high you can lower the power supply voltage `V_dc` in order prevent too high peaks of the current. If you are not able to change your power supply voltage you can limit the voltage set to motor in software. 
<blockquote class="warning">
    <p class="heading">NOTE</p>
    The equation above calculates the worst case maximum current <code>I_max</code> and in most cases calculated <code>I_max</code> is higher than the actual value. Maximum current depends both of the motor hardware such as winding configuration and the control algorithm.  
</blockquote>