---
layout: default
title: Encoders
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /encoder
nav_order: 1
parent: Position Sensors
grand_parent: Code
---


## Encoder setup
To initialise the encoder you need to provide the encoder `A` and `B` channel pins, encoder `PPR` and optionally `index` pin.
```cpp
//  Encoder(int encA, int encB , int cpr, int index)
//  - encA, encB    - encoder A and B pins
//  - ppr           - impulses per rotation  (cpr=ppr*4)
//  - index pin     - (optional input)
Encoder encoder = Encoder(2, 3, 8192, A0);
```
Next important feature of the encoder is enabling or disabling the `Quadrature` more. If the Encoder is run in the quadratue more its number of impulses per rotation(`PPR`) is quadrupled by detecting each `CHANGE` of the signals `A` and `B` - `CPR = 4xPPR`. In some applicaitons, when the encoder `PPR` is high it can be too much for the Arudino to handle so it is preferable not to use `Quadrature` mode. By default all the encoders use `Quadrature` mode. If you would like to enable or disable this paramter do it in the Arduino setup funciton by running:
```cpp
// check if you need internal pullups
//  Quadrature::ENABLE - CPR = 4xPPR  - default
//  Quadrature::DISABLE - CPR = PPR
encoder.quadrature = Quadrature::ENABLE;
```
Additionally the encoder has one more important parameters which is whether you want to use Arduino's internal pullup or you have external one. That is set by changing the value of the `encoder.pullup` variuable. The default value is set to `Pullup::EXTERN`
```cpp
// check if you need internal pullups
// Pullup::EXTERN - external pullup added  - dafault
// Pullup::INTERN - needs internal arduino pullup
encoder.pullup = Pullup::EXTERN;
```
### Encoder interrupt configuration
There are two ways you can run encoders with Simple FOC libtrary.
- Using Arduino hardware external interrupt - for Arduino UNO pins  `2` and `3` 
- Using software pin chnage interrupt by using a library such as [PciManager library](https://github.com/prampec/arduino-pcimanager)

> Using the hardware external interrupts usualy results in a bit better and more realible performance but software interrupts will work very good as well. 

#### Arduino Hardware external interrupt
Arduino UNO has two hadrware external interrupt pins, pin `2` and `3`. And in order to use its functionallities the encoder channels `A` and `B` will have to be connected exacly on these pins.

Simple FOC `Encoder` class already has implemented initialisation and encoder `A` and `B` channel callbacks. 
All you need to do is define two funcitons `doA()` and `doB()`, the buffering functions of encoder callback funcitons `encoder.handleA()` and `encoder.handleB()`. 
```cpp
// interrupt ruotine intialisation
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}
```
And supply those functions to the encoder interrupt init fucntion `encoder.enableInterrupts()`
```cpp
// enable encoder hardware interrupts
encoder.enableInterrupts(doA, doB)
```
You can name the buffering funcitons as you wish. It is just important to supply them to the `encoder.init()` funciton. This procedure is a tradeoff in between scalability and simplicity. This allows you to have more than one encoder connected to the same arduino. All you need to do is to instantiate new `Encoder` class and create new buffer functions. For example:
```cpp
// encoder 1
Encoder enc1 =  Encoder(...);
void doA1(){enc1.handleA();}
void doB1(){enc1.handleB();}
// encoder 2
Encoder enc2 =  Encoder(...);
void doA2(){enc2.handleA();}
void doB2(){enc2.handleB();}

void setup(){
...
  enc1.init();
  enc1.enableInterrupts(doA1,doB1);
  enc2.init();
  enc2.enableInterrupts(doA2,doB2);
...
}
```

##### Index pin configuration
In order to read index pin efficienlty Simple FOC algorithm enables you to use the same approach as for the channels `A` and `B`. First you need to provide the `Encoder` class the index pin number:
```cpp
Encoder encoder = Encoder(pinA, pinB, cpr, index_pin);
```
If you are using Arduino board such as Arduino Mega and simialar and if you have more tha 2 hadrware interrupts you can connect your index pin to the hadrware interrupt pin (example Arduino Mega pin `21`). Your code will look like:
```cpp
Encoder encoder =  Encoder(2,3,600,A0);
// A and B interrupt rutine 
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}
void doIndex(){encoder.handleIndex();}

void setup(){
  ...
  encoder.enableInterrupts(doA,doB,doIndex);
  ...
  }
```
The function `enableInterrupts` will handle all the intialisation for you. 
If yo are using Arduino UNO to run this algorithm and you do not have enough hardware interrupt pins you will need to use software interrupt library such as  [PciManager library](https://github.com/prampec/arduino-pcimanager). Arduino UNO code for using an encoder with index can be:
```cpp
Encoder encoder =  Encoder(2,3,600,A0);
// A and B interrupt rutine 
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}
void doIndex(){encoder.handleIndex();}

// softaware interrupt listener for index pin
PciListenerImp listenerIndex(encoder.index_pin, doIndex);

void setup(){
  ...
  // hardware interrupts for A and B
  encoder.enableInterrupts(doA,doB);
  // software interrupt for index
  PciManager.registerListener(&listenerIndex);
  ...
  }
```
The same procedure can be done for pins `A` and `B` if your application makes you run out of the hardware interrupt pins. Software interrupts are very powerfull and produce very comparable results to the hardware interupts, but in general they tend to have a bit worse performance. `index` pin produces an interrupt once per rotation, therefore it is not critical, so software or hardware interrupt doesn't change too much in terms of performance. 

To explore better the encoder algorithm an example is provided `encoder_example.ino`.

#### Arduino software pin change interrupt
If you are not able to access your pins `2` and `3` of your Arduino UNO or if you want to use more than none encoder you will have to use the software interrupt approach. 
I suggest using the [PciManager library](https://github.com/prampec/arduino-pcimanager).

The stps of using this library in code are very similar to [harware interrupt](#arduino-hardware-external-interrupt).
The SimpleFOC `Encoder` class still provides you with all the callbacks `A`, `B` and `Index` channels but the Simple FOC library will not initialise the interrupts for you. 

In order to use the `PCIManager` library you will need to include it in your code:
```cpp
#include <PciManager.h>
#include <PciListenerImp.h>
```
Next step is the same as before, you will just intialise the new `Encoder` instance.
```cpp
Encoder encoder = Encoder(10, 11, 8192);
// A and B interrupt callback buffers
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}
```
Then you declare listeners `PciListenerImp `:
```cpp
// encoder interrupt init
PciListenerImp listenerA(encoder.pinA, doA);
PciListenerImp listenerB(encoder.pinB, doB);
```
Finally, after running `encoder.init()` you skip the call of the `encoder.enableInterrupts()` and call the `PCIManager` library to register the interrupts for all the encoder channels.
```cpp
// initialise encoder hardware
encoder.init();
// interrupt intitialisation
PciManager.registerListener(&listenerA);
PciManager.registerListener(&listenerB);
```
And that is it, it is very simple. It if you wnat more than one encoder, you just initialise the new class instance, create the new `A` and `B` callbacks, intialise the new listeners. Here is a quick example:
```cpp
// encoder 1
Encoder enc1 =  Encoder(9, 10, 8192);
void doA1(){enc1.handleA();}
void doB1(){enc1.handleB();}
PciListenerImp listA1(enc1.pinA, doA1);
PciListenerImp listB1(enc1.pinB, doB1);

// encoder 2
Encoder enc2 =  Encoder(13, 12, 8192);
void doA2(){enc2.handleA();}
void doB2(){enc2.handleB();}
PciListenerImp listA2(enc2.pinA, doA2);
PciListenerImp listB2(enc2.pinB, doB2);

void setup(){
...
  // encoder 1
  enc1.init();
  PciManager.registerListener(&listA1);
  PciManager.registerListener(&listB1);
  // encoder 2
  enc2.init();
  PciManager.registerListener(&listA2);
  PciManager.registerListener(&listB2);
...
}
```
You can look into the `HMBGC_example.ino` ecxample to see this code in action. 
##### Index pin configuration
Enabling index pin in the case of the software interrupt is very simple. You just need to provide it to the `Encoder` class intialisation as additional parameter. 
```cpp
Encoder encoder = Encoder(pinA, pinB, cpr, index_pin);
```
Afterward you create the same type of callback buffering function as for `A` and `B` channels and using the `PCIManager` tools initialise and register the listener for the `index` channel as for the `A` and `B`. Here is a quick example:
xample:
```cpp
// class init
Encoder encoder =  Encoder(9, 10, 8192,11);
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}
void doIndex(){encoder.handleIndex();}
// listeners init
PciListenerImp listenerA(encoder.pinA, doA);
PciListenerImp listenerB(encoder.pinB, doB);
PciListenerImp listenerIndex(encoder.index_pin, doIndex);

void setup(){
...
  // enable the hardware
  enc1.init();
  // enable interrupt
  PciManager.registerListener(&listenerA);
  PciManager.registerListener(&listenerB);
  PciManager.registerListener(&listenerIndex);
...
}
```