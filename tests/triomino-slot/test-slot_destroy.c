/**
 * @file       test-tile_destroy.c
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

int main(void)
{
  Triomino *triomino = triomino_create_default();
  TriominoTile *tile = triomino_tile_create_full(triomino, 0, R_45);
  TriominoSlot *slot = triomino_slot_create_full(tile, 5, 7, E_BOT_LEFT);

  triomino_slot_destroy(slot);

  return EXIT_SUCCESS;
}
