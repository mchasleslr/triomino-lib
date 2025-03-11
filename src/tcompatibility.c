/**
 * @file       tcompatibility.c
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#include "tcompatibility.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tconstants.h"
#include "tgrid.h"
#include "tmem.h"
#include "tplacement.h"
#include "ttypes.h"

// ----------------------------------------------------------------------------

static default_compatibibility_strategy(const Triomino* ref,
                                        const Triomino* target) {
  return false;
}

TCompatibility* t_compatibility_create(Triomino* ref) {
  TCompatibility* comp = t_malloc(sizeof(TCompatibility));

  comp->ref = ref;

  return comp;
}

void t_compatibility_destroy(TCompatibility* comp) {
  // Note: it doesn't destroy the ressources
  free(comp);
}

// TODO: change the return type to bool or other...
int t_compatibility_set_strategy(TCompatibility* comp, int context) {
  switch (context) {
    case (POS_REL_SXY | ROT_REL_AA):  // OK
    case (POS_REL_SX | ROT_REL_BB):
    case (POS_REL_SY | ROT_REL_CC):
      comp->strategy = triomino_bc_cb_compatible;
      break;
    case (POS_REL_SXY | ROT_REL_AC):  // OK
    case (POS_REL_SX | ROT_REL_BA):
    case (POS_REL_SY | ROT_REL_CB):
      //
      comp->strategy = triomino_bc_ba_compatible;
      break;
    case (POS_REL_SXY | ROT_REL_AB):  // OK
    case (POS_REL_SX | ROT_REL_BC):
    case (POS_REL_SY | ROT_REL_CA):
      //
      comp->strategy = triomino_bc_ac_compatible;
      break;
    case (POS_REL_SXY | ROT_REL_CA):  // OK
    case (POS_REL_SX | ROT_REL_AB):
    case (POS_REL_SY | ROT_REL_BC):
      //
      comp->strategy = triomino_ab_cb_compatible;
      break;
    case (POS_REL_SXY | ROT_REL_CC):  // OK
    case (POS_REL_SX | ROT_REL_AA):
    case (POS_REL_SY | ROT_REL_BB):
      //
      comp->strategy = triomino_ab_ba_compatible;
      break;
    case (POS_REL_SXY | ROT_REL_CB):  // OK
    case (POS_REL_SX | ROT_REL_AC):
    case (POS_REL_SY | ROT_REL_BA):
      //
      comp->strategy = triomino_ab_ac_compatible;
      break;
    case (POS_REL_SXY | ROT_REL_BA):  // OK
    case (POS_REL_SX | ROT_REL_CB):
    case (POS_REL_SY | ROT_REL_AC):
      //
      comp->strategy = triomino_ca_cb_compatible;
      break;
    case (POS_REL_SXY | ROT_REL_BC):  // OK
    case (POS_REL_SX | ROT_REL_CA):
    case (POS_REL_SY | ROT_REL_AB):
      //
      comp->strategy = triomino_ca_ba_compatible;
      break;
    case (POS_REL_SXY | ROT_REL_BB):  // OK
    case (POS_REL_SX | ROT_REL_CC):
    case (POS_REL_SY | ROT_REL_AA):
      //
      comp->strategy = triomino_ca_ac_compatible;
      break;
    case (POS_REL_CCIS2 | ROT_REL_BC):
    case (POS_REL_CCIS1 | ROT_REL_CB):
    case (POS_REL_CTRANS1 | ROT_REL_CC):
    case (POS_REL_CTRANS2 | ROT_REL_BB):
    case (POS_REL_CY2 | ROT_REL_AC):
    case (POS_REL_CY1 | ROT_REL_CA):
    case (POS_REL_CX2 | ROT_REL_BA):
    case (POS_REL_CX1 | ROT_REL_AB):
    case (POS_REL_COPP | ROT_REL_AA):
      comp->strategy = triomino_aa_compatible;
      break;
    case (POS_REL_COPP | ROT_REL_AB):
    case (POS_REL_CTRANS2 | ROT_REL_BC):
    case (POS_REL_CTRANS1 | ROT_REL_CA):
    case (POS_REL_CCIS2 | ROT_REL_BA):
    case (POS_REL_CCIS1 | ROT_REL_CC):
    case (POS_REL_CY2 | ROT_REL_AA):
    case (POS_REL_CY1 | ROT_REL_CB):
    case (POS_REL_CX2 | ROT_REL_BB):
    case (POS_REL_CX1 | ROT_REL_AC):
      comp->strategy = triomino_ab_compatible;
      break;
    case (POS_REL_COPP | ROT_REL_AC):
    case (POS_REL_CTRANS2 | ROT_REL_BA):
    case (POS_REL_CTRANS1 | ROT_REL_CB):
    case (POS_REL_CCIS2 | ROT_REL_BB):
    case (POS_REL_CCIS1 | ROT_REL_CA):
    case (POS_REL_CY2 | ROT_REL_AB):
    case (POS_REL_CY1 | ROT_REL_CC):
    case (POS_REL_CX2 | ROT_REL_BC):
    case (POS_REL_CX1 | ROT_REL_AA):
      comp->strategy = triomino_ac_compatible;
      break;
    case (POS_REL_COPP | ROT_REL_BA):
    case (POS_REL_CTRANS2 | ROT_REL_CB):
    case (POS_REL_CTRANS1 | ROT_REL_AC):
    case (POS_REL_CCIS2 | ROT_REL_CC):
    case (POS_REL_CCIS1 | ROT_REL_AB):
    case (POS_REL_CY2 | ROT_REL_BC):
    case (POS_REL_CY1 | ROT_REL_AA):
    case (POS_REL_CX2 | ROT_REL_CA):
    case (POS_REL_CX1 | ROT_REL_BB):
      comp->strategy = triomino_ba_compatible;
      break;
    case (POS_REL_CTRANS1 | ROT_REL_AA):
    case (POS_REL_CCIS2 | ROT_REL_CA):
    case (POS_REL_CY2 | ROT_REL_BA):
    case (POS_REL_CTRANS2 | ROT_REL_CC):
    case (POS_REL_COPP | ROT_REL_BB):
    case (POS_REL_CCIS1 | ROT_REL_AC):
    case (POS_REL_CY1 | ROT_REL_AB):
    case (POS_REL_CX2 | ROT_REL_CB):
    case (POS_REL_CX1 | ROT_REL_BC):
      comp->strategy = triomino_bb_compatible;
      break;
    case (POS_REL_COPP | ROT_REL_BC):
    case (POS_REL_CTRANS2 | ROT_REL_CA):
    case (POS_REL_CTRANS1 | ROT_REL_AB):
    case (POS_REL_CCIS2 | ROT_REL_CB):
    case (POS_REL_CCIS1 | ROT_REL_AA):
    case (POS_REL_CY2 | ROT_REL_BB):
    case (POS_REL_CY1 | ROT_REL_AC):
    case (POS_REL_CX2 | ROT_REL_CC):
    case (POS_REL_CX1 | ROT_REL_BA):
      comp->strategy = triomino_bc_compatible;
      break;
    case (POS_REL_CCIS1 | ROT_REL_BB):
    case (POS_REL_CCIS2 | ROT_REL_AC):
    case (POS_REL_CTRANS1 | ROT_REL_BC):
    case (POS_REL_CTRANS2 | ROT_REL_AB):
    case (POS_REL_COPP | ROT_REL_CA):
    case (POS_REL_CX2 | ROT_REL_AA):
    case (POS_REL_CY2 | ROT_REL_CC):
    case (POS_REL_CY1 | ROT_REL_BA):
    case (POS_REL_CX1 | ROT_REL_CB):
      comp->strategy = triomino_ca_compatible;
      break;
    case (POS_REL_CX1 | ROT_REL_CC):
    case (POS_REL_CY1 | ROT_REL_BB):
    case (POS_REL_CTRANS1 | ROT_REL_BA):
    case (POS_REL_COPP | ROT_REL_CC):
    case (POS_REL_CTRANS2 | ROT_REL_AC):
    case (POS_REL_CCIS1 | ROT_REL_BC):
    case (POS_REL_CX2 | ROT_REL_AB):
    case (POS_REL_CY2 | ROT_REL_CA):
    case (POS_REL_CCIS2 | ROT_REL_AA):
      comp->strategy = triomino_cb_compatible;
      break;
    case (POS_REL_CX1 | ROT_REL_CA):
    case (POS_REL_CCIS1 | ROT_REL_BA):
    case (POS_REL_CY1 | ROT_REL_BC):
    case (POS_REL_CTRANS2 | ROT_REL_AA):
    case (POS_REL_CTRANS1 | ROT_REL_BB):
    case (POS_REL_COPP | ROT_REL_CB):
    case (POS_REL_CX2 | ROT_REL_AC):
    case (POS_REL_CY2 | ROT_REL_CB):
    case (POS_REL_CCIS2 | ROT_REL_AB):
      comp->strategy = triomino_cc_compatible;
      break;
    default:
      comp->strategy = default_compatibibility_strategy;
      return 1;
  }
  return 0;
}

bool t_compatibility_exec_strategy(TCompatibility* comp,
                                   const Triomino* target) {
  return comp->strategy(comp->ref, target);
}
