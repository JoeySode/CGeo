

#ifndef CGEO_UTIL_H_

#define CGEO_UTIL_H_


// The first value clamped between the given minimum and maximum
#define CG_CLAMP(n, min, max) (((n) <= (min)) ? (min) : ((n) >= (max)) ? (max) : (n))

// The largest of the two values
#define CG_MAX(a, b) (((a) >= (b)) ? (a) : (b))

// The smallest of the two values
#define CG_MIN(a, b) (((a) <= (b)) ? (a) : (b))

// The sum of the squares of the two numbers
#define CG_SUM_SQRS(a, b) ((a) * (a)) + ((b) * (b))


#endif // CGEO_UTIL_H_
