/**
 * @file       test-set_remove.c
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
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;

  int x = 0;

  Set *set_first = set_create();

  set_first = set_add(set_first, &a);
  set_first = set_add(set_first, &b);
  set_first = set_add(set_first, &c);
  set_first = set_add(set_first, &d);
  set_first = set_add(set_first, &e);

  set_first = set_remove(set_first, &a);

  assert("" && set_size(set_first) == 4);
  assert("" && !set_contains(set_first, &a));
  assert("" && set_contains(set_first, &b));
  assert("" && set_contains(set_first, &c));
  assert("" && set_contains(set_first, &d));
  assert("" && set_contains(set_first, &e));

  Set *set_middle = set_create();

  set_middle = set_add(set_middle, &a);
  set_middle = set_add(set_middle, &b);
  set_middle = set_add(set_middle, &c);
  set_middle = set_add(set_middle, &d);
  set_middle = set_add(set_middle, &e);

  set_middle = set_remove(set_middle, &c);

  assert("" && set_size(set_middle) == 4);
  assert("" && set_contains(set_middle, &a));
  assert("" && set_contains(set_middle, &b));
  assert("" && !set_contains(set_middle, &c));
  assert("" && set_contains(set_middle, &d));
  assert("" && set_contains(set_middle, &e));

  Set *set_end = set_create();

  set_end = set_add(set_end, &a);
  set_end = set_add(set_end, &b);
  set_end = set_add(set_end, &c);
  set_end = set_add(set_end, &d);
  set_end = set_add(set_end, &e);

  set_end = set_remove(set_end, &e);

  assert("" && set_size(set_end) == 4);
  assert("" && set_contains(set_end, &a));
  assert("" && set_contains(set_end, &b));
  assert("" && set_contains(set_end, &c));
  assert("" && set_contains(set_end, &d));
  assert("" && !set_contains(set_end, &e));

  Set *set_that_not_contains = set_create();

  set_that_not_contains = set_add(set_that_not_contains, &a);
  set_that_not_contains = set_add(set_that_not_contains, &b);
  set_that_not_contains = set_add(set_that_not_contains, &c);
  set_that_not_contains = set_add(set_that_not_contains, &d);
  set_that_not_contains = set_add(set_that_not_contains, &e);

  set_that_not_contains = set_remove(set_that_not_contains, &x);

  assert("" && set_size(set_that_not_contains) == 5);
  assert("" && set_contains(set_that_not_contains, &a));
  assert("" && set_contains(set_that_not_contains, &b));
  assert("" && set_contains(set_that_not_contains, &c));
  assert("" && set_contains(set_that_not_contains, &d));
  assert("" && set_contains(set_that_not_contains, &e));

  Set *set_empty = set_create();

  set_empty = set_remove(set_empty, &x);

  assert("" && set_size(set_empty) == 0);
  assert("" && !set_contains(set_empty, &a));
  assert("" && !set_contains(set_empty, &b));
  assert("" && !set_contains(set_empty, &c));
  assert("" && !set_contains(set_empty, &d));
  assert("" && !set_contains(set_empty, &e));

  set_destroy(set_first);
  set_destroy(set_middle);
  set_destroy(set_end);
  set_destroy(set_that_not_contains);
  set_destroy(set_empty);

  return EXIT_SUCCESS;
}
