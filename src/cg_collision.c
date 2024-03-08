
#include "cg_collision.h"

#include "cg_def.h"
#include "cg_util.h"


bool cgCollBoundBound(const bound_t* ba, const bound_t* bb)
{
    return (ba->left <= bb->right) && (ba->right >= bb->left) && (ba->bottom <= bb->top) && (ba->top >= bb->bottom);
}

bool cgCollBoundCirc(const bound_t* b, const circ_t* c)
{
    // The difference in position from the circle's center to the closest point withint the rect
    float dx = cgClamp(c->x, b->left, b->right) - c->x;
    float dy = cgClamp(c->y, b->bottom, b->top) - c->y;

    // Return true if the distance is at most the circle's radius
    return cgSumSqr(dx, dy) <= c->r * c->r;
}

bool cgCollBoundRect(const bound_t* b, const rect_t* r)
{
    return (b->left <= r->x + r->w) && (b->right >= r->x) && (b->bottom <= r->y + r->h) && (b->top >= r->y);
}

bool cgCollBoundVec(const bound_t* b, const vec2_t* v)
{
    return (b->left <= v->x) && (b->right >= v->x) && (b->bottom <= v->y) && (b->top >= v->y);
}

bool cgCollCircCirc(const circ_t* ca, const circ_t* cb)
{
    float dx = ca->x - cb->x;
    float dy = ca->y - cb->y;

    float sum_r = ca->r + cb->r;

    return cgSumSqr(dx, dy) <= sum_r * sum_r;
}

bool cgCollCircRect(const circ_t* c, const rect_t* r)
{
    // The difference in position from the circle's center to the closest point withint the rect
    float dx = cgClamp(c->x, r->x, r->x + r->w) - c->x;
    float dy = cgClamp(c->y, r->y, r->y + r->h) - c->y;

    // Return true if the distance is at most the circle's radius
    return cgSumSqr(dx, dy) <= c->r * c->r;
}

bool cgCollCircVec(const circ_t* c, const vec2_t* v)
{
    float dx = c->x - v->x;
    float dy = c->y - v->y;

    return cgSumSqr(dx, dy) <= c->r * c->r;
}

bool cgCollRectRect(const rect_t* ra, const rect_t* rb)
{
    return (ra->x <= rb->x + rb->w) && (ra->x + ra->w >= rb->x) && (ra->y <= rb->y + rb->h) && (ra->y + ra->h >= rb->y);
}

bool cgCollRectVec(const rect_t* r, const vec2_t* v)
{
    return (r->x <= v->x) && (r->x + r->w >= v->x) && (r->y <= v->y) && (r->y + r->h >= v->y);
}
