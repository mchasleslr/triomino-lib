/**
 * @file       test-t_placement_create-destroy.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "tconstants.h"
#include "test-config.h"
#include "tplacement.h"
#include "triomino.inc"

static void test_t_placement_create(void) {
  TPlacement *tp = t_placement_create(1, 2, EDGE_INF);

  assert(tp != NULL);
  assert(tp->id == 0);
  assert(tp->coords[0] == 1);
  assert(tp->coords[1] == 2);
  assert(tp->coords[2] == EDGE_INF);

  t_placement_destroy(tp);
}

static void test_t_placement_create_full(void) {
  Triomino *t = triomino_create_full(0, 0, 0);
  TPlacement *tp = t_placement_create_full(1, 2, 3, EDGE_SUP, ROT_ABS_A, t);

  assert(tp != NULL);
  assert(tp->id == 1);
  assert(tp->coords[0] == 2);
  assert(tp->coords[1] == 3);
  assert(tp->coords[2] == EDGE_SUP);
  assert(tp->player_id == 1);
  assert(tp->rotation == ROT_ABS_A);
  assert(tp->triomino == t);

  t_placement_destroy(tp);
}

int main(void) {
  test_t_placement_create();
  test_t_placement_create_full();

  return 0;
}
