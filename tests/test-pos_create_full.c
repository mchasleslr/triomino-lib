/**
 * @file       test-pos_create_default.c
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

#include "triomino.inc"

int main(void)
{
  coord_t coords[2] = {25, 60};
  rot_t rotation = ROT_225;
  slot_t slot = SLOT_BOTTOM;

  TriominoPos *pos = triomino_pos_create_full(coords[0], coords[1], slot, rotation);

  assert("" && pos->coords[0] == 25);
  assert("" && pos->coords[1] == 60);
  assert("" && pos->slot == SLOT_BOTTOM);
  assert("" && pos->rotation == ROT_225);

  triomino_pos_destroy(pos);

  return EXIT_SUCCESS;
}
