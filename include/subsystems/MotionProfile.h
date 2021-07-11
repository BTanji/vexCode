#ifndef MOTIONPROFILE_H_
#define MOTIONPROFILE_H_

typedef struct PhysBot
{
  int pos;
  int vel;
  int acc;
}_PhysBot;

//get robot velocity through motion profile
void getProfile(_PhysBot p, int desPos, int desAcc, int cruiseVel);

#endif
