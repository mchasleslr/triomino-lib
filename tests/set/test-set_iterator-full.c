/**
 * @file       test-set_iterator-full.c
 *
 * @author     Maxime Chasles <mchasles@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include <stdlib.h>
#include <string.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "set.h"
#include "triomino.h"

#include "set.inc"

int main(void)
{
  Set *set = set_create();

  Triomino *t1 = triomino_create_full(5, 5, 5);
  Triomino *t2 = triomino_create_full(4, 4, 4);
  Triomino *t3 = triomino_create_full(3, 3, 3);
  Triomino *t4 = triomino_create_full(2, 2, 2);

  Triomino *triominos[] = {t1, t2, t3, t4};

  set = set_add(set, t1);
  set = set_add(set, t2);
  set = set_add(set, t3);
  set = set_add(set, t4);

  SetIterator *iterator;
  unsigned int i;

  for (i = 0, iterator = set_iterator_create(set); set_iterator_has_next(iterator); i++, iterator = set_iterator_next(iterator))
  {
    assert("" && !strcmp(triomino_to_string((Triomino *)set_iterator_get(iterator)),
                         triomino_to_string(triominos[i])));
    assert("" && i == set_iterator_index(iterator));
  }

  for (i = 0, iterator = set_iterator_reset(iterator); set_iterator_has_next(iterator); i++, iterator = set_iterator_next(iterator))
  {
    assert("" && !strcmp(triomino_to_string((Triomino *)set_iterator_get(iterator)),
                         triomino_to_string(triominos[i])));
    assert("" && i == set_iterator_index(iterator));
  }

  set_iterator_destroy(iterator);
  triomino_destroy(t1);
  triomino_destroy(t2);
  triomino_destroy(t3);
  triomino_destroy(t4);

  return EXIT_SUCCESS;
}
