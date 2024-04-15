

#include "cg_rect.h"

#include <math.h>


float cgRectArea(const rect_t* r)
{
  return r->w * r->h;
}

float cgRectCenterX(const rect_t* r)
{
  return r->x + (r->w / 2.0f);
}

float cgRectCenterY(const rect_t* r)
{
  return r->y + (r->h / 2.0f);
}

float cgRectDiagonal(const rect_t* r)
{
  return sqrtf((r->w * r->w) + (r->h * r->h));
}

float cgRectDiagonalSqr(const rect_t* r)
{
  return (r->w * r->w) + (r->h * r->h);
}

float cgRectPerimeter(const rect_t* r)
{
  return 2.0f * (r->w + r->h);
}

void cgRectCenter(vec2_t* result, const rect_t* r)
{
  result->x = r->x + (r->w / 2.0f);
  result->y = r->y + (r->h / 2.0f);
}

void cgRectCenterAt(rect_t* r, const vec2_t* center)
{
  r->x = center->x - (r->w / 2.0f);
  r->y = center->y - (r->h / 2.0f);
}
