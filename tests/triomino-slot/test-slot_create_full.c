/**
 * @file       test-slot_create_full.c
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
#include "triomino-slot.h"

#include "triomino.inc"

int main(void)
{
  Triomino *triomino = triomino_create_default();
  TriominoTile *tile = triomino_tile_create_full(triomino, 0, R_45);
  TriominoSlot *slot = triomino_slot_create_full(tile, 5, 7, E_BOT_LEFT);

  assert(slot->coord[0] == 5);
  assert(slot->coord[1] == 7);
  assert(slot->edge == E_BOT_LEFT);
  assert(slot->tile == tile);

  triomino_tile_destroy(tile);
  free(slot);

  return EXIT_SUCCESS;
}
