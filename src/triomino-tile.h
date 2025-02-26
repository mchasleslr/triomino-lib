/**
 * @file       triomino-tile.h
 *
 * @author     Maxime CHASLES
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#ifndef _TRIOMINO_TILE_H
#define _TRIOMINO_TILE_H

#include "triomino.h"
#include "triomino-types.h"

typedef struct _TriominoTile TriominoTile;

extern TriominoTile *triomino_tile_create_full(Triomino *triomino, id_t player_id, rot_t rotation);
extern void triomino_tile_destroy(TriominoTile *tile);
extern id_t triomino_tile_get_player_id(TriominoTile *tile);
extern rot_t triomino_tile_get_rotation(TriominoTile *tile);
extern Triomino *triomino_tile_get_triomino(TriominoTile *tile);

#endif // _TRIOMINO_TILE_H
