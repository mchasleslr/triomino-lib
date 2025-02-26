#ifndef _TRIOMINO_TYPES_H
#define _TRIOMINO_TYPES_H

#include "set.h"

typedef unsigned int coord_t;
typedef enum _rot_t rot_t;
typedef enum _edge_t edge_t;
typedef Set TriominoSet;

enum _rot_t
{
  R_45,
  R_135,
  R_225,
  R_270,
};

enum _edge_t
{
  EDGE_INF,
  EDGE_SUP
};

#endif // _TRIOMINO_TYPES_H
