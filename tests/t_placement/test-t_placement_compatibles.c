/**
 * @file       test-t_placement_compatibles.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "tconstants.h"
#include "test-config.h"
#include "tplacement.h"
#include "triomino.inc"

static void test_suite(void) {
  Triomino *t1 = triomino_create_full(1, 2, 3);
  Triomino *t2 = triomino_create_full(1, 3, 5);
  Triomino *t3 = triomino_create_full(1, 1, 5);
  Triomino *t4 = triomino_create_full(2, 2, 4);
  Triomino *t5 = triomino_create_full(1, 2, 2);

  Triomino *t6 = triomino_create_full(1, 1, 2);
  Triomino *t7 = triomino_create_full(1, 1, 1);
  Triomino *t8 = triomino_create_full(1, 1, 4);
  Triomino *t9 = triomino_create_full(1, 4, 4);

  Triomino *t10 = triomino_create_full(4, 4, 4);
  Triomino *t11 = triomino_create_full(4, 4, 5);
  Triomino *t12 = triomino_create_full(1, 4, 5);
  Triomino *t13 = triomino_create_full(1, 5, 5);
  Triomino *t14 = triomino_create_full(0, 1, 5);
  Triomino *t15 = triomino_create_full(0, 5, 5);
  Triomino *t16 = triomino_create_full(0, 0, 5);
  Triomino *t17 = triomino_create_full(3, 4, 4);
  Triomino *t18 = triomino_create_full(3, 3, 4);
  Triomino *t19 = triomino_create_full(1, 3, 4);
  Triomino *t20 = triomino_create_full(1, 1, 3);
  Triomino *t21 = triomino_create_full(0, 1, 1);
  Triomino *t22 = triomino_create_full(0, 0, 3);
  Triomino *t23 = triomino_create_full(0, 2, 3);
  Triomino *t24 = triomino_create_full(0, 1, 2);

  TPlacement *tp1 = t_placement_create_full(1, 0, 0, EDGE_INF, ROT_ABS_B, t1);
  TPlacement *tp2 = t_placement_create_full(1, 0, 0, EDGE_SUP, ROT_ABS_C, t2);

  TPlacement *tp3 = t_placement_create_full(1, 1, 0, EDGE_INF, ROT_ABS_B, t3);

  TPlacement *tp4 = t_placement_create_full(1, 0, 1, EDGE_INF, ROT_ABS_C, t4);
  TPlacement *tp5 = t_placement_create_full(1, 0, 1, EDGE_SUP, ROT_ABS_A, t5);

  TPlacement *tp6 = t_placement_create_full(1, 1, 1, EDGE_INF, ROT_ABS_C, t6);
  TPlacement *tp7 = t_placement_create_full(1, 1, 1, EDGE_SUP, ROT_ABS_A, t7);

  TPlacement *tp8 = t_placement_create_full(1, 2, 1, EDGE_INF, ROT_ABS_A, t8);

  TPlacement *tp9 = t_placement_create_full(1, 2, 2, EDGE_SUP, ROT_ABS_B, t9);

  TPlacement *tp10 = t_placement_create_full(1, 3, 2, EDGE_INF, ROT_ABS_A, t10);
  TPlacement *tp11 = t_placement_create_full(1, 3, 2, EDGE_SUP, ROT_ABS_C, t11);

  TPlacement *tp12 = t_placement_create_full(1, 4, 2, EDGE_INF, ROT_ABS_B, t12);
  TPlacement *tp13 = t_placement_create_full(1, 4, 2, EDGE_SUP, ROT_ABS_C, t13);

  TPlacement *tp14 = t_placement_create_full(1, 5, 2, EDGE_INF, ROT_ABS_B, t14);
  TPlacement *tp15 = t_placement_create_full(1, 5, 2, EDGE_SUP, ROT_ABS_C, t15);

  TPlacement *tp16 = t_placement_create_full(1, 6, 2, EDGE_INF, ROT_ABS_B, t16);

  TPlacement *tp17 = t_placement_create_full(1, 3, 3, EDGE_SUP, ROT_ABS_C, t17);

  TPlacement *tp18 = t_placement_create_full(1, 4, 3, EDGE_INF, ROT_ABS_B, t18);
  TPlacement *tp19 = t_placement_create_full(1, 4, 3, EDGE_SUP, ROT_ABS_A, t19);

  TPlacement *tp20 = t_placement_create_full(1, 5, 3, EDGE_INF, ROT_ABS_C, t20);
  TPlacement *tp21 = t_placement_create_full(1, 5, 3, EDGE_SUP, ROT_ABS_A, t21);

  TPlacement *tp22 = t_placement_create_full(1, 6, 3, EDGE_SUP, ROT_ABS_B, t22);

  TPlacement *tp23 = t_placement_create_full(1, 7, 3, EDGE_INF, ROT_ABS_C, t23);
  TPlacement *tp24 = t_placement_create_full(1, 7, 3, EDGE_SUP, ROT_ABS_B, t24);

  assert(t_placement_compatibles(tp1, tp2) == true);
  assert(t_placement_compatibles(tp1, tp3) == true);
  assert(t_placement_compatibles(tp1, tp4) == true);
  assert(t_placement_compatibles(tp1, tp5) == true);
  assert(t_placement_compatibles(tp1, tp6) == true);
  assert(t_placement_compatibles(tp1, tp7) == true);

  assert(t_placement_compatibles(tp1, tp8) == false);
  assert(t_placement_compatibles(tp1, tp9) == false);
  assert(t_placement_compatibles(tp1, tp10) == false);
  assert(t_placement_compatibles(tp1, tp11) == false);
  assert(t_placement_compatibles(tp1, tp12) == false);
  assert(t_placement_compatibles(tp1, tp13) == false);
  assert(t_placement_compatibles(tp1, tp14) == false);
  assert(t_placement_compatibles(tp1, tp15) == false);
  assert(t_placement_compatibles(tp1, tp16) == false);
  assert(t_placement_compatibles(tp1, tp17) == false);
  assert(t_placement_compatibles(tp1, tp18) == false);
  assert(t_placement_compatibles(tp1, tp19) == false);
  assert(t_placement_compatibles(tp1, tp20) == false);
  assert(t_placement_compatibles(tp1, tp21) == false);
  assert(t_placement_compatibles(tp1, tp22) == false);
  assert(t_placement_compatibles(tp1, tp23) == false);
  assert(t_placement_compatibles(tp1, tp24) == false);

  assert(t_placement_compatibles(tp2, tp1) == true);
  assert(t_placement_compatibles(tp2, tp3) == true);
  assert(t_placement_compatibles(tp2, tp5) == true);
  assert(t_placement_compatibles(tp2, tp6) == true);
  assert(t_placement_compatibles(tp2, tp7) == true);

  assert(t_placement_compatibles(tp2, tp4) == false);
  assert(t_placement_compatibles(tp2, tp8) == false);
  assert(t_placement_compatibles(tp2, tp9) == false);
  assert(t_placement_compatibles(tp2, tp10) == false);
  assert(t_placement_compatibles(tp2, tp11) == false);
  assert(t_placement_compatibles(tp2, tp12) == false);
  assert(t_placement_compatibles(tp2, tp13) == false);
  assert(t_placement_compatibles(tp2, tp14) == false);
  assert(t_placement_compatibles(tp2, tp15) == false);
  assert(t_placement_compatibles(tp2, tp16) == false);
  assert(t_placement_compatibles(tp2, tp17) == false);
  assert(t_placement_compatibles(tp2, tp18) == false);
  assert(t_placement_compatibles(tp2, tp19) == false);
  assert(t_placement_compatibles(tp2, tp20) == false);
  assert(t_placement_compatibles(tp2, tp21) == false);
  assert(t_placement_compatibles(tp2, tp22) == false);
  assert(t_placement_compatibles(tp2, tp23) == false);
  assert(t_placement_compatibles(tp2, tp24) == false);

  assert(t_placement_compatibles(tp3, tp1) == true);
  assert(t_placement_compatibles(tp3, tp2) == true);
  assert(t_placement_compatibles(tp3, tp5) == true);
  assert(t_placement_compatibles(tp3, tp6) == true);
  assert(t_placement_compatibles(tp3, tp7) == true);
  assert(t_placement_compatibles(tp3, tp8) == true);

  assert(t_placement_compatibles(tp3, tp4) == false);
  assert(t_placement_compatibles(tp3, tp9) == false);
  assert(t_placement_compatibles(tp3, tp10) == false);
  assert(t_placement_compatibles(tp3, tp11) == false);
  assert(t_placement_compatibles(tp3, tp12) == false);
  assert(t_placement_compatibles(tp3, tp13) == false);
  assert(t_placement_compatibles(tp3, tp14) == false);
  assert(t_placement_compatibles(tp3, tp15) == false);
  assert(t_placement_compatibles(tp3, tp16) == false);
  assert(t_placement_compatibles(tp3, tp17) == false);
  assert(t_placement_compatibles(tp3, tp18) == false);
  assert(t_placement_compatibles(tp3, tp19) == false);
  assert(t_placement_compatibles(tp3, tp20) == false);
  assert(t_placement_compatibles(tp3, tp21) == false);
  assert(t_placement_compatibles(tp3, tp22) == false);
  assert(t_placement_compatibles(tp3, tp23) == false);
  assert(t_placement_compatibles(tp3, tp24) == false);

  assert(t_placement_compatibles(tp4, tp1) == true);
  assert(t_placement_compatibles(tp4, tp5) == true);
  assert(t_placement_compatibles(tp4, tp6) == true);

  assert(t_placement_compatibles(tp4, tp2) == false);
  assert(t_placement_compatibles(tp4, tp3) == false);
  assert(t_placement_compatibles(tp4, tp7) == false);
  assert(t_placement_compatibles(tp4, tp8) == false);
  assert(t_placement_compatibles(tp4, tp9) == false);
  assert(t_placement_compatibles(tp4, tp10) == false);
  assert(t_placement_compatibles(tp4, tp11) == false);
  assert(t_placement_compatibles(tp4, tp12) == false);
  assert(t_placement_compatibles(tp4, tp13) == false);
  assert(t_placement_compatibles(tp4, tp14) == false);
  assert(t_placement_compatibles(tp4, tp15) == false);
  assert(t_placement_compatibles(tp4, tp16) == false);
  assert(t_placement_compatibles(tp4, tp17) == false);
  assert(t_placement_compatibles(tp4, tp18) == false);
  assert(t_placement_compatibles(tp4, tp19) == false);
  assert(t_placement_compatibles(tp4, tp20) == false);
  assert(t_placement_compatibles(tp4, tp21) == false);
  assert(t_placement_compatibles(tp4, tp22) == false);
  assert(t_placement_compatibles(tp4, tp23) == false);
  assert(t_placement_compatibles(tp4, tp24) == false);

  assert(t_placement_compatibles(tp5, tp1) == true);
  assert(t_placement_compatibles(tp5, tp2) == true);
  assert(t_placement_compatibles(tp5, tp3) == true);
  assert(t_placement_compatibles(tp5, tp4) == true);
  assert(t_placement_compatibles(tp5, tp6) == true);
  assert(t_placement_compatibles(tp5, tp7) == true);

  assert(t_placement_compatibles(tp24, tp23) == true);
  assert(t_placement_compatibles(tp24, tp22) == true);
  assert(t_placement_compatibles(tp24, tp16) == true);

  t_placement_destroy(tp1);
  t_placement_destroy(tp2);
  t_placement_destroy(tp3);
  t_placement_destroy(tp4);
  t_placement_destroy(tp5);
  t_placement_destroy(tp6);
  t_placement_destroy(tp7);
  t_placement_destroy(tp8);
  t_placement_destroy(tp9);
  t_placement_destroy(tp10);
  t_placement_destroy(tp11);
  t_placement_destroy(tp12);
  t_placement_destroy(tp13);
  t_placement_destroy(tp14);
  t_placement_destroy(tp15);
  t_placement_destroy(tp16);
  t_placement_destroy(tp17);
  t_placement_destroy(tp18);
  t_placement_destroy(tp19);
  t_placement_destroy(tp20);
  t_placement_destroy(tp21);
  t_placement_destroy(tp22);
  t_placement_destroy(tp23);
  t_placement_destroy(tp24);
}

int main(void) {
  test_suite();

  return EXIT_SUCCESS;
}
