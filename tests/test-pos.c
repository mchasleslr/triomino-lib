/**
 * @file       test-pos.c
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
  assert("" && sizeof(TriominoPos *) == __SIZEOF_POINTER__);
  assert("" && sizeof(TriominoPos) == 16);

  return EXIT_SUCCESS;
}
