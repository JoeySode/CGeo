

#ifndef CGEO_COLLISION_H_

#define CGEO_COLLISION_H_


#include <stdbool.h>

#include "cg_bound.h"
#include "cg_circ.h"
#include "cg_lseg.h"
#include "cg_rect.h"
#include "cg_vec2.h"


// True if the objects collide, false if not
bool cgCollBoundBound(const bound_t* ba, const bound_t* bb);

// True if the objects collide, false if not
bool cgCollBoundCirc(const bound_t* b, const circ_t* c);

// True if the objects collide, false if not
bool cgCollBoundRect(const bound_t* b, const rect_t* r);

// True if the objects collide, false if not
bool cgCollBoundVec(const bound_t* b, const vec2_t* v);

// True if the objects collide, false if not
bool cgCollCircCirc(const circ_t* ca, const circ_t* cb);

// True if the objects collide, false if not
bool cgCollCircRect(const circ_t* c, const rect_t* r);

// True if the objects collide, false if not
bool cgCollCircVec(const circ_t* c, const vec2_t* v);

// True if the objects collide, false if not
bool cgCollRectRect(const rect_t* ra, const rect_t* rb);

// True if the objects collide, false if not
bool cgCollRectVec(const rect_t* r, const vec2_t* v);


#endif // CGEO_COLLISION_H_
