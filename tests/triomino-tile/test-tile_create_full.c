/**
 * @file       test-tile_create_full.c
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

#include "triomino-types.h"
#include "triomino-tile.h"

#include "triomino.inc"

int main(void)
{
  Triomino *triomino = triomino_create_default();
  TriominoTile *tile = triomino_tile_create_full(triomino, 0, R_45);

  assert(tile->triomino == triomino);
  assert(tile->player_id == 0);
  assert(tile->rotation == R_45);

  triomino_destroy(triomino);
  free(tile);

  return EXIT_SUCCESS;
}
