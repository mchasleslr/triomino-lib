/**
 * @file       test-t_placement_getters.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "test-config.h"

#include "tconstants.h"
#include "tplacement.h"

#include "triomino.inc"

static void test_t_placement_get_x(void)
{
  TPlacement *tp = t_placement_create(1, 2, EDGE_INF);

  assert(t_placement_get_x(tp) == 1);

  t_placement_destroy(tp);
}

static void test_t_placement_get_y(void)
{
  TPlacement *tp = t_placement_create(1, 2, EDGE_INF);

  assert(t_placement_get_y(tp) == 2);

  t_placement_destroy(tp);
}

static void test_t_placement_get_edge(void)
{
  TPlacement *tp = t_placement_create(1, 2, EDGE_INF);

  assert(t_placement_get_edge(tp) == EDGE_INF);

  t_placement_destroy(tp);
}

static void test_t_placement_get_rotation(void)
{
  TPlacement *tp = t_placement_create_full(1, 2, 3, EDGE_SUP, ROT_ABS_A, NULL);

  assert(t_placement_get_rotation(tp) == ROT_ABS_A);

  t_placement_destroy(tp);
}

static void test_t_placement_get_player_id(void)
{
  TPlacement *tp = t_placement_create_full(1, 2, 3, EDGE_SUP, ROT_ABS_A, NULL);

  assert(t_placement_get_player_id(tp) == 1);

  t_placement_destroy(tp);
}

static void test_t_placement_get_triomino(void)
{
  Triomino *t = triomino_create_full(0, 0, 0);
  TPlacement *tp = t_placement_create_full(1, 2, 3, EDGE_SUP, ROT_ABS_A, t);

  assert(t_placement_get_triomino(tp) == t);

  t_placement_destroy(tp);
}

static void test_t_placement_empty(void)
{
  TPlacement *tp = t_placement_create(1, 2, EDGE_INF);

  assert(t_placement_empty(tp));

  t_placement_destroy(tp);
}

int main(void)
{
  test_t_placement_get_x();
  test_t_placement_get_y();
  test_t_placement_get_edge();
  test_t_placement_get_rotation();
  test_t_placement_get_player_id();
  test_t_placement_get_triomino();
  test_t_placement_empty();

  return EXIT_SUCCESS;
}
