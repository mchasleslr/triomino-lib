/**
 * @file       test-set.c
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

#include "triomino-tile.h"

#include "triomino.inc"

int main(void)
{
  assert("" && sizeof(TriominoTile *) == __SIZEOF_POINTER__);
  assert("" && sizeof(TriominoTile) == 32);

  return EXIT_SUCCESS;
}
