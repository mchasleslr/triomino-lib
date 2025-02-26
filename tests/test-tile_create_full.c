/**
 * @file       test-set_create_full.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "triomino-pos.h"
#include "triomino-tile.h"

#include "triomino.inc"

int main(void)
{
  Triomino *triomino = triomino_create_full(0, 0, 5);
  TriominoPos *pos = triomino_pos_create_full(5, 4, SLOT_TOP, ROT_135);

  TriominoTile *tile = triomino_tile_create_full(1, pos, NULL, triomino);

  assert("" && tile->player_id == 1);
  assert("" && triomino_pos_get_x(tile->pos) == 5);
  assert("" && triomino_pos_get_y(tile->pos) == 4);
  assert("" && triomino_pos_get_slot(tile->pos) == SLOT_TOP);
  assert("" && triomino_pos_get_rotation(tile->pos) == ROT_135);
  assert("" && tile->prev_played == NULL);
  assert("" && tile->triomino == triomino);

  triomino_tile_destroy(tile);

  return EXIT_SUCCESS;
}
