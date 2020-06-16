---
layout: default
title: Using the Code
nav_order: 6
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /code
has_children: True
has_toc: False
parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span> 
---

# Let's write the code

Once when you have your <span class="simple">Simple<span class="foc">FOC</span>library</span> [installed](installation) and you have all the necessary [hardware](supported_hardware),we can finally start the fun part, let's white the code and move the motor!

Let's start by including the library header file:
```c++
#include <SimpleFOC.h>
```
```cpp
#include <SimpleFOC.h>
```
Or if you have downloaded the [minimal example](minimal_download) you will include it this way:
```c++
#include "SimpleFOC.h"
```
```cpp
#include "SimpleFOC.h"
```

## Step 1. <a href="sensors" class="remove_dec">Position sensor</a>

First step when writing the code is initializing and configuring the position sensor.


Choose position sensor to use in this example:

<a href ="javascript:showMagnetic();" id="mag" class="btn btn-primary">Magnetic sensor</a> <a href="javascript:showEncoder();" id="enc" class="btn">Encoder</a> 

```cpp
#include <SimpleFOC.h>

// Encoder(pin_A, pin_B, PPR)
Encoder encoder = Encoder(2, 3, 2048);
// channel A and B callbacks
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}


void setup() {  
  // initialize encoder hardware
  encoder.init();
  // hardware interrupt enable
  encoder.enableInterrupts(doA, doB);

}

void loop() {
  
}
```

```c++
#include <SimpleFOC.h>

// MagneticSensor(int cs, float _cpr, int _angle_register)
MagneticSensor AS5x4x = MagneticSensor(10, 16384, 0x3FFF);

void setup() {
  // initialize magnetic sensor hardware
  AS5x4x.init();
}

void loop() {

}
```

<blockquote class="info"> <p class="heading">FULL DOCS: Position sensors</p>For full documentation of the setup and all configuration parameters please visit the <a href="sensors"> position sensors docs</a>. </blockquote>


## Step 2. <a href="motor_initialization" class="remove_dec"> BLDC motor</a>
Next step is initializing and configuring the BLDC motor.

```cpp
#include <SimpleFOC.h>

//  BLDCMotor( pin_pwmA, pin_pwmB, pin_pwmC, pole_pairs, enable (optional))
BLDCMotor motor = BLDCMotor(9, 5, 6, 11, 8);
//  Encoder(pin_A, pin_B, CPR)
Encoder encoder = Encoder(2, 3, 2048);
// channel A and B callbacks
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}


void setup() {  
  // initialize encoder hardware
  encoder.init();
  // hardware interrupt enable
  encoder.enableInterrupts(doA, doB);
  // link the motor to the sensor
  motor.linkSensor(&encoder);

  // set control loop type to be used
  motor.controller = ControlType::velocity;
  // initialize motor
  motor.init();

}

void loop() {

}
```

```c++
#include <SimpleFOC.h>

//  BLDCMotor( pin_pwmA, pin_pwmB, pin_pwmC, pole_pairs, enable (optional))
BLDCMotor motor = BLDCMotor(9, 5, 6, 11, 8);

// MagneticSensor(int cs, float _cpr, int _angle_register)
MagneticSensor AS5x4x = MagneticSensor(10, 16384, 0x3FFF);

void setup() {
  // initialize magnetic sensor hardware
  AS5x4x.init();
  // link the motor to the sensor
  motor.linkSensor(&AS5x4x);

  // set control loop type to be used
  motor.controller = ControlType::velocity;
  // initialize motor
  motor.init();

}

void loop() {

}
```

<blockquote class="info"> <p class="heading">FULL DOCS: BLDC motor</p>For full documentation of the setup and all configuration parameters please visit the <a href="motor_initialization"> BLDC motor docs</a>. </blockquote>


## Step 3.<a href="foc_routine" class="remove_dec"> FOC routine and real-time execution</a>
Finally, we initialize and configure the FOC algorithm and start the real-time execution.


```cpp
#include <SimpleFOC.h>

//  BLDCMotor( pin_pwmA, pin_pwmB, pin_pwmC, pole_pairs, enable (optional))
BLDCMotor motor = BLDCMotor(9, 5, 6, 11, 8);
//  Encoder(pin_A, pin_B, CPR)
Encoder encoder = Encoder(2, 3, 2048);
// channel A and B callbacks
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}


void setup() {  
  // initialize encoder hardware
  encoder.init();
  // hardware interrupt enable
  encoder.enableInterrupts(doA, doB);
  // link the motor to the sensor
  motor.linkSensor(&encoder);

  // set control loop type to be used
  motor.controller = ControlType::velocity;
  // initialize motor
  motor.init();

  // align encoder and start FOC
  motor.initFOC();
}

void loop() {
  // FOC algorithm function
  motor.loopFOC();

  // velocity control loop function
  // setting the target velocity or 2rad/s
  motor.move(2);
}
```

```c++
#include <SimpleFOC.h>

//  BLDCMotor( pin_pwmA, pin_pwmB, pin_pwmC, pole_pairs, enable (optional))
BLDCMotor motor = BLDCMotor(9, 5, 6, 11, 8);

// MagneticSensor(int cs, float _cpr, int _angle_register)
MagneticSensor AS5x4x = MagneticSensor(10, 16384, 0x3FFF);

void setup() {
  // initialize magnetic sensor hardware
  AS5x4x.init();
  // link the motor to the sensor
  motor.linkSensor(&AS5x4x);

  // set control loop type to be used
  motor.controller = ControlType::velocity;
  // initialize motor
  motor.init();

  // align encoder and start FOC
  motor.initFOC();
}

void loop() {
  // FOC algorithm function
  motor.loopFOC();

  // velocity control loop function
  // setting the target velocity or 2rad/s
  motor.move(2);
}
```

<blockquote class="info"> <p class="heading">FULL DOCS: FOC Algorithm </p>For full documentation of the setup and all configuration parameters please visit the <a href="foc_routine"> FOC algorithm docs</a>. </blockquote>


## Step 4. <a href="monitoring" class="remove_dec"> Monitoring</a>

```cpp
#include <SimpleFOC.h>

//  BLDCMotor( pin_pwmA, pin_pwmB, pin_pwmC, pole_pairs, enable (optional))
BLDCMotor motor = BLDCMotor(9, 5, 6, 11, 8);
//  Encoder(pin_A, pin_B, CPR)
Encoder encoder = Encoder(2, 3, 2048);
// channel A and B callbacks
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}


void setup() {  
  // initialize encoder hardware
  encoder.init();
  // hardware interrupt enable
  encoder.enableInterrupts(doA, doB);
  // link the motor to the sensor
  motor.linkSensor(&encoder);

  // use monitoring with the BLDCMotor
  Serial.begin(115200);
  // monitoring port
  motor.useMonitoring(Serial);

  // set control loop type to be used
  motor.controller = ControlType::velocity;
  // initialize motor
  motor.init();

  // align encoder and start FOC
  motor.initFOC();
}

void loop() {
  // FOC algorithm function
  motor.loopFOC();

  // velocity control loop function
  // setting the target velocity or 2rad/s
  motor.move(2);

  // monitoring function outputting motor variables to the serial terminal 
  motor.monitor();
}
```

```c++
#include <SimpleFOC.h>

//  BLDCMotor( pin_pwmA, pin_pwmB, pin_pwmC, pole_pairs, enable (optional))
BLDCMotor motor = BLDCMotor(9, 5, 6, 11, 8);

// MagneticSensor(int cs, float _cpr, int _angle_register)
MagneticSensor AS5x4x = MagneticSensor(10, 16384, 0x3FFF);

void setup() {
  // initialize magnetic sensor hardware
  AS5x4x.init();
  // link the motor to the sensor
  motor.linkSensor(&AS5x4x);

  // use monitoring with the BLDCMotor
  Serial.begin(115200);
  // monitoring port
  motor.useMonitoring(Serial);

  // set control loop type to be used
  motor.controller = ControlType::velocity;
  // initialize motor
  motor.init();

  // align encoder and start FOC
  motor.initFOC();
}

void loop() {
  // FOC algorithm function
  motor.loopFOC();

  // velocity control loop function
  // setting the target velocity or 2rad/s
  motor.move(2);

  // monitoring function outputting motor variables to the serial terminal 
  motor.monitor();
}
```

<blockquote class="info"> <p class="heading">FULL DOCS: Monitoring </p>For full documentation of the setup and all configuration parameters please visit the <a href="monitoring"> Monitoring docs</a>. </blockquote>


## Step 4. <a href="communication" class="remove_dec"> User Communication</a>

```cpp
#include <SimpleFOC.h>

//  BLDCMotor( pin_pwmA, pin_pwmB, pin_pwmC, pole_pairs, enable (optional))
BLDCMotor motor = BLDCMotor(9, 5, 6, 11, 8);
//  Encoder(pin_A, pin_B, CPR)
Encoder encoder = Encoder(2, 3, 2048);
// channel A and B callbacks
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}


void setup() {  
  // initialize encoder hardware
  encoder.init();
  // hardware interrupt enable
  encoder.enableInterrupts(doA, doB);
  // link the motor to the sensor
  motor.linkSensor(&encoder);

  // use monitoring with the BLDCMotor
  Serial.begin(115200);
  // monitoring port
  motor.useMonitoring(Serial);

  // set control loop type to be used
  motor.controller = ControlType::velocity;
  // initialize motor
  motor.init();

  // align encoder and start FOC
  motor.initFOC();
}

void loop() {
  // FOC algorithm function
  motor.loopFOC();

  // velocity control loop function
  // target set by user using motor.command()
  motor.move();

  // monitoring function outputting motor variables to the serial terminal 
  //motor.monitor(); // comment out the monitor - spamming the serial port
  
  // user communication
  serialReceiveUserCommand();
}

// utility function enabling serial communication function with the user
// user can set the target values and set/get the motor configuration using motor commands 
// see documentation for full command list 
// 
// this function can be implemented in serialEvent function as well
void serialReceiveUserCommand() {
  
  // a string to hold incoming data
  static String received_chars;
  
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the string buffer:
    received_chars += inChar;

    // end of user input
    if (inChar == '\n') {
      
      // execute the user command
      motor.command(received_chars);

      // reset the command buffer 
      received_chars = "";
    }
  }
}

```

```c++
#include <SimpleFOC.h>

//  BLDCMotor( pin_pwmA, pin_pwmB, pin_pwmC, pole_pairs, enable (optional))
BLDCMotor motor = BLDCMotor(9, 5, 6, 11, 8);

// MagneticSensor(int cs, float _cpr, int _angle_register)
MagneticSensor AS5x4x = MagneticSensor(10, 16384, 0x3FFF);

void setup() {
  // initialize magnetic sensor hardware
  AS5x4x.init();
  // link the motor to the sensor
  motor.linkSensor(&AS5x4x);

  // use monitoring with the BLDCMotor
  Serial.begin(115200);
  // monitoring port
  motor.useMonitoring(Serial);

  // set control loop type to be used
  motor.controller = ControlType::velocity;
  // initialize motor
  motor.init();

  // align encoder and start FOC
  motor.initFOC();
}

void loop() {
  // FOC algorithm function
  motor.loopFOC();

  // velocity control loop function
  // target set by user using motor.command()
  motor.move();

  // monitoring function outputting motor variables to the serial terminal 
  //motor.monitor(); // comment out the monitor - spamming the serial port
 
  // user communication
  serialReceiveUserCommand();
}

// utility function enabling serial communication function with the user
// user can set the target values and set/get the motor configuration using motor commands 
// see documentation for full command list 
// 
// this function can be implemented in serialEvent function as well
void serialReceiveUserCommand() {
  
  // a string to hold incoming data
  static String received_chars;
  
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the string buffer:
    received_chars += inChar;

    // end of user input
    if (inChar == '\n') {
      
      // execute the user command
      motor.command(received_chars);

      // reset the command buffer 
      received_chars = "";
    }
  }
}

```

<blockquote class="info"> <p class="heading">FULL DOCS: Communication </p>For full documentation of the setup and all configuration parameters please visit the <a href="communication"> Communication docs</a>. </blockquote>


<script type="text/javascript">
    var elems = document.getElementsByClassName('language-cpp');
    for (i = 0; i < elems.length; i++) {
        elems[i].style.display = "none";
    }

    function showMagnetic(){
        document.getElementById("enc").classList.remove("btn-primary");
        document.getElementById("mag").classList.add("btn-primary");
        var elems = document.getElementsByClassName('language-cpp');
        for (i = 0; i < elems.length; i++) {
            elems[i].style.display = "none";
        } 
        var elems = document.getElementsByClassName('language-c++');
        for (i = 0; i < elems.length; i++) {
            elems[i].style.display = "block";
        } 
        return 0;
    }

    function showEncoder(){
        document.getElementById("mag").classList.remove("btn-primary");
        document.getElementById("enc").classList.add("btn-primary");
        var elems = document.getElementsByClassName('language-cpp');
        for (i = 0; i < elems.length; i++) {
            elems[i].style.display = "block";
        } 
        var elems = document.getElementsByClassName('language-c++');
        for (i = 0; i < elems.length; i++) {
            elems[i].style.display = "none";
        } 
        return 0;
    }
</script>

## Arduino Uno interactive sketch

<div class="image_icon" style="width:100%" >
    <a href="interactive_example" >
        <img src="extras/Images/interactive_example.png" >
        <i class="fa fa-external-link-square fa-2x"></i>
    </a>
</div>


## Library source code
If you are interested in extending and adapting the <span class="simple">Simple<span class="foc">FOC</span>library</span> source code you can find full documentation on [library source docs](source_code)