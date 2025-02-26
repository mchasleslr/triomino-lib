/**
 * @file       test-slot.c
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

#include "triomino-slot.h"

#include "triomino.inc"

int main(void)
{
  assert(sizeof(TriominoSlot) == 24);
  return EXIT_SUCCESS;
}
