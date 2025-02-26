/**
 * @file       test-tile_get_.c
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

int main(void)
{
  Triomino *triomino = triomino_create_default();
  TriominoTile *tile = triomino_tile_create_full(triomino, 0, R_45);

  assert(triomino_tile_get_triomino(tile) == triomino);
  assert(triomino_tile_get_player_id(tile) == 0);
  assert(triomino_tile_get_rotation(tile) == R_45);

  triomino_tile_destroy(tile);

  return EXIT_SUCCESS;
}
