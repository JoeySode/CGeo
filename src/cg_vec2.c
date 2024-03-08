
#include "cg_vec2.h"

#include "cg_def.h"
#include "cg_util.h"

#include <math.h>


float cgVecAngle(const vec2_t* v)
{
    return atan2f(v->y, v->x);
}

float cgVecAngleTo(const vec2_t* va, const vec2_t* vb)
{
    return atan2f(vb->y - va->y, vb->x - va->x);
}

float cgVecCross(const vec2_t* va, const vec2_t* vb)
{
    return (va->x * vb->y) - (va->y * vb->x);
}

float cgVecDistance(const vec2_t* va, const vec2_t* vb)
{
    float dx = va->x - vb->x;
    float dy = va->y - vb->y;

    return sqrtf(cgSumSqr(dx, dy));
}

float cgVecDistanceMan(const vec2_t* va, const vec2_t* vb)
{
    return fabsf(va->x - vb->x) + fabsf(va->y - vb->y);
}

float cgVecDistanceSqr(const vec2_t* va, const vec2_t* vb)
{
    float dx = va->x - vb->x;
    float dy = va->y - vb->y;

    return cgSumSqr(dx, dy);
}

float cgVecDot(const vec2_t* va, const vec2_t* vb)
{
    return (va->x * vb->x) + (va->y * vb->y);
}

float cgVecMagnitude(const vec2_t* v)
{
    return sqrtf((v->x * v->x) + (v->y * v->y));
}

float cgVecMagnitudeSqr(const vec2_t* v)
{
    return (v->x * v->x) + (v->y * v->y);
}

bool cgVecIsZero(const vec2_t* v)
{
    return cgVecMagnitude(v) <= CG_EPSILON;
}

void cgVecFrom(vec2_t* result, float direction, float magnitude)
{
    result->x = magnitude * cosf(direction);
    result->y = magnitude * sinf(direction);
}

void cgVecLerp(vec2_t* v, const vec2_t* target, float t)
{
    v->x = (target->x - v->x) * t;
    v->y = (target->y - v->y) * t;
}

void cgVecNormalize(vec2_t* v)
{
    float mag = cgVecMagnitude(v);

    // Avoid dividing by 0
    if (mag <= CG_EPSILON)
        return;

    v->x /= mag;
    v->y /= mag;
}

void cgVecNormalizeZ(vec2_t* v)
{
    float mag = cgVecMagnitude(v);

    v->x /= mag;
    v->y /= mag;
}

void cgVecRotate(vec2_t* v, float angle)
{
    float c = cosf(angle);
    float s = sinf(angle);

    v->x = (v->x * c) - (v->y * s);
    v->y = (v->x * s) + (v->y * c);
}

void cgVecRotateAround(vec2_t* v, const vec2_t* origin, float angle)
{
    float c = cosf(angle);
    float s = sinf(angle);

    float dx = v->x - origin->x;
    float dy = v->y - origin->y;

    v->x = origin->x + (dx * c) - (dy * s);
    v->y = origin->y + (dy * s) + (dy * c);
}

void cgVecSinCos(vec2_t* result, const vec2_t* v)
{
    float mag = cgVecMagnitude(v);

    // Avoid dividing by 0
    if (mag <= CG_EPSILON)
        return;
    
    result->x = v->x / mag;
    result->y = v->y / mag;
}

void cgVecSinCosZ(vec2_t* result, const vec2_t* v)
{
    float mag = cgVecMagnitude(v);

    result->x = v->x / mag;
    result->y = v->y / mag;
}
