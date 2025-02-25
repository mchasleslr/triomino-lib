/**
 * @file       test-set.c
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
#include "triomino_plcmt.h"

#include "set.inc"
#include "triomino.inc"
#include "triomino_plcmt.inc"

#define _SIZEOF_SET sizeof(Set)
#define _SIZEOF_SETNODE sizeof(SetNode)

int main(void)
{
  assert(sizeof(Set *) == __SIZEOF_POINTER__);
  assert(sizeof(SetNode *) == __SIZEOF_POINTER__);
  assert(sizeof(Set) == _SIZEOF_SET);
  assert(sizeof(SetNode) == _SIZEOF_SETNODE);

  return EXIT_SUCCESS;
}
