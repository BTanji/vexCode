#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <math.h>

// position and angle
typedef struct Pos {
  float x;
  float y;
  float Ang;
} _pos;

// polar coord
typedef struct Polar {
  float Ang;
  float radius;
} _polar;

// 2d vector
typedef struct vector {
  float x;
  float y;
} _vector;

// 2d line
typedef struct Line {
  _vector p1;
  _vector p2;
} _line;

//change polar coords to vectors
void polarTovectors(_polar pol, _vector vec);

//chhange vectors to polar coords
void vectorTopolar(_vector vec, _polar pol);

//find angle of line
float lineAngle(_line lin);

//find length of line
float lineLength(_line lin);

//conversion of angles
float radToDeg(float rad);
float degToRad(float deg);

#endif
