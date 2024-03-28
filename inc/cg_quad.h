
#ifndef CGEO_QUAD_H_

#define CGEO_QUAD_H_


#include "cg_rect.h"
#include "cg_vec2.h"


// A struct that represents an abnormal quad using 4 vec2s as points
typedef struct
{
  vec2_t a; // Bottom left corner of a rectangle
  vec2_t b; // Bottom right corner of a rectangle
  vec2_t c; // Top left corner of a rectangle
  vec2_t d; // Top right corner of a rectangle
}
quad_t;


// The perimeter of the quad
float cgQuadPerimeter(const quad_t* q);

// Sets the vec2 to the center (average) of the quad's points
void cgQuadCenter(vec2_t* result, const quad_t* q);

// Creates the quad from the given rectangle rotated by the angle in radians
void cgQuadFromRectRotated(quad_t* result, const rect_t* r, float angle);

// Rotates the quad's points the given angle in radians around (0, 0)
void cgQuadRotate(quad_t* q, float angle);

// Rotates the quad's points the given angle in radians around the vec2
void cgQuadRotateAround(quad_t* q, const vec2_t* origin, float angle);


#endif
