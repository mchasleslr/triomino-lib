/**
 * @file       triomino-tile.h
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#ifndef _TRIOMINO_TILE_H
#define _TRIOMINO_TILE_H

#include <stdbool.h>

#include "triomino.h"
#include "triomino-pos.h"
#include "types.h"

typedef struct _TriominoTile TriominoTile;

extern TriominoTile *triomino_tile_set_full(TriominoTile *tile, id_t player_id, TriominoPos *pos, TriominoTile *prev, Triomino *triomino);
extern TriominoTile *triomino_tile_create_full(id_t player_id, TriominoPos *pos, TriominoTile *prev, Triomino *triomino);
extern void triomino_tile_destroy(TriominoTile *tile);
extern coord_t triomino_tile_get_x(TriominoTile *tile);
extern coord_t triomino_tile_get_y(TriominoTile *tile);
extern slot_t triomino_tile_get_slot(TriominoTile *tile);
extern rot_t triomino_tile_get_rotation(TriominoTile *tile);
extern id_t triomino_tile_get_player_id(TriominoTile *tile);
extern Triomino *triomino_tile_get_triomino(TriominoTile *tile);
extern TriominoTile *triomino_tile_get_prev(TriominoTile *tile);
extern bool triomino_tile_on_bottom_slot(TriominoTile *tile);
extern bool triomino_tile_on_top_slot(TriominoTile *tile);
extern bool triomino_tile_ymin(TriominoTile *tile, coord_t y_min);
extern bool triomino_tile_xmin(TriominoTile *tile, coord_t x_min);
extern bool triomino_tile_ymax(TriominoTile *tile, coord_t y_max);
extern bool triomino_tile_xmax(TriominoTile *tile, coord_t x_max);

/**
 *
 */
extern bool triomino_tile_is_above(TriominoTile *current, TriominoTile *ajacent);

/**
 *
 */
extern bool triomino_tile_is_after(TriominoTile *current, TriominoTile *ajacent);

/**
 *
 */
extern bool triomino_tile_is_below(TriominoTile *current, TriominoTile *ajacent);

/**
 *
 */
extern bool triomino_tile_is_before(TriominoTile *current, TriominoTile *ajacent);

#endif // _TRIOMINO_TILE_H
