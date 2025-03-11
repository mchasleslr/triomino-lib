/**
 * @file       test-set_pop_random.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include <unistd.h>

#include "set.h"
#include "set.inc"
#include "test-config.h"
#include "tutils.h"

static void test_set_pop_random(void) {
  int arr[] = {1, 2, 3, 4, 5, 6};
  Set *set = set_create();

  for (int i = 0; i < (int)ARRAY_LEN(arr); i++) {
    set_add(set, &arr[i]);
  }

  int *popped = set_pop_random(set);

  assert("" && set_size(set) == 5);
  assert("" && !set_contains(set, popped));

  set_destroy(set);
}

static void test_set_pop_random_empty(void) {
  Set *set = set_create();

  int *popped = set_pop_random(set);

  assert("" && !popped);

  set_destroy(set);
}

int main(void) {
  test_set_pop_random();
  test_set_pop_random_empty();

  return EXIT_SUCCESS;
}
