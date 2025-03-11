/**
 * @file       test-set_iterator_destroy.c
 *
 * @author     Maxime Chasles <mchasles@etudiant.univ-lr.fr>
 * @date       2024
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
  Set *set = set_create();

  SetIterator *iterator = set_iterator_create(set);

  assert("" && iterator->current == 0);
  assert("" && iterator->set == set);

  set_iterator_destroy(iterator);
  set_destroy(set);

  return EXIT_SUCCESS;
}
