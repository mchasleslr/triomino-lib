/**
 * @file       test-plcmt-struct.c
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
#include "set_iterator.h"

#include "set.inc"
#include "set_iterator.inc"

int main(void)
{
  Set *set = set_create();

  SetIterator *iterator = set_iterator_create(set);

  assert("" && iterator->current == 0);
  assert("" && iterator->set == set);

  set_destroy(set);
  free(iterator);

  return EXIT_SUCCESS;
}
