---
layout: default
title: PI controller theory
parent: Theory corner
grand_parent: Digging deeper
grand_grand_parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 1
permalink: /pi_controller
---

 
## PI controller theory
Transfer function of the PI controller this library implements is:

<p><img src="./extras/Images/cont_PI.png" /></p>

Continuos PI is transformed to the discrete domain using Tustin transformation. The final discrete equation becomes:

<p><img src="./extras/Images/dis_PI.png" /></p>

Where the <i>u(k)</i> is the control signal (voltage <i>U<sub>q</sub></i> in our case) in moment <i>k</i>, <i>e(k),e(k-1)</i> is the tracking error in current moment <i>k</i> and previous step <i>k-1</i>. Tracking error presents the difference in between the target velocity value <i>v<sub>d</sub></i> and measured velocity <i>v</i>. 

<p><img src="./extras/Images/track.png" /></p>
