/**
 * @file       test-copy-clone.c
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

    Triomino* clone = triomino_clone(triomino);
    assert(triomino->a == clone->a);
    assert(triomino->b == clone->b);
    assert(triomino->c == clone->c);

    Triomino* copy = triomino_create_default();
    assert(triomino_copy(copy, triomino) == copy);
    assert(triomino->a == copy->a);
    assert(triomino->b == copy->b);
    assert(triomino->c == copy->c);

    triomino_destroy(triomino);
    triomino_destroy(clone);
    triomino_destroy(copy);
  }
  triomino_finish();

  return EXIT_SUCCESS;
}
