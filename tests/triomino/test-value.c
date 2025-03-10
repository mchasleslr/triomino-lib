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
    // triomios singles/doubles
    Triomino *tr_xxy = triomino_create_full(1, 1, 2);
    Triomino *tr_xyy = triomino_create_full(1, 2, 2);
    Triomino *tr_xyz = triomino_create_full(1, 2, 3);
    // triomios triples
    Triomino *tr_xxx = triomino_create_full(1, 1, 1);
    Triomino *tr_yyy = triomino_create_full(2, 2, 2);
    Triomino *tr_zzz = triomino_create_full(3, 3, 3);
    Triomino *tr_ooo = triomino_create_full(0, 0, 0);

    // test triominos singles/doubles
    assert(triomino_get_value(tr_xxx, DEFAULT) == 3);
    assert(triomino_get_value(tr_xxy,DEFAULT) == 4);
    assert(triomino_get_value(tr_xyy,DEFAULT) == 5);
    assert(triomino_get_value(tr_xyz,DEFAULT) == 6);

    // test triominos triples at game initialisation/startup
    assert(triomino_get_value(tr_xxx, GAME_START) == 13);
    assert(triomino_get_value(tr_yyy, GAME_START) == 16);
    assert(triomino_get_value(tr_zzz, GAME_START) == 19);
    assert(triomino_get_value(tr_ooo, GAME_START) == 40);

    triomino_destroy(tr_xxx);
    triomino_destroy(tr_xxy);
    triomino_destroy(tr_xyy);
    triomino_destroy(tr_xyz);
    triomino_destroy(tr_yyy);
    triomino_destroy(tr_ooo);
    triomino_destroy(tr_zzz);
  }
  triomino_finish();
  return EXIT_SUCCESS;
}
