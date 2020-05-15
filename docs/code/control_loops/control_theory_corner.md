---
layout: default
title: Control Theory Corner
parent: Control loops
grand_parent: Code
description: "Arduino Simple Field Oriented Control (FOC) library ."
nav_order: 5
permalink: /control_theory_corner
---

 
# Control theory lovers corner


## PI controller theory
Transfer function of the PI controller this library implements is:

<p><img src="./extras/Images/cont_PI.png" /></p>

Continuos PI is transformed to the discrete domain using Tustin transformation. The final discrete equation becomes:

<p><img src="./extras/Images/dis_PI.png" /></p>

Where the <i>u(k)</i> is the control signal (voltage <i>U<sub>q</sub></i> in our case) in moment <i>k</i>, <i>e(k),e(k-1)</i> is the tracking error in current moment <i>k</i> and previous step <i>k-1</i>. Tracking error presents the difference in between the target velocity value <i>v<sub>d</sub></i> and measured velocity <i>v</i>. 

<p><img src="./extras/Images/track.png" /></p>

## Low-Pass velocity filter theory
Transfer function of the Low pass filter is controller is:

<p><img src="./extras/Images/cont_LPF.png" /></p>
In it discrete form it becomes:

<p><img src="./extras/Images/dis_LPF.png" /></p>

where <i>v<sub>f</sub>(k)</i> is filtered velocity value in moment <i>k</i>, <i>v(k)</i> is the measured velocity in the moment <i>k</i>, <i>T<sub>f</sub></i> is the filter time constant and <i>T<sub>s</sub></i> is the sampling time (or time in between executions of the equation).
This low pass filter can be also written in the form:

<p><img src="./extras/Images/LPF_alpha.png" /></p>

where:

<p><img src="./extras/Images/alpha.png" /></p>

This makes it a bit more clear what the time constant `Tf` of the Low pass filter stands for. If your sample time is around 1millisecond (for arduino UNO this can be taken as an average) then setting the
`Tf` value to `Tf = 0.01` will result in:

```cpp
alpha = 0.01/(0.01 + 0.001) = 0.91
```

Which means that your actual velocity measurement <i>v</i> will influence the filtered value <i>v<sub>f</sub><i> with the coefficient `1-alpha = 0.09` which is going to smooth the velocity values considerably (maybe even too much, depends of the application).

