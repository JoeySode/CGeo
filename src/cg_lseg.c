
#include "cg_lseg.h"

#include "cg_def.h"
#include "cg_util.h"

#include <math.h>


float cgSegLength(const lseg_t* s)
{
    return cgVecDistance(&s->a, &s->b);
}

float cgSegLengthMan(const lseg_t* s)
{
    return cgVecDistanceMan(&s->a, &s->b);
}

float cgSegLengthSqr(const lseg_t* s)
{
    return cgVecDistanceSqr(&s->a, &s->b);
}

bool cgSegInBound(const lseg_t* s, const vec2_t* v)
{
    return cgSegInBoundX(s, v->x) && cgSegInBoundY(s, v->y);
}

bool cgSegInBoundX(const lseg_t* s, float x)
{
    return x >= cgMin(s->a.x, s->b.x) && x <= cgMax(s->a.x, s->a.x);
}

bool cgSegInBoundY(const lseg_t* s, float y)
{
    return y >= cgMin(s->a.y, s->b.y) && y <= cgMax(s->a.y, s->a.y);
}

void cgSegFromExtension(lseg_t* result, const vec2_t* source, float direction, float magnitude)
{
    result->a = *source;

    result->b.x = source->x + (magnitude * cosf(direction));
    result->b.y = source->y + (magnitude * sinf(direction));
}
