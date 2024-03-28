
#include "cg_circ.h"

#include "cg_def.h"

#include <math.h>


float cgCircArea(const circ_t* c)
{
  return CG_PI * c->r * c->r;
}

float cgCircleDiameter(const circ_t* c)
{
  return 2.0f * c->r;
}

float cgCircPerimeter(const circ_t* c)
{
  return 2.0f * CG_PI * c->r;
}

void cgCircPointAtAngle(vec2_t* result, const circ_t* c, float angle)
{
  result->x = c->x + (c->r * cosf(angle));
  result->y = c->y + (c->r * sinf(angle));
}
