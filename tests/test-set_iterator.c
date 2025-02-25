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
#include "set-iterator.h"

#include "set.inc"
#include "set_iterator.inc"

int main(void)
{
  assert(sizeof(SetIterator *) == __SIZEOF_POINTER__);
  assert(sizeof(SetIterator) == 24);

  return EXIT_SUCCESS;
}
