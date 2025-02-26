/**
 * @file       triomino-slot.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "triomino-slot.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "triomino.inc"

TriominoSlot *triomino_slot_create_full(TriominoTile *tile, coord_t x, coord_t y, edge_t edge)
{
  TriominoSlot *slot;

  if (NULL != (slot = malloc(sizeof(TriominoSlot))))
  {
    // Allocation success

    slot->tile = tile;
    slot->edge = edge;
    slot->coord[0] = x;
    slot->coord[1] = y;
  }
  return slot;
}

TriominoSlot *triomino_slot_create_empty(coord_t x, coord_t y, edge_t edge)
{
  return triomino_slot_create_full(NULL, x, y, edge);
}

void triomino_slot_destroy(TriominoSlot *slot)
{
  if (slot->tile)
  {
    triomino_tile_destroy(slot->tile);
  }
  free(slot);
}

bool triomino_slot_on_inf_edge(TriominoSlot *s)
{
  return s->edge == EDGE_INF;
}

bool triomino_slot_on_sup_edge(TriominoSlot *s)
{
  return s->edge == EDGE_SUP;
}

TriominoTile *triomino_slot_get_tile(TriominoSlot *slot)
{
  return slot->tile;
}

coord_t triomino_slot_get_x(TriominoSlot *slot)
{
  return slot->coord[0];
}

coord_t triomino_slot_get_y(TriominoSlot *slot)
{
  return slot->coord[1];
}

edge_t triomino_slot_get_edge(TriominoSlot *slot)
{
  return slot->edge;
}

bool triomino_slot_empty(TriominoSlot *slot)
{
  return slot->tile == NULL;
}

// TODO: change returns in one line

bool triomino_slot_ymin(TriominoSlot *slot, coord_t y_min)
{
  coord_t y = triomino_slot_get_y(slot);
  return y == y_min;
}

bool triomino_slot_ymax(TriominoSlot *slot, coord_t y_max)
{
  coord_t y = triomino_slot_get_y(slot);
  return y == y_max - 1;
}

bool triomino_slot_xmin(TriominoSlot *slot, coord_t x_min)
{
  coord_t x = triomino_slot_get_y(slot);
  return x == x_min;
}

bool triomino_slot_xmax(TriominoSlot *slot, coord_t x_max)
{
  coord_t x = triomino_slot_get_x(slot);
  return x == x_max - 1;
}
