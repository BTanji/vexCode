#include "subsystems/drive.h"

Encoder rgtEnc;
Encoder lftEnc;
Encoder bckEnc;

_pos sPos;

float bckToMid = 9.0;
float sideToMid = 7.5;

float angToEnc = 0.8064;

// circumfrence of wheel / encoder ticks per rotation
float EncToInches = (4.1 * 3.1415926535) / 900.0;
float QEncToInches = (4.1 * 3.1415926535) / 360.0;

// change in ang
float DeltaAngle;

// for robot position tracking
float L;
float R;
float B;

float lstLft;
float lstRgt;
float lstBck;

float halfAng;
float hRL;
float hB;

// desired drive positions for auto
float desiredPos;
float desiredAng;

float followDist;
float followAng;

// desired drive power
int DesPower;

//get back encoder values
int getBckPos()
{
  return encoderGet(bckEnc);
}

//get back encoder values in inches
float getBckPosInches()
{
  return getBckPos()*EncToInches;
}

//get left wheel encoder values
float getLeftPos()
{
  return encoderGet(lftEnc);
}

//get left wheel encoder values in inches
float getLeftPosInches()
{
  return getLeftPos()*EncToInches;
}

//get right wheel encoder values
float getRightPos()
{
  return encoderGet(rgtEnc);
}

//get right wheel encoder values in inches
float getRightPosInches()
{
  return getRightPos()*EncToInches;
}

//reset robot position
void resetRobotPos()
{

  // reset angle
  sPos.Ang = 0;

  // reset last enc values
  lstBck = 0;
  lstLft = 0;
  lstRgt = 0;

  // reset current pos
  sPos.x = 0;
  sPos.y = 0;
}

//reset all compoenets of drive (motor, sensors, values)
void resetDrive()
{
  encoderReset(rgtEnc);
  encoderReset(lftEnc);
  encoderReset(bckEnc);

  desiredPos = 0; // reset desired positions
  desiredAng = 0;
  DesPower = 0;
}

void moveDrive(int lftPow, int rgtPow)
{
  // limti power to 100%
  if (lftPow > 127) {
    lftPow = 127;
  } else if (lftPow < -127) {
    lftPow = -127;
  }

  if (rgtPow > 127) {
    rgtPow = 127;
  } else if (rgtPow < -127) {
    rgtPow = -127;
  }

  motorSet(2, lftPow);
  motorSet(3, rgtPow);
}

void stopDrive()
{
  motorStop(2);
  motorStop(3);
}

//find position of robot in space using encoders
void trackPos()
{
}

//drive control task
void driveTask()
{
  trackPos();

}
