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
#include "triomino.h"
#include "triomino_plcmt.h"

#include "set.inc"
#include "triomino.inc"
#include "triomino_plcmt.inc"

int main(void)
{
  assert(sizeof(Set *) == __SIZEOF_POINTER__);
  assert(sizeof(SetNode *) == __SIZEOF_POINTER__);
  assert(sizeof(Set) == _SIZEOF_SET);
  assert(sizeof(SetNode) == _SIZEOF_SETNODE);

  return EXIT_SUCCESS;
}
