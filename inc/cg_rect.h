

#ifndef CGEO_RECT_H_

#define CGEO_RECT_H_


#include "cg_vec2.h"


// A 2D rectangle using float to store its x and y position and its width (w) and height(h)
// (x, y) is the bottom left corner of the rect
typedef struct rect_t
{
  float x;
  float y;
  float w;
  float h;
}
rect_t;


// The area of the rectangle
float cgRectArea(const rect_t* r);

// The rectangle's center x
float cgRectCenterX(const rect_t* r);

// The rectangle's center y
float cgRectCenterY(const rect_t* r);

// The length of the rectangle's diagonal
float cgRectDiagonal(const rect_t* r);

// The length of the rectangle's diagonal squared
float cgRectDiagonalSqr(const rect_t* r);

// The perimeter of the rectangle
float cgRectPerimeter(const rect_t* r);

// Sets the vec2 to the rectangle's center
void cgRectCenter(vec2_t* result, const rect_t* r);

// Moves the rectangle so that it is centered at the given vec2
void cgRectCenterAt(rect_t* r, const vec2_t* center);


#endif // CGEO_RECT_H_
