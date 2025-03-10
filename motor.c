#include "xc.h"
#include "motor.h"
#include "misc.h"

//stepper motor functions

#define PS LATEbits.LATE0
#define PHASE1 LATEbits.LATE1
#define PHASE2 LATEbits.LATE2
#define PHASE3 LATEbits.LATE3
#define PHASE4 LATEbits.LATE4
//etc...

//we want one step and one step only (one signal is changed, not both)

//1-16
//17-32
//33-48
//49-64

void motor_stepFeeder() { //only deals with feeding motor
	//one "step" is one phase shift?
	//or is one "step" the whole sequence A+ B+ A- B-?
	if (PHASE1 == 1) {
		if (PHASE2 == 1) {
			PHASE1 = 0;
		} else {
			PHASE2 = 1;
		}
	} else {
		if (PHASE2 == 1) {
			PHASE2 = 0;
		} else {
			PHASE1 = 1;
		}
	}
}

void motor_stepCutterDown() { //only deals with feeding motor
	//one "step" is one phase shift?
	//or is one "step" the whole sequence A+ B+ A- B-?
	if (PHASE3 == 1) {
		if (PHASE4 == 1) {
			PHASE3 = 0;
		} else {
			PHASE4 = 1;
		}
	} else {
		if (PHASE4 == 1) {
			PHASE4 = 0;
		} else {
			PHASE3 = 1;
		}
	}
}

void motor_stepCutterUp() {
	if (PHASE3 == 1) {
		if (PHASE4 == 1) {
			PHASE4 = 0;
		} else {
			PHASE3 = 0;
		}
	} else {
		if (PHASE4 == 1) {
			PHASE3 = 1;
		} else {
			PHASE4 = 1;
		}
	}
}

void motor_stepFeeder(int steps) {
	for (int i = 0; i < steps; i++) {
		motor_stepFeeder();
        //delay_ms(250); //crucial delay
						 //very exaggerated for testing purposes
	}
}

static float wheel_radius = .3;//in cm
static float step_angle = 1.8; //in degrees
								//from "SM_42BYG011-25"
static float dps = step_angle * wheel_radius; //distance per step

void motor_feed(int distance) { //distance in centimeters, can only be int input
	float dps = step_angle * wheel_radius;
	int steps = distance / dps; //dps = distance/step;
	motor_stepFeeder(steps);
}

static float cutting_distance = 10; //distance knife will travel

void motor_cut() {
	int numSteps = cutting_distance / dps;
	for (int i = 0; i < numSteps; i++) {
		motor_stepCutterDown();
		//delay_ms(100); //shorter delay for faster cutting speed
	}
	
	for (int i = 0; i < numSteps; i++) {
		motor_stepCutterUp();
		//delay_ms(200); //slightly relaxed journey back to resting position
	}
}