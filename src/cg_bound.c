

#include "cg_bound.h"

#include <math.h>


float cgBoundArea(const bound_t* b)
{
  return cgBoundWidth(b) * cgBoundHeight(b);
}

float cgBoundCenterX(const bound_t* b)
{
  return (b->left + b->right) / 2.0f;
}

float cgBoundCenterY(const bound_t* b)
{
  return (b->bottom + b->top) / 2.0f;
}

float cgBoundDiagonal(const bound_t* b)
{
  float w = cgBoundWidth(b);
  float h = cgBoundHeight(b);

  return sqrtf((w * w) + (h * h));
}

float cgBoundDiagonalSqr(const bound_t* b)
{
  float w = cgBoundWidth(b);
  float h = cgBoundHeight(b);

  return (w * w) + (h * h);
}

float cgBoundHeight(const bound_t* b)
{
  return b->top - b->bottom;
}

float cgBoundPerimeter(const bound_t* b)
{
  return 2.0f * (cgBoundWidth(b) + cgBoundHeight(b));
}

float cgBoundWidth(const bound_t* b)
{
  return b->right - b->left;
}

void cgBoundCenter(vec2_t* result, const bound_t* b)
{
  result->x = cgBoundCenterX(b);
  result->y = cgBoundCenterY(b);
}

void cgBoundCenterAt(bound_t* b, const vec2_t* center)
{
  float half_w = cgBoundWidth(b) / 2.0f;
  float half_h = cgBoundHeight(b) / 2.0f;

  b->left = center->x - half_w;
  b->right = center->x + half_w;

  b->bottom = center->y - half_h;
  b->top = center->y + half_h; 
}

void cgBoundFromDimensions(bound_t* result, const vec2_t* center, float width, float height)
{
  float half_w = width / 2.0f;
  float half_h = height / 2.0f;

  result->left = center->x - half_w;
  result->right = center->x + half_w;

  result->bottom = center->y - half_h;
  result->top = center->y + half_h;
}

void cgBoundFromVecs(bound_t* result, const vec2_t* va, const vec2_t* vb)
{
  if (va->x < vb->x)
  {
    result->left = va->x;
    result->right = vb->y;
  }
  else
  {
    result->left = vb->x;
    result->right = va->y;
  }

  if (va->y < vb->y)
  {
    result->bottom = va->y;
    result->top = vb->y;
  }
  else
  {
    result->bottom = vb->y;
    result->top = va->y;
  }
}

void cgBoundSetHeightB(bound_t* b, float height)
{
  b->top = b->bottom + height;
}

void cgBoundSetHeightC(bound_t* b, float height)
{
  float half_h = height / 2.0f;
  float cy = cgBoundCenterY(b);

  b->bottom = cy - half_h;
  b->top = cy + half_h;
}

void cgBoundSetHeightT(bound_t* b, float height)
{
  b->bottom = b->top - height;
}

void cgBoundSetWidthC(bound_t* b, float width)
{
  float half_w = width / 2.0f;
  float cx = cgBoundCenterX(b);

  b->left = cx - half_w;
  b->right = cx + half_w;
}

void cgBoundSetWidthL(bound_t* b, float width)
{
  b->right = b->left + width;
}

void cgBoundSetWidthR(bound_t* b, float width)
{
  b->left = b->right - width;
}
