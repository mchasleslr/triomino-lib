/**
 * @file       test-grid.c
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

#include "triomino-grid.h"

#include "triomino.inc"

int main(void)
{
  assert("" && sizeof(TriominoGrid *) == __SIZEOF_POINTER__);
  assert("" && sizeof(TriominoGrid) == 16);

  return EXIT_SUCCESS;
}
