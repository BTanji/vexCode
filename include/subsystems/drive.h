#ifndef DRIVE_H_
#define DRIVE_H_

#include "stdbool.h"
#include "subsystems/utilities.h"
#include "API.h"

extern Encoder rgtEnc;
extern Encoder lftEnc;
extern Encoder bckEnc;

extern _pos sPos;

extern float bckToMid;
extern float sideToMid;

extern float angToEnc;

// circumfrence of wheel / encoder ticks per rotation
extern float EncToInches;
extern float QEncToInches;

// change in ang
extern float DeltaAngle;

// for robot position tracking
extern float L;
extern float R;
extern float B;

extern float lstLft;
extern float lstRgt;
extern float lstBck;

extern float halfAng;
extern float hRL;
extern float hB;

// desired drive positions for auto
extern float desiredPos;
extern float desiredAng;

extern float followDist;
extern float followAng;

// desired drive power
extern int DesPower;

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
void trackPos();

//drive control task
void driveTask();

#endif
