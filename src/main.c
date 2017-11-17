#pragma config(Sensor, in1,    powerExpander,  sensorAnalog)
#pragma config(Sensor, dgtl1,  autonomousToggle, sensorDigitalIn)
#pragma config(Motor,  port1,           mogoLeft,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           driveRightRear, tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           driveLeftRear, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port8,           driveLeftFront, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port9,           driveRightFront, tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port10,          mogoRight,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"
#include "NatLang_CORTEX.c"
#include "motion.c"
#include "user.c"
#include "auto.c"

void pre_auton(void){
	bStopTasksBetweenModes = true;
	//Establish slave and master motors
	slaveMotor(driveRightRear, driveRightFront);
	slaveMotor(mogoRight, mogoLeft);
	//Reset all encoders
	reset_I2C_sensors();
}
