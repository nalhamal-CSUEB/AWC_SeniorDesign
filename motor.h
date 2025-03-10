#ifndef MOTOR_H   /* Guard against multiple inclusion */
#define MOTOR_H

static float cutting_distance = 10; //distance knife will travel
static float wheel_radius = .3;//in cm
static float step_angle = 1.8; //in degrees
								//from "SM_42BYG011-25"
static float dps = step_angle * wheel_radius; //distance per step

void motor_stepFeeder();
void motor_stepCutterDown();
void motor_stepCutterUp();
void motor_stepFeeder(int steps);
void motor_feed(int distance);
void motor_cut();

#endif