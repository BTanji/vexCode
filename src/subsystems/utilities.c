#include "subsystems/utilities.h"

void polarTovectors(_polar pol, _vector vec) {
  vec.x = pol.radius * cos(pol.Ang);
  vec.y = pol.radius * sin(pol.Ang);
}

void vectorTopolar(_vector vec, _polar pol) {
  pol.Ang = atan2f(vec.y, vec.x);
  pol.radius = sqrtf(vec.x * vec.x + vec.y * vec.y);
}

float lineAngle(_line lin) {
  float difY = (lin.p2.y - lin.p1.y);
  float difX = (lin.p2.x - lin.p1.x);
  return atan2(difX, difY);
}

float lineLength(_line lin) {
  float difY = (lin.p2.y - lin.p1.y);
  float difX = (lin.p2.x - lin.p1.x);
  return sqrtf((difX * difX) + (difY * difY));
}

float radToDeg(float rad) { return (rad * 180) / 3.1415; }

float degToRad(float deg) { return (deg * 3.1415) / 180; }
