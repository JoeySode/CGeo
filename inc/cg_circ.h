

#ifndef CGEO_CIRC_H_

#define CGEO_CIRC_H_


#include "cg_vec2.h"


// A circle using float to represent its x and y potision and its radius
// (x, y) is the center of the circle
typedef struct circ_t
{
  float x;
  float y;
  float r;
}
circ_t;


// The area of the circle
float cgCircArea(const circ_t* c);

// The diameter of the circle
float cgCircleDiameter(const circ_t* c);

// The perimeter of the circle
float cgCircPerimeter(const circ_t* c);

// Sets the vec2 to the angle on the circle's edge the given angle in radians from its center
void cgCircPointAtAngle(vec2_t* result, const circ_t* c, float angle);


#endif // CGEO_CIRC_H_
