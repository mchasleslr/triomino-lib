/**
 * @file       test-set_size.c
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
  int m = 1;
  int n = 2;

  Set *set = set_create();

  assert("" && set_size(set) == 0);

  set = set_add(set, &m);

  assert("" && set_size(set) == 1);

  set = set_add(set, &n);

  assert("" && set_size(set) == 2);

  set_destroy(set);

  return EXIT_SUCCESS;
}
