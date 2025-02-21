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

#include "triomino.h"
#include "triomino_plcmt.h"
#include "triomino.inc"
#include "triomino_plcmt.inc"

int main(void)
{
  triomino_init();
  {
    assert("Pointer size" && sizeof(TriominoPlcmt *) == 8);
    assert("Struct size" && sizeof(TriominoPlcmt) == 24);
  }
  triomino_finish();

  return EXIT_SUCCESS;
}
