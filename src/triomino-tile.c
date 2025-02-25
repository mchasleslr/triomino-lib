/**
 * @file       triomino-tile.c
 *
 * @author     Maxime Chasles <mchasles@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include "triomino-tile.h"

#include <stdlib.h>
#include <stdio.h>

#include "triomino.h"
#include "types.h"

#include "triomino.inc"

TriominoTile *triomino_tile_fill_full(TriominoTile *tile, Triomino *triomino, id_t player_id, unsigned int x, unsigned int y, rotation_t rotation)
{
  tile->triomino = triomino;
  tile->pos->coords.x = x;
  tile->pos->coords.y = y;
  tile->pos->rotation = rotation;
  tile->player_id = player_id;

  return tile;
}
