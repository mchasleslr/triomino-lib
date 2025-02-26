/**
 * @file       test-set_create.c
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

#include "set.h"

#include "set.inc"

int main(void)
{
  Set *set = set_create();

  assert("" && set->head == NULL);

  free(set);

  return EXIT_SUCCESS;
}
