/**
 * @file       triomino-grid.h
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#ifndef _TRIOMINO_GRID_H
#define _TRIOMINO_GRID_H

#include <stdbool.h>

#include "set.h"
#include "triomino-types.h"
#include "triomino.h"
#include "triomino-tile.h"

#define GRID_XMIN 0
#define GRID_YMIN 0

typedef struct _TriominoGrid TriominoGrid;

extern TriominoGrid *triomino_grid_create_full(unsigned int width, unsigned int height);
extern TriominoGrid *triomino_grid_init(unsigned int width, unsigned int height);
extern void triomino_grid_destroy(TriominoGrid *grid);
extern TriominoTile *triomino_grid_put_tile(TriominoGrid *grid, Triomino *triomino, id_t player_id, coord_t x, coord_t y, slot_t slot, rot_t rotation, TriominoTile *prev_played);
extern TriominoTile *triomino_grid_get_tile(TriominoGrid *grid, coord_t x, coord_t y, slot_t slot);

extern TriominoTile *triomino_grid_get_tile_above(TriominoGrid *grid, TriominoTile *tile);
extern TriominoTile *triomino_grid_get_tile_below(TriominoGrid *grid, TriominoTile *tile);
extern TriominoTile *triomino_grid_get_tile_before(TriominoGrid *grid, TriominoTile *tile);
extern TriominoTile *triomino_grid_get_tile_after(TriominoGrid *grid, TriominoTile *tile);

extern Set *triomino_grid_get_adjacents_tiles(TriominoGrid *grid, TriominoTile *tile);
#endif // _TRIOMINO_GRID_H
