/**
 * @file       test-t_grid_fill_placement.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "tconstants.h"
#include "test-config.h"
#include "tgrid.h"
#include "tplacement.h"
#include "triomino.h"
#include "triomino.inc"

static void test_t_grid_fill_placement(void) {
  TGrid *grid = t_grid_create(3);

  Triomino *triomino = triomino_create_full(1, 2, 3);

  TPlacement *tp = t_grid_get_placement(grid, 0, 0, EDGE_INF);

  t_grid_fill_placement(grid, 0, 0, EDGE_INF, ROT_ABS_B, triomino);

  assert(t_placement_get_triomino(tp) == triomino);
  assert(t_placement_get_rotation(tp) == ROT_ABS_B);

  t_grid_destroy(grid);
}

int main(void) {
  test_t_grid_fill_placement();

  return EXIT_SUCCESS;
}
