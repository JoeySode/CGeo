
#ifndef CGEO_VEC2_H_

#define CGEO_VEC2_H_


#include <stdbool.h>


// A 2D vector class using floats to store its x and y values
typedef struct
{
    float x;
    float y;
} vec2_t;


#define CG_VEC2_ZERO    (vec2_t){ 0.0f, 0.0f };
#define CG_VEC2_ONE     (vec2_t){ 1.0f, 1.0f };

#define CG_VEC2_LEFT    (vec2_t){ -1.0f, 0.0f };
#define CG_VEC2_RIGHT   (vec2_t){ 1.0f, 0.0f };
#define CG_VEC2_DOWN    (vec2_t){ 0.0f, -1.0f };
#define CG_VEC2_UP      (vec2_t){ 0.0f, 1.0f };


// The angle in radians of the vec2
float cgVecAngle(const vec2_t* v);

// The angle in radians between the first vec2 and the second
float cgVecAngleTo(const vec2_t* va, const vec2_t* vb);

// The cross product of the vec2s
float cgVecCross(const vec2_t* va, const vec2_t* vb);

// The distance between the two vec2s
float cgVecDistance(const vec2_t* va, const vec2_t* vb);

// The manhattan distance between the vec2s
float cgVecDistanceMan(const vec2_t* va, const vec2_t* vb);

// The distance between the two vec2s squared
float cgVecDistanceSqr(const vec2_t* va, const vec2_t* vb);

// The dot product of the vec2s
float cgVecDot(const vec2_t* va, const vec2_t* vb);

// The magnitude of the vec2
float cgVecMagnitude(const vec2_t* v);

// The magnitude of the vec2 squared
float cgVecMagnitudeSqr(const vec2_t* v);

// True if the vec2's magnitude is zero (less than or equal to CG_EPSILON), otherwise false
bool cgVecIsZero(const vec2_t* v);

// Initializes the vec2 from a given direction (degrees radians) and magnitude
void cgVecFrom(vec2_t* result, float direction, float magnitude);

// Lerps the first vec2 to the second by the given value t
void cgVecLerp(vec2_t* v, const vec2_t* target, float t);

// Normalizes the vec2. Does nothing if the vec2's magnitude is 0
void cgVecNormalize(vec2_t* v);

// Normalizes the vec2, disregarding divide-by-0 safety. Only use if the vec2's magnitude is for sure not 0
void cgVecNormalizeZ(vec2_t* v);

// Rotates the vec2 the given degrees radians around (0, 0)
void cgVecRotate(vec2_t* v, float angle);

// Rotates the first vec2 the given degrees radians aroung the second
void cgVecRotateAround(vec2_t* v, const vec2_t* origin, float angle);

// Sets the first vec2 to the seconds's sine and cosine values. Does nothing if the second vec2's magnitude is 0
void cgVecSinCos(vec2_t* result, const vec2_t* v);

// Sets the first vec2 to the seconds's sine and cosine values, disregarding divide by 0 safety. Only use if the vec2's magnitude is for sure not 0
void cgVecSinCosZ(vec2_t* result, const vec2_t* v);


#endif // CGEO_VEC2_H_
