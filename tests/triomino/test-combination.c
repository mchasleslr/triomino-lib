/**
 * @file       test-combination.c
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

#include "triomino.h"
#include "triomino.inc"

int main(void) {
  triomino_init();
  {
    Triomino *tr_xxx = triomino_create_full(1, 1, 1);
    Triomino *tr_xxy = triomino_create_full(1, 1, 2);
    Triomino *tr_xyy = triomino_create_full(1, 2, 2);
    Triomino *tr_xyz = triomino_create_full(1, 2, 3);

    assert(triomino_is_triple(tr_xxx) == true);
    assert(triomino_is_triple(tr_xxy) == false);
    assert(triomino_is_triple(tr_xyy) == false);
    assert(triomino_is_triple(tr_xyz) == false);

    assert(triomino_is_double(tr_xxy) == true);
    assert(triomino_is_double(tr_xyy) == true);
    assert(triomino_is_double(tr_xxx) == false);
    assert(triomino_is_double(tr_xyz) == false);

    assert(triomino_is_single(tr_xyz) == true);
    assert(triomino_is_single(tr_xxx) == false);
    assert(triomino_is_single(tr_xxy) == false);
    assert(triomino_is_single(tr_xyy) == false);

    triomino_destroy(tr_xxx);
    triomino_destroy(tr_xxy);
    triomino_destroy(tr_xyy);
    triomino_destroy(tr_xyz);
  }
  triomino_finish();
  return EXIT_SUCCESS;
}
