/**
 * @file       test-cell.c
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

#include "triomino-cell.h"

#include "triomino.inc"

int main(void)
{
  assert("" && sizeof(TriominoCell *) == __SIZEOF_POINTER__);
  assert("" && sizeof(TriominoCell) == 16);

  return EXIT_SUCCESS;
}
