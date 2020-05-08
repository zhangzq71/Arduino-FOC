---
layout: default
title: <span class="simple">Simple<span class="foc">FOC</span>library</span> Installation
parent: Getting Started
nav_order: 1
description: "Arduino Simple Field Oriented Control (FOC) library ."
permalink: /library_download
---

# Installing <span class="simple">Simple<span class="foc">FOC</span>library</span>

## Arduino Library Manager 
The simplest way to get hold of the library is direclty by using Arduino IDE and its integrated Library Manager. 
- Open Arduino IDE and start Arduino Library Manager by clicking: `Tools > Manage Libraries...`.
- Serarch for `Simple FOC` library and install the lates version.
- Reopen Arduino IDE and you should have the library examples in `File > Examples > Simple FOC`.

## Installation from Github
If you don't want to use the Arduino IDE and Library manager you can direclty download the library from the [github repository](https://github.com/askuric/Arduino-FOC). 

### Using Github website 
- Go to the [github repository](https://github.com/askuric/Arduino-FOC)
- Click first on `Clone or Download > Download ZIP`. 
- Unzip it and place it in `Arduino Libraries` forlder. Windows: `Documents > Arduino > libraries`.  
- Reopen Arduino IDE and you should have the library examples in `File > Examples > Simple FOC`.

### Using terminal
- Open terminal and run
```sh  
cd *arduino libraries folder*
git clone https://github.com/askuric/Arduino-FOC.git
```
- Reopen Arduino IDE and you should have the library examples in `File > Examples > Simple FOC`.
