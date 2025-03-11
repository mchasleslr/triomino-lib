/**
 * @file       test-set_filter.c
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
#include "triomino.h"
#include "triomino.inc"

bool filter_triomino(void *element) {
  Triomino *triomino = (Triomino *)element;
  return triomino->a == 0 || triomino->b == 3;
}

int main(void) {
  Triomino *t1 = triomino_create_full(0, 0, 0);
  Triomino *t2 = triomino_create_full(1, 1, 1);
  Triomino *t3 = triomino_create_full(2, 2, 2);
  Triomino *t4 = triomino_create_full(3, 3, 3);
  Triomino *t5 = triomino_create_full(4, 4, 4);

  Set *set = set_create();
  SetIterator *iterator;

  set = set_add(set, t1);
  set = set_add(set, t2);
  set = set_add(set, t3);
  set = set_add(set, t4);
  set = set_add(set, t5);

  for (iterator = set_iterator_create(set); set_iterator_has_next(iterator);
       iterator = set_iterator_next(iterator)) {
    printf("%s\n", triomino_to_string((Triomino *)set_iterator_get(iterator)));
  }

  set = set_filter(set, filter_triomino);

  for (iterator = set_iterator_reset(iterator); set_iterator_has_next(iterator);
       iterator = set_iterator_next(iterator)) {
    printf("%s\n", triomino_to_string((Triomino *)set_iterator_get(iterator)));
  }

  set_iterator_destroy(iterator);
  set_destroy(set);
  triomino_destroy(t1);
  triomino_destroy(t2);
  triomino_destroy(t3);
  triomino_destroy(t4);
  triomino_destroy(t5);

  return EXIT_SUCCESS;
}
