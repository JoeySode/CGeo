
#ifndef CGEO_LSEG_H_

#define CGEO_LSEG_H_


#include "cg_vec2.h"

#include <stdbool.h>


// A line segment represented by 2 points (its two ends) as vec2s
typedef struct
{
  vec2_t a;
  vec2_t b;
}
lseg_t;

// The length of the line segment
float cgSegLength(const lseg_t* s);

// The manhattan length of the line segment
float cgSegLengthMan(const lseg_t* s);

// The length of the line segment squared
float cgSegLengthSqr(const lseg_t* s);

// Returns true if the given vec2 is within the line segment's x and y bounds, false if not
bool cgSegInBound(const lseg_t* s, const vec2_t* v);

// Returns true if the given x value is within the line segment's x bounds, false if not
bool cgSegInBoundX(const lseg_t* s, float x);

// Returns true if the given y value is within the line segment's y bounds, false if not
bool cgSegInBoundY(const lseg_t* s, float y);

// Initializes the line segment from the given vec2 and an extending direction (degrees radians) and magnitude
void cgSegFromExtension(lseg_t* result, const vec2_t* source, float direction, float magnitude);


#endif // CGEO_LSEG_H_
