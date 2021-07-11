#ifndef DRIVE_H_
#define DRIVE_H_

#include "stdbool.h"
//#include "subsystems/utilities.h"
#include "API.h"

Encoder rgtEnc;
Encoder lftEnc;
Encoder bckEnc;

float bckToMid = 9.0;
float sideToMid = 7.5;

float angToEnc = 0.8064;

// circumfrence of wheel / encoder ticks per rotation
float EncToInches = (4.1 * 3.1415926535) / 900.0;
float QEncToInches = (4.1 * 3.1415926535) / 360.0;

// change in ang
float DeltaAngle = 0;

// for robot position tracking
float L = 0;
float R = 0;
float B = 0;

float lstLft = 0;
float lstRgt = 0;
float lstBck = 0;

float halfAng = 0;
float hRL = 0;
float hB = 0;

// desired drive positions for auto
float desiredPos;
float desiredAng;

float followDist;
float followAng;

// desired drive power
int DesPower;

//get back encoder values
int getBckPosition();

//get back encoder values in inches
float getBckPosInches();

//get left wheel encoder values
float getLeftPos();

//get left wheel encoder values in inches
float getLeftPosInches();

//get right wheel encoder values
float getRightPos();

//get right wheel encoder values in inches
float getRightPosInches();

//reset robot position
void resetRobotPos();

//reset all compoenets of drive (motor, sensors, values)
void resetDrive();

//set power to drive motor
void moveDrive(int lft, int rgt);

//stop drive motor
void stopDrive();

//find position of robot in space using encoders
void trackPos(int lft, int rgt, int bck);

//drive control task
void driveTask();

#endif
