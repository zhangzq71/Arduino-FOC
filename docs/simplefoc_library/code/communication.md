---
layout: default
title: Communication
parent: Using the Code
nav_order: 6
permalink: /communication
grand_parent: Arduino <span class="simple">Simple<span class="foc">FOC</span>library</span>
---


# Communication functionality
```cpp
/**
 * Function setting the configuration parameters  of the motor, target value of the control loop
 * and outputing them to the monitoring port( if available ) :
 * - configure PID controller constants
 * - change motion control loops
 * - monitor motor variabels
 * - set target values
 * - check all the configuration values 
 * 
 * To check the config value just enter the command letter.
 * For example: 
 * - to read velocity PI controller P gain run: P
 * - to set velocity PI controller P gain  to 1.2 run: P1.2
 * 
 * To change the target value just enter a number in the terminal:
 * For example: 
 * - to change the target value to -0.1453 enter: -0.1453
 * - to get the current target value enter: V3 
 * 
 * List of commands:
 *  - P: velocity PI controller P gain
 *  - I: velocity PI controller I gain
 *  - L: velocity PI controller voltage limit
 *  - R: velocity PI controller voltage ramp
 *  - F: velocity Low pass filter time constant
 *  - K: angle P controller P gain
 *  - N: angle P controller velocity limit
 *  - C: control loop 
 *    - 0: voltage 
 *    - 1: velocity 
 *    - 2: angle
 *  - V: get motor variables
 *    - 0: currently set voltage
 *    - 1: current velocity
 *    - 2: current angle
 *    - 3: current target value
 *
 * - Look into the documentation (docs.simplefoc.com) for more information.
 * 
 * @param command String containing the user command
 * 
 * returns 0 for error or 1 for executed command
 */
int BLDCMotor::command(String user_command) {
  // error flag
  int errorFlag = 1;
  // parse command letter
  char cmd = user_command.charAt(0);
  // check if get command
  char GET = user_command.charAt(1) == '\n';
  // parse command values
  float value = user_command.substring(1).toFloat();

  // apply the the command
  switch(cmd){
    case 'P':      // velocity P gain change
      if(monitor_port) monitor_port->print("PI velocity P: ");
      if(!GET) PI_velocity.P = value;
      if(monitor_port) monitor_port->println(PI_velocity.P);
      break;
    case 'I':      // velocity I gain change
      if(monitor_port) monitor_port->print("PI velocity I: ");
      if(!GET) PI_velocity.I = value;
      if(monitor_port) monitor_port->println(PI_velocity.I);
      break;
    case 'L':      // velocity voltage limit change
      if(monitor_port) monitor_port->print("PI velocity voltage limit: ");
      if(!GET)PI_velocity.voltage_limit = value;
      if(monitor_port) monitor_port->println(PI_velocity.voltage_limit);
      break;
    case 'R':      // velocity voltage ramp change
      if(monitor_port) monitor_port->print("PI velocity voltage ramp: ");
      if(!GET) PI_velocity.voltage_ramp = value;
      if(monitor_port) monitor_port->println(PI_velocity.voltage_ramp);
      break;
    case 'F':      // velocity Tf low pass filter change
      if(monitor_port) monitor_port->print("LPF velocity time constant: ");
      if(!GET) LPF_velocity.Tf = value;
      if(monitor_port) monitor_port->println(LPF_velocity.Tf);
      break;
    case 'K':      // angle loop gain P change
      if(monitor_port) monitor_port->print("P angle P value: ");
      if(!GET) P_angle.P = value;
      if(monitor_port) monitor_port->println(P_angle.P);
      break;
    case 'N':      // angle loop gain velocity_limit change
      if(monitor_port) monitor_port->print("P angle velocity limit: ");
      if(!GET) P_angle.velocity_limit = value;
      if(monitor_port) monitor_port->println(P_angle.velocity_limit);
      break;
    case 'C':
      // change control type
      if(monitor_port) monitor_port->print("Contoller type: ");
      
      if(GET){ // if get commang
        switch(controller){
          case ControlType::voltage:
            if(monitor_port) monitor_port->println("voltage");
            break;
          case ControlType::velocity:
            if(monitor_port) monitor_port->println("velocity");
            break;
          case ControlType::angle:
            if(monitor_port) monitor_port->println("angle");
            break;
        }
      }else{ // if set command
        switch((int)value){
          case 0:
            if(monitor_port) monitor_port->println("voltage");
            controller = ControlType::voltage;
            break;
          case 1:
            if(monitor_port) monitor_port->println("velocity");
            controller = ControlType::velocity;
            break;
          case 2:
            if(monitor_port) monitor_port->println("angle");
            controller = ControlType::angle;
            break;
          default: // not valid command
            errorFlag = 0;
        }
      }
      break;
    case 'V':     // get current values of the state variables
        switch((int)value){
          case 0: // get voltage
            if(monitor_port) monitor_port->print("Uq: ");
            if(monitor_port) monitor_port->println(voltage_q);
            break;
          case 1: // get velocity
            if(monitor_port) monitor_port->print("Velocity: ");
            if(monitor_port) monitor_port->println(shaft_velocity);
            break;
          case 2: // get angle
            if(monitor_port) monitor_port->print("Angle: ");
            if(monitor_port) monitor_port->println(shaft_angle);
            break;
          case 3: // get angle
            if(monitor_port) monitor_port->print("Target: ");
            if(monitor_port) monitor_port->println(target);
            break;
          default: // not valid command
            errorFlag = 0;
        }
      break;
    default:  // target change
      if(monitor_port) monitor_port->print("Target : ");
      target = user_command.toFloat();
      if(monitor_port) monitor_port->println(target);
  }
  // return 0 if error and 1 if ok
  return errorFlag;
}

```