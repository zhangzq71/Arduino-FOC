/*
    Odrive robotics' hardware is one of the best  BLDC motor foc supporting hardware out there.

    This is an example code that can be directly uploaded to the Odrive usind the SWD programmer. 
    This code uses an encoder with 500 cpr and a BLDC motor with 7 pole pairs connected to the M0 interface of the Odrive. 

    This is a short template code and the idea is that you are able to adapt to your needs not to be a complete solution. :D 
*/
#include <SimpleFOC.h>

// Odrive M0 motor pinout
#define M0_INH_A PA8
#define M0_INH_B PA9
#define M0_INH_C PA10
#define M0_INL_A PB13
#define M0_INL_B PB14
#define M0_INL_C PB15
// M0 currnets
#define M0_IB PC0
#define M0_IC PC1
// Odrive M0 encoder pinout
#define M0_ENC_A PB4
#define M0_ENC_B PB5


// Odrive M1 motor pinout
#define M1_INH_A PC6
#define M1_INH_B PC7
#define M1_INH_C PC8
#define M1_INL_A PA7
#define M1_INL_B PB0
#define M1_INL_C PB1
// M0 currnets
#define M1_IB PC2
#define M1_IC PC3
// Odrive M1 encoder pinout
#define M1_ENC_A PB6
#define M1_ENC_B PB7

// M1 & M2 common enable pin
#define EN_GATE PB12


// Motor instance
BLDCMotor motor = BLDCMotor(7);
BLDCDriver6PWM driver = BLDCDriver6PWM(M0_INH_A,M0_INL_A, M0_INH_B,M0_INL_B, M0_INH_C,M0_INL_C, EN_GATE);

// instantiate the commander
Commander command = Commander(Serial);
void doMotor(char* cmd) { command.motor(&motor, cmd); }


Encoder encoder = Encoder(M0_ENC_A, M0_ENC_B, 500);
// Interrupt routine intialisation
// channel A and B callbacks
void doA(){encoder.handleA();}
void doB(){encoder.handleB();}

void setup(){

  // pwm frequency to be used [Hz]
  driver.pwm_frequency = 20000;
  // power supply voltage [V]
  driver.voltage_power_supply = 20;
  // Max DC voltage allowed - default voltage_power_supply
  driver.voltage_limit = 20;
  // driver init
  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // initialize encoder sensor hardware
  encoder.init();
  encoder.enableInterrupts(doA, doB); 
  // link the motor to the sensor
  motor.linkSensor(&encoder);
  
  // control loop type and torque mode 
  motor.torque_controller = TorqueControlType::voltage;
  motor.controller = MotionControlType::torque;

  // max voltage  allowed for motion control 
  motor.voltage_limit = 8.0;
  // alignment voltage limit
  motor.voltage_sensor_align = 0.5;
  

  Serial.begin(115200);
  // comment out if not needed
  motor.useMonitoring(Serial);
  motor.monitor_downsample = 0; // disable monitoring at start

  // add target command T
  command.add('M', doMotor, "motor M0");

  // initialise motor
  motor.init();
  // init FOC  
  motor.initFOC();  
  delay(1000);
}
void loop(){
  // foc loop
  motor.loopFOC();
  // motion control
  motor.move();
  // monitoring 
  motor.monitor();
  // user communication
  command.run();
}