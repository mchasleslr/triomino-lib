/**
 * @file       test-set_contains.c
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

int main(void) {
  int m = 1;
  int n = 2;
  int x = 0;

  Set *set = set_create();

  set = set_add(set, &m);
  set = set_add(set, &n);

  assert("" && set_contains(set, &m));
  assert("" && set_contains(set, &n));
  assert("" && !set_contains(set, &x));

  set_destroy(set);

  return EXIT_SUCCESS;
}
