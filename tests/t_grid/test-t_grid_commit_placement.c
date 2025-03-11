/**
 * @file       test-t_grid_commit_placement.c
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

static void test_t_grid_commit_placement(void) {
  TGrid *grid = t_grid_create(3);

  Triomino *triomino = triomino_create_full(1, 2, 3);

  TPlacement *staged =
      t_placement_create_full(1, 0, 0, EDGE_INF, ROT_ABS_B, triomino);

  TPlacement *committed = t_grid_commit_placement(grid, staged);

  assert(t_placement_get_triomino(committed) == triomino);
  assert(t_placement_get_rotation(committed) == ROT_ABS_B);

  t_grid_destroy(grid);
}

int main(void) {
  test_t_grid_commit_placement();

  return EXIT_SUCCESS;
}
