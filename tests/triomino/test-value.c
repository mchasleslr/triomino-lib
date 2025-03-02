/**
 * @file       test-value.c
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

int main(void)
{
  triomino_init();
  {
    Triomino *tr_xxx = triomino_create_full(1, 1, 1);
    Triomino *tr_xxy = triomino_create_full(1, 1, 2);
    Triomino *tr_xyy = triomino_create_full(1, 2, 2);
    Triomino *tr_xyz = triomino_create_full(1, 2, 3);

    assert(triomino_get_value(tr_xxx) == 3);
    assert(triomino_get_value(tr_xxy) == 4);
    assert(triomino_get_value(tr_xyy) == 5);
    assert(triomino_get_value(tr_xyz) == 6);

    triomino_destroy(tr_xxx);
    triomino_destroy(tr_xxy);
    triomino_destroy(tr_xyy);
    triomino_destroy(tr_xyz);
  }
  triomino_finish();
  return EXIT_SUCCESS;
}
