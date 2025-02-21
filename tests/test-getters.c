/**
 * @file       test-getters.c
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
  triomino_init();
  {
    Triomino* triomino = triomino_create_full(1, 2, 3);
    assert(triomino_get_a(triomino) == 1);
    assert(triomino_get_b(triomino) == 2);
    assert(triomino_get_c(triomino) == 3);
    triomino_destroy(triomino);
  }
  triomino_finish();

  return EXIT_SUCCESS;
}
