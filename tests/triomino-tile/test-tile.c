/**
 * @file       test-tile.c
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
  assert(sizeof(TriominoTile) == 16);

  return EXIT_SUCCESS;
}
