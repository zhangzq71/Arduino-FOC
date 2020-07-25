# SimpleFOC sensor testing branch - Magnetic Sensor 

![MinimalBuild](https://github.com/askuric/Arduino-FOC/workflows/MinimalBuild/badge.svg?branch=minimal)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![arduino-library-badge](https://www.ardu-badge.com/badge/Simple%20FOC.svg?)](https://www.ardu-badge.com/badge/Simple%20FOC.svg)

This is the minimal Arduino example of the [Simple FOC](https://github.com/askuric/Arduino-FOC) arduino library intended for testing the sensor implementation in the development stage.

### Minimal repository structure
```shell
├───motion_control_example    # Full motion control example code to test magnetic sensors 
│
└───sensor_test_minimal   # Magnetic sensor minimal code to test SPI and I2C communication
```


#### Motor control example
You will be able to change the PI velocity parameters `P` and `I`, Low pass filter time constant `Tf`, change the control loop in real time and check the average loop execution time, all from the serial terminal. 

List of commands:
- **P**: velocity PI controller P gain
- **I**: velocity PI controller I gain
- **L**: velocity PI controller voltage limit
- **R**: velocity PI controller voltage ramp
- **F**: velocity Low pass filter time constant
- **K**: angle P controller P gain
- **N**: angle P controller velocity limit
- **C**: control loop 
  - **0**: voltage 
  - **1**: velocity 
  - **2**: angle
- **V**: get motor variables
  - **0**: currently set voltage
  - **1**: current velocity
  - **2**: current angle
  - **3**: current target value


Find more information about the **motor commands** in the [docs.simplefoc.com](https://docs.simplefoc.com/communication)

#### Github website download
- Download the code by clicking on the `Clone or Download > Download ZIP`.
- Unzip it and open the sketch in Arduino IDE. 

#### Using terminal
- Open the terminal:
  ```sh
  cd *to you desired directory*
  git clone -b test_sensors https://github.com/askuric/Arduino-FOC.git
  ```
- Then you just open it with the Arduino IDE and run it.

> **NOTE**
> In some cases this branch will not be compatible with the SimpleFOC library and you will need to remove your SimpleFOC library from the Arduino libraries folder. 

## Documentation
Find out more information about the Arduino SimpleFOC project in [docs website](https://askuric.github.io/Arduino-FOC/) 


## Arduino FOC repo structure
Branch  | Description | Status
------------ | ------------- | ------------ 
[master](https://github.com/askuric/Arduino-FOC) | Stable and tested library version | ![Library Compile](https://github.com/askuric/Arduino-FOC/workflows/Library%20Compile/badge.svg)
[dev](https://github.com/askuric/Arduino-FOC/tree/dev) | Development library version | ![Library Dev Compile](https://github.com/askuric/Arduino-FOC/workflows/Library%20Dev%20Compile/badge.svg?branch=dev)
[minimal](https://github.com/askuric/Arduino-FOC/tree/minimal) | Minimal Arduino example with integrated library | ![MinimalBuild](https://github.com/askuric/Arduino-FOC/workflows/MinimalBuild/badge.svg?branch=minimal)
