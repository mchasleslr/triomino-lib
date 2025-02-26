/**
 * @file       triomino-tile.c
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include "triomino-tile.h"

#include <stdlib.h>
#include <stdio.h>

#include "triomino-pos.h"
#include "types.h"

#include "triomino.inc"

#define _SIZEOF_TRIOMINO_TILE sizeof(TriominoTile)

const id_t default_player_id = ID_NDEF;

TriominoTile *triomino_tile_set_full(TriominoTile *tile, id_t player_id, TriominoPos *pos, TriominoTile *prev, Triomino *triomino)
{
  tile->player_id = player_id;
  tile->pos = pos;
  tile->prev_played = prev;
  tile->triomino = triomino;

  return tile;
}

TriominoTile *triomino_tile_create_full(id_t player_id, TriominoPos *pos, TriominoTile *prev, Triomino *triomino)
{
  TriominoTile *tile;

  if (NULL != (tile = malloc(sizeof(TriominoTile))))
  {
    tile = triomino_tile_set_full(tile, player_id, pos, prev, triomino);
  }

  return tile;
}

void triomino_tile_destroy(TriominoTile *tile)
{
  triomino_pos_destroy(tile->pos);
  triomino_destroy(tile->triomino);
  free(tile);
}

coord_t triomino_tile_get_x(TriominoTile *tile)
{
  return triomino_pos_get_x(tile->pos);
}
coord_t triomino_tile_get_y(TriominoTile *tile)
{
  return triomino_pos_get_y(tile->pos);
}
slot_t triomino_tile_get_slot(TriominoTile *tile)
{
  return triomino_pos_get_slot(tile->pos);
}
rot_t triomino_tile_get_rotation(TriominoTile *tile)
{
  return triomino_pos_get_rotation(tile->pos);
}

id_t triomino_tile_get_player_id(TriominoTile *tile)
{
  return tile->player_id;
}

Triomino *triomino_tile_get_triomino(TriominoTile *tile)
{
  return tile->triomino;
}

TriominoTile *triomino_tile_get_prev(TriominoTile *tile)
{
  return tile->prev_played;
}

bool triomino_tile_on_bottom_slot(TriominoTile *tile)
{
  return tile->pos->slot == SLOT_BOTTOM;
}
bool triomino_tile_on_top_slot(TriominoTile *tile)
{
  return tile->pos->slot == SLOT_TOP;
}

bool triomino_tile_ymin(TriominoTile *tile, coord_t y_min)
{
  coord_t y = triomino_tile_get_y(tile);
  return y == y_min;
}

bool triomino_tile_ymax(TriominoTile *tile, coord_t y_max)
{
  coord_t y = triomino_tile_get_y(tile);
  return y == y_max - 1;
}

bool triomino_tile_xmin(TriominoTile *tile, coord_t x_min)
{
  coord_t x = triomino_tile_get_y(tile);
  return x == x_min;
}

bool triomino_tile_xmax(TriominoTile *tile, coord_t x_max)
{
  coord_t x = triomino_tile_get_x(tile);
  return x == x_max - 1;
}
