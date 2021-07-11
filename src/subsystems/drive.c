#include "subsystems/drive.h"


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
  /*
  // reset angle
  sPos.Ang = 0;

  // reset last enc values
  lstBck = 0;
  lstLft = 0;
  lstRgt = 0;

  // reset current pos
  sPos.x = 0;
  sPos.y = 0;*/
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
