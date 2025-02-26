#ifndef _TRIOMINO_TYPES_H
#define _TRIOMINO_TYPES_H

typedef enum _rot_t rot_t;
typedef enum _edge_t edge_t;

enum _rot_t
{
  R_45,
  R_135,
  R_225,
  R_270,
};

enum _edge_t
{
  E_BOT_LEFT,
  E_TOP_RIGHT
};

typedef unsigned int coord_t;

#endif // _TRIOMINO_TYPES_H
