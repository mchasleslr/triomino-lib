/**
 * @file       test-grid_create_full.c
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
  TriominoGrid *grid = triomino_grid_create_full(50, 50);

  assert("" && grid->width == 50);
  assert("" && grid->height == 50);
  assert("" && grid->cells == NULL);

  free(grid);

  return EXIT_SUCCESS;
}
