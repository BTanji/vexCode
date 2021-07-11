#include "subsystems/pid.h"

void setPID(_pid c, float kp, float ki, float kd)
{
  c.kp = kp;
  c.ki = ki;
  c.kd = kd;
}

//get PID constant values (debugging)
float getKp(_pid c){
  return c.kp;
}
float getKi(_pid c){
  return c.ki;
}
float getKd(_pid c){
  return c.kd;
}

float getError(float curVal, float desVal){
  //find error
  return desVal - curVal;
}

float getP(_pid c, float error){
  c.p = error*c.kp;  //find power based on proportioned value
  if(c.p > 100){c.p = 100;}
  if(c.p < -100){c.p = -100;}
  return c.p;
}

float getI(_pid c, float error){
  c.i = (c.i +error)*c.ki;  //find power based on accumalated error
  if(error == 0){c.i = 0;}
  if(c.i > integralLimit){c.i = integralLimit;}
  return c.i;
}

float getD(_pid c, float error, float pastError){
  c.d = (error - pastError)*c.kd;
  return c.d;
}

float getOutput(_pid c, int power, float error)
{
  //add up all pid values
    output = getP(c, c.error) + getI(c, c.error) + getD(c, c.error, c.pastError);
    if(output > 127){output = 127;}
    if(output < -127){output = -127;}
    c.pastError = error;
    return output;
}
