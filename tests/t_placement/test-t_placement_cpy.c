/**
 * @file       test-t_placement_cpy.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "tconstants.h"
#include "test-config.h"
#include "tplacement.h"
#include "triomino.inc"

static void test_with_non_null_dest() {
  Triomino *t1 = triomino_create_full(1, 2, 3);
  TPlacement *src = t_placement_create_full(1, 20, 30, EDGE_INF, ROT_ABS_A, t1);

  TPlacement *dest = t_placement_create(0, 0, EDGE_SUP);

  dest = t_placement_cpy(dest, src);

  assert(dest != NULL);
  assert(dest->coords[0] == src->coords[0]);
  assert(dest->coords[1] == src->coords[1]);
  assert(dest->coords[2] == src->coords[2]);
  assert(dest != src);
  assert(dest->player_id == src->player_id);
  assert(dest->triomino == src->triomino);

  t_placement_destroy(src);
  free(dest);
}

static void test_with_null_dest() {
  Triomino *t1 = triomino_create_full(1, 2, 3);
  TPlacement *src = t_placement_create_full(1, 20, 30, EDGE_INF, ROT_ABS_A, t1);

  TPlacement *dest = NULL;

  dest = t_placement_cpy(dest, src);

  assert(dest != NULL);
  assert(dest->coords[0] == src->coords[0]);
  assert(dest->coords[1] == src->coords[1]);
  assert(dest->coords[2] == src->coords[2]);
  assert(dest != src);
  assert(dest->player_id == src->player_id);
  assert(dest->triomino == src->triomino);

  t_placement_destroy(src);
  free(dest);
}

static void test_with_null_src() {
  TPlacement *src = NULL;

  TPlacement *dest = t_placement_create(0, 0, EDGE_SUP);

  dest = t_placement_cpy(dest, src);

  assert(dest != NULL);
  assert(dest->coords[0] == 0);
  assert(dest->coords[1] == 0);
  assert(dest->coords[2] == EDGE_SUP);
  assert(dest->player_id == _UNDEFINED);
  assert(dest->rotation == _UNDEFINED);
  assert(dest->triomino == NULL);

  free(dest);
}

int main(void) {
  test_with_non_null_dest();
  test_with_null_dest();
  test_with_null_src();
  return EXIT_SUCCESS;
}
