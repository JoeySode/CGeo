
#include "cg_util.h"


float cgClamp(float n, float min, float max)
{
    if (n <= min) return min;
    if (n >= max) return max;
    return n;
}

float cgMax(float a, float b)
{
    return a >= b ? a : b;
}

float cgMin(float a, float b)
{
    return a <= b ? a : b;
}

float cgSumSqr(float a, float b)
{
    return (a * a) + (b * b);
}
