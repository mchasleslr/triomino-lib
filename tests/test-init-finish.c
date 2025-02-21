/**
 * @file       test-init-finish.c
 *
 * @author     Christophe Demko <christophe.demko@univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "triomino.h"
#include "triomino.inc"

int main(void) {
  assert(triomino_init());
  assert(triomino_init());
  assert(triomino_init());
  assert(triomino_finish());
  assert(triomino_finish());
  assert(triomino_finish());
  assert(!triomino_finish());
  return EXIT_SUCCESS;
}
