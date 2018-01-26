#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    aclX,           sensorAccelerometer)
#pragma config(Sensor, in3,    aclY,           sensorAccelerometer)
#pragma config(Sensor, in4,    aclZ,           sensorAccelerometer)
#pragma config(Sensor, in8,    powerExpander,  sensorAnalog)
#pragma config(Sensor, dgtl9,  resetLED,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, resetButton,    sensorTouch)
#pragma config(Sensor, dgtl12, autonomousToggle, sensorDigitalIn)
#pragma config(Sensor, I2C_1,  armLiftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  driveRightEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  driveLeftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           mobileGoalRight, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           driveRightRear, tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port3,           driveLeftFront, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           armLeftSplit,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           coneIntake,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           armLift,       tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port7,           armRightSplit, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           driveRightFront, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port9,           driveLeftRear, tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, I2C_3)
#pragma config(Motor,  port10,          mobileGoalLeft, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

void resetAll(void);

#include "Vex_Competition_Includes.c"
#include "NatLang_CORTEX.c"
#include "motion.c"
#include "pos.c"
#include "user.c"
#include "auto.c"

void pre_auton(void){
	bStopTasksBetweenModes = true;
	resetAll();
}

void resetAll(void){
	//Reset sensors
	setHome();
	reset_I2C_sensors();
	//Establish slave and master motors
	slaveMotor(driveRightFront, driveRightRear);
	slaveMotor(driveLeftFront, driveLeftRear);
	slaveMotor(mobileGoalRight, mobileGoalLeft);
}
