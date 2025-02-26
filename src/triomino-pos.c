/**
 * @file       triomino-pos.c
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include "triomino-pos.h"

#include <stdlib.h>
#include <stdio.h>

#include "types.h"

#include "triomino.inc"

#define _SIZEOF_TRIOMINO_POS sizeof(TriominoPos)

TriominoPos *triomino_pos_set_full(TriominoPos *pos, coord_t x, coord_t y, slot_t slot, rot_t rotation)
{
  pos->coords[0] = x;
  pos->coords[1] = y;
  pos->rotation = rotation;
  pos->slot = slot;

  return pos;
}

TriominoPos *triomino_pos_create_full(coord_t x, coord_t y, slot_t slot, rot_t rotation)
{
  TriominoPos *pos;

  if (NULL != (pos = malloc(sizeof(TriominoPos))))
  {
    pos = triomino_pos_set_full(pos, x, y, slot, rotation);
  }

  return pos;
}

void triomino_pos_destroy(TriominoPos *pos)
{
  free(pos);
}

coord_t triomino_pos_get_x(TriominoPos *pos)
{
  return pos->coords[0];
}

coord_t triomino_pos_get_y(TriominoPos *pos)
{
  return pos->coords[1];
}

slot_t triomino_pos_get_slot(TriominoPos *pos)
{
  return pos->slot;
}

rot_t triomino_pos_get_rotation(TriominoPos *pos)
{
  return pos->rotation;
}
