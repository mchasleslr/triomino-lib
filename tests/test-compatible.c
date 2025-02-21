/**
 * @file       test-compatible.c
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
    Triomino* triomino1 = triomino_create_full(1, 2, 3);
    Triomino* triomino2 = triomino_create_full(1, 1, 2);
    assert(triomino_aa_compatible(triomino1, triomino2) == true);
    assert(triomino_ab_compatible(triomino1, triomino2) == true);
    assert(triomino_ac_compatible(triomino1, triomino2) == false);
    assert(triomino_ba_compatible(triomino1, triomino2) == false);
    assert(triomino_bb_compatible(triomino1, triomino2) == false);
    assert(triomino_bc_compatible(triomino1, triomino2) == true);
    assert(triomino_ca_compatible(triomino1, triomino2) == false);
    assert(triomino_cb_compatible(triomino1, triomino2) == false);
    assert(triomino_cc_compatible(triomino1, triomino2) == false);
    assert(triomino_ab_cb_compatible(triomino1, triomino2) == false);
    assert(triomino_ab_ba_compatible(triomino1, triomino2) == false);
    assert(triomino_ab_ac_compatible(triomino1, triomino2) == true);
    assert(triomino_bc_cb_compatible(triomino1, triomino2) == false);
    assert(triomino_bc_ba_compatible(triomino1, triomino2) == false);
    assert(triomino_bc_ac_compatible(triomino1, triomino2) == false);
    assert(triomino_ca_cb_compatible(triomino1, triomino2) == false);
    assert(triomino_ca_ba_compatible(triomino1, triomino2) == false);
    assert(triomino_ca_ac_compatible(triomino1, triomino2) == false);
    triomino_destroy(triomino1);
    triomino_destroy(triomino2);
  }
  triomino_finish();
  return EXIT_SUCCESS;
}
