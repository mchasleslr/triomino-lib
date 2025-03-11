/**
 * @file       test-set_merge.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "set.h"
#include "test-config.h"

static void test_set_merge_empty_sets(void) {
  Set *dest = set_create();
  Set *src = set_create();

  Set *result = set_merge(dest, src);

  assert(set_empty(result));
  assert(result == dest);

  set_destroy(result);
}

static void test_set_merge_empty_source(void) {
  Set *dest = set_create();
  Set *src = set_create();
  int val = 42;

  set_add(dest, &val);
  Set *result = set_merge(dest, src);

  assert(set_size(result) == 1);
  assert(set_contains(result, &val));
  assert(result == dest);

  set_destroy(result);
}

static void test_set_merge_empty_dest(void) {
  Set *dest = set_create();
  Set *src = set_create();
  int val = 42;

  set_add(src, &val);
  Set *result = set_merge(dest, src);

  assert(set_size(result) == 1);
  assert(set_contains(result, &val));
  assert(result == dest);

  set_destroy(result);
}

static void test_set_merge_with_duplicates(void) {
  Set *dest = set_create();
  Set *src = set_create();
  int val1 = 42;
  int val2 = 43;

  set_add(dest, &val1);
  set_add(src, &val1);  // Duplicate
  set_add(src, &val2);

  Set *result = set_merge(dest, src);

  assert(set_size(result) == 2);
  assert(set_contains(result, &val1));
  assert(set_contains(result, &val2));
  assert(result == dest);

  set_destroy(result);
}

static void test_set_merge_multiple_elements(void) {
  Set *dest = set_create();
  Set *src = set_create();
  int val1 = 42, val2 = 43, val3 = 44;

  set_add(dest, &val1);
  set_add(src, &val2);
  set_add(src, &val3);

  Set *result = set_merge(dest, src);

  assert(set_size(result) == 3);
  assert(set_contains(result, &val1));
  assert(set_contains(result, &val2));
  assert(set_contains(result, &val3));
  assert(result == dest);

  set_destroy(result);
}

int main(void) {
  test_set_merge_empty_dest();
  test_set_merge_empty_source();
  test_set_merge_empty_sets();
  test_set_merge_with_duplicates();
  test_set_merge_multiple_elements();

  return EXIT_SUCCESS;
}
