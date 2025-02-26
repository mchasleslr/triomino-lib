/**
 * @file       triomino-tile.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "triomino-tile.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "triomino.inc"

TriominoTile *triomino_tile_create_full(Triomino *triomino, unsigned int player_id, rot_t rotation)
{
  TriominoTile *tile;

  if (NULL != (tile = malloc(sizeof(TriominoTile))))
  {
    // Allocation success

    tile->triomino = triomino;
    tile->player_id = player_id;
    tile->rotation = rotation;
  }

  return tile;
}

void triomino_tile_destroy(TriominoTile *tile)
{
  triomino_destroy(tile->triomino);
  free(tile);
}

unsigned int triomino_tile_get_player_id(TriominoTile *tile)
{
  return tile->player_id;
}

rot_t triomino_tile_get_rotation(TriominoTile *tile)
{
  return tile->rotation;
}

Triomino *triomino_tile_get_triomino(TriominoTile *tile)
{
  return tile->triomino;
}
