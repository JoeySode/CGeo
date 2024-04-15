

#include "cg_quad.h"

#include <math.h>


float cgQuadPerimeter(const quad_t* q)
{
  return cgVecDistance(&q->a, &q->b) + cgVecDistance(&q->b, &q->c) + cgVecDistance(&q->c, &q->d) + cgVecDistance(&q->d, &q->a);
}

void cgQuadCenter(vec2_t* result, const quad_t* q)
{
  result->x = (q->a.x + q->b.x + q->c.x + q->d.x) / 4.0f;
  result->y = (q->a.y + q->b.y + q->c.y + q->d.y) / 4.0f;
}

void cgQuadFromRect(quad_t* result, const rect_t* r)
{
  const float left = r->x;
  const float right = r->x + r->w;
  const float bottom = r->y;
  const float top = r->y + r->h;

  result->a = (vec2_t){ left, bottom };
  result->b = (vec2_t){ left, top };
  result->c = (vec2_t){ right, top };
  result->d = (vec2_t){ right, bottom };
}

void cgQuadFromRectRotated(quad_t* result, const rect_t* r, float angle)
{
  float s = sinf(angle);
  float c = cosf(angle);

  float dx = r->w / 2.0f;
  float dy = r->h / 2.0f;

  float cx = r->x + (r->w / 2.0f);
  float cy = r->y + (r->h / 2.0f);

  // Bottom left (a)
  result->a.x = cx - (dx * c) - (dy * s);
  result->a.y = cy + (dx * s) - (dy * c);

  // Top left (b)
  result->b.x = cx - (dx * c) + (dy * s);
  result->b.y = cy - (dx * s) - (dy * c);

  // Top right (c)
  result->c.x = cx + (dx * c) - (dy * s);
  result->c.y = cy + (dx * s) + (dy * c);

  // Bottom right (d)
  result->d.x = cx + (dx * c) + (dy * s);
  result->d.y = cy - (dx * s) + (dy * c);
}

void cgQuadRotate(quad_t* q, float angle)
{
  float og_x;

  float s = sinf(angle);
  float c = cosf(angle);

  // Bottom left (a)
  og_x = q->a.x;
  q->a.x = (q->a.x * c) - (q->a.y * s);
  q->a.y = (og_x * s) + (q->a.y * c);

  // Bottom right (b)
  og_x = q->b.x;

  q->b.x = (q->b.x * c) - (q->b.y * s);
  q->b.y = (og_x * s) + (q->b.y * c);

  // Top left (c)
  og_x = q->c.x;

  q->c.x = (q->c.x * c) - (q->c.y * s);
  q->c.y = (og_x * s) + (q->c.y * c);

  // Top right (d)
  og_x = q->d.x;

  q->d.x = (q->d.x * c) - (q->d.y * s);
  q->d.y = (og_x * s) + (q->d.y * c);
}

void cgQuadRotateAround(quad_t* q, const vec2_t* origin, float angle)
{
  float s = sinf(angle);
  float c = cosf(angle);

  float dx;
  float dy;

  // Bottom left (a)
  dx = q->a.x - origin->x;
  dy = q->a.y - origin->y;

  q->a.x = origin->x + (dx * c) - (dy * s);
  q->a.y = origin->y + (dx * s) + (dy * c);

  // Bottom right (b)
  dx = q->b.x - origin->x;
  dy = q->b.y - origin->y;

  q->b.x = origin->x + (dx * c) - (dy * s);
  q->b.y = origin->y + (dx * s) + (dy * c);

  // Top left (c)
  dx = q->c.x - origin->x;
  dy = q->c.y - origin->y;

  q->c.x = origin->x + (dx * c) - (dy * s);
  q->c.y = origin->y + (dx * s) + (dy * c);

  // Top right (d)
  dx = q->d.x - origin->x;
  dy = q->d.y - origin->y;

  q->d.x = origin->x + (dx * c) - (dy * s);
  q->d.y = origin->y + (dx * s) + (dy * c);
}
