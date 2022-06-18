<<<<<<< HEAD
#pragma config(Sensor, in1,    claw,           sensorPotentiometer)
#pragma config(Sensor, dgtl1,  button,         sensorTouch)
#pragma config(Sensor, dgtl9,  sFront,         sensorSONAR_mm)
#pragma config(Sensor, dgtl11, sBack,          sensorSONAR_mm)
#pragma config(Motor,  port1,           mDrive,        tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           mArm,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           mClaw,         tmotorVex393_MC29, openLoop)
=======
#pragma config(Sensor, dgtl1, button, sensorTouch)
#pragma config(Sensor, dgtl11, range, sensorSONAR_mm)
#pragma config(Motor, port1, drive1, tmotorVex393_HBridge, openLoop)
#pragma config(Motor, port2, drive2, tmotorVex393_MC29, openLoop)
>>>>>>> main
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define WHEEL_SPEED 100
#define ARM_SPEED 100
#define CLAW_SPEED 100
#define CLAW_DISTANCE 20

enum SystemPhase {
	idle,
	moveFore,
	pickup,
	moveBack,
	egg
};
SystemPhase phase = idle;

task main() {
	int fore;
	int aft;

	while(true){
		fore = SensorValue[sFront];
		aft = SensorValue[sBack];

		switch (phase) {
			case idle:
				idlePhase();
				break;

			case moveFore:
				if (SensorValue[range] == CLAW_DISTANCE) {
					stopTask(moveForePhase);
					++phase;
				}
				break;

			case pickup:
				pickupPhase();
				break;

			case moveBack:
				startTask(moveBackPhase);
				break;

			case makeEgg:
				eggPhase();
				break;
		}
	}
}
