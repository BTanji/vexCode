#ifndef PID_H_
#define PID_H_

int integralLimit = 10000;
int output;

typedef struct PID
{
  float kp;
  float ki;
  float kd;

  float p;
  float i;
  float d;

  int error;
  int pastError;
}_pid;

//set pid values
void setPID(_pid c, float kp, float ki, float kd);

//get PID constant values (debugging)
float getKp(_pid c);
float getKi(_pid c);
float getKd(_pid c);

float getError(float curVal, float desVal);

//get p, i, and d values
float getP(_pid c, float error);
float getI(_pid c, float error);
float getD(_pid c, float error, float pastError);

//add up p, i, and d values to
float getOutput(_pid c, int power, float error);

#endif
