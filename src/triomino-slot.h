/**
 * @file       triomino-slot.h
 *
 * @author     Maxime CHASLES
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#ifndef _TRIOMINO_SLOT_H
#define _TRIOMINO_SLOT_H

#include "triomino-tile.h"
#include "triomino-types.h"
#include "set.h"

typedef struct _TriominoSlot TriominoSlot;

extern TriominoSlot *triomino_slot_create_full(TriominoTile *tile, coord_t x, coord_t y, edge_t edge);
extern TriominoSlot *triomino_slot_create_empty(coord_t x, coord_t y, edge_t edge);
extern void triomino_slot_destroy(TriominoSlot *slot);
extern TriominoTile *triomino_slot_get_tile(TriominoSlot *slot);
extern coord_t triomino_slot_get_x(TriominoSlot *slot);
extern coord_t triomino_slot_get_y(TriominoSlot *slot);
extern edge_t triomino_slot_get_edge(TriominoSlot *slot);

extern bool triomino_slot_on_inf_edge(TriominoSlot *s);
extern bool triomino_slot_on_sup_edge(TriominoSlot *s);

extern bool triomino_slot_empty(TriominoSlot *slot);

extern bool triomino_slot_ymin(TriominoSlot *slot, coord_t y_min);
extern bool triomino_slot_ymax(TriominoSlot *slot, coord_t y_max);
extern bool triomino_slot_xmin(TriominoSlot *slot, coord_t x_min);
extern bool triomino_slot_xmax(TriominoSlot *slot, coord_t x_max);

extern TriominoSet *triomino_slot_get_empty_adjacents(TriominoSlot *slot);
extern TriominoSet *triomino_slot_get_full_adjacents(TriominoSlot *slot);

#endif // _TRIOMINO_SLOT_H
