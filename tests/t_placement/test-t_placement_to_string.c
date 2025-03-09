/**
 * @file       test-t_placement_to_string.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "test-config.h"

#include "tconstants.h"
#include "tplacement.h"

#include "triomino.inc"

static void test_with_null_triomino()
{
  TPlacement *tp = t_placement_create_full(1, 2, 3, EDGE_INF, ROT_ABS_A, NULL);

  char *str = t_placement_to_string(tp);

  printf("%s\n", str);

  assert(str != NULL);
  assert(strcmp(str, "[-(2, 3), (empty)]") == 0);

  t_placement_destroy(tp);
}

static void test_with_non_null_triomino()
{
  Triomino *t1 = triomino_create_full(1, 2, 3);
  TPlacement *tp = t_placement_create_full(1, 2, 3, EDGE_INF, ROT_ABS_A, t1);

  char *str = t_placement_to_string(tp);

  printf("%s\n", str);

  assert(str != NULL);
  assert(strcmp(str, "[-(2, 3), 1-2-3]") == 0);

  t_placement_destroy(tp);
}

int main(void)
{
  test_with_null_triomino();
  test_with_non_null_triomino();

  return EXIT_SUCCESS;
}
