/**
 * @file       test-t_placement_setters.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "test-config.h"

#include "tconstants.h"
#include "tplacement.h"

#include "triomino.inc"

static void test_t_placement_set_player_id(void)
{
  TPlacement *tp = t_placement_create(1, 2, EDGE_INF);

  tp = t_placement_set_player_id(tp, 1);

  assert(tp != NULL);
  assert(tp->player_id == 1);

  t_placement_destroy(tp);
}

static void test_t_placement_set_rotation(void)
{
  TPlacement *tp = t_placement_create(1, 2, EDGE_INF);

  tp = t_placement_set_rotation(tp, ROT_ABS_A);

  assert(tp != NULL);
  assert(tp->rotation == ROT_ABS_A);

  t_placement_destroy(tp);
}

static void test_t_placement_set_triomino(void)
{
  Triomino *t = triomino_create_full(0, 0, 0);
  TPlacement *tp = t_placement_create(1, 2, EDGE_INF);

  tp = t_placement_set_triomino(tp, t);

  assert(tp != NULL);
  assert(tp->triomino == t);

  t_placement_destroy(tp);
}

static void test_t_placement_clear_out(void)
{
  Triomino *t = triomino_create_full(0, 0, 0);
  TPlacement *tp = t_placement_create_full(1, 2, 3, EDGE_SUP, ROT_ABS_A, t);

  t_placement_clear_out(tp);

  assert(tp != NULL);
  assert(tp->player_id == _UNDEFINED);
  assert(tp->rotation == _UNDEFINED);
  assert(tp->triomino == NULL);

  t_placement_destroy(tp);
  triomino_destroy(t);
}

int main(void)
{
  test_t_placement_set_player_id();
  test_t_placement_set_rotation();
  test_t_placement_set_triomino();
  test_t_placement_clear_out();

  return EXIT_SUCCESS;
}
