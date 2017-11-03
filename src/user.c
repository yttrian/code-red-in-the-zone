task usercontrol(){
	int DY, DT;
	bool armsLocked = false;
	//Disable PID
	setPIDforMotor(driveSplitLeft, false);
	setPIDforMotor(driveSplitRight, false);
	setPIDforMotor(liftRight, false);
	setPIDforMotor(armLeft, false);

	while(true){
		//Driving
		DY = threshold(PAIRED_CH2, 15) + (PAIRED_BTN8U * MAX_POWER) - (PAIRED_BTN8D * MAX_POWER);
		DT = threshold(PAIRED_CH1, 15) + (PAIRED_BTN8R * MAX_POWER) - (PAIRED_BTN8L * MAX_POWER);
		drive(DY, DT);

		//Pistons (toggle)
		if(PAIRED_BTN7R){
			pistons(!PISTON_POS);
			waitUntil(!PAIRED_BTN7R);
		}

		//Arms
		if(PAIRED_BTN7L){
			armsLocked = !armsLocked;
			waitUntil(!PAIRED_BTN7L);
		}
		if(armsLocked){
			arms(ARM_LOCK);
		} else {
			arms(threshold(PAIRED_CH3, 15) + ((PAIRED_BTN6U - PAIRED_BTN6D) * MAX_POWER));
		}

		//Lift
		lift((PAIRED_BTN7U - PAIRED_BTN7D) * MAX_POWER);

		//Intake
		intake((PAIRED_BTN5U - PAIRED_BTN5D) * MAX_POWER);
	}
}
