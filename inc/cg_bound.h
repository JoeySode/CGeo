

#ifndef CGEO_BOUND_H_

#define CGEO_BOUND_H_


#include "cg_vec2.h"


// A rectangle represented by its left right top and bottom edges as float coordinates
typedef struct bound_t
{
    float left;
    float right;
    float top;
    float bottom;
} bound_t;


// The area of the bound
float cgBoundArea(const bound_t* b);

// The bound's center x value
float cgBoundCenterX(const bound_t* b);

// The bound's center y value
float cgBoundCenterY(const bound_t* b);

// The bound's diagonal length
float cgBoundDiagonal(const bound_t* b);

// The bound's diagonal length squared
float cgBoundDiagonalSqr(const bound_t* b);

// The height of the bound
float cgBoundHeight(const bound_t* b);

// The perimeter of the bound
float cgBoundPerimeter(const bound_t* b);

// The width of the bound
float cgBoundWidth(const bound_t* b);

// Sets the vec2 to the bound's center
void cgBoundCenter(vec2_t* result, const bound_t* b);

// Moves the bound so that its center is the given vec2
void cgBoundCenterAt(bound_t* b, const vec2_t* center);

// Initializes the bound so that its center is the given vec2 and its width and height are the given values
void cgBoundFromDimensions(bound_t* result, const vec2_t* center, float width, float height);

// Initializes the bound so that its edges are whichever vec2 is furthest in that direction
void cgBoundFromVecs(bound_t* result, const vec2_t* va, const vec2_t* vb);

// Sets the bound's height to the given value without moving its bottom bound
void cgBoundSetHeightB(bound_t* b, float height);

// Sets the bound's height to the given value without moving its center
void cgBoundSetHeightC(bound_t* b, float height);

// Sets the bound's height to the given value without moving its top bound
void cgBoundSetHeightT(bound_t* b, float height);

// Sets the bound's width to the given value without moving its center
void cgBoundSetWidthC(bound_t* b, float width);

// Sets the bound's width to the given value without moving its left bound
void cgBoundSetWidthL(bound_t* b, float width);

// Sets the bound's width to the given value without moving its right bound
void cgBoundSetWidthR(bound_t* b, float width);


#endif // CGEO_BOUND_H_
