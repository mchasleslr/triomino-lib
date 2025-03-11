/**
 * @file       test-t_grid_getters.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "tconstants.h"
#include "test-config.h"
#include "tgrid.h"
#include "triomino.inc"

static void test_t_grid_getters(void) {
  TGrid *grid = t_grid_create(3);

  assert(t_grid_get_size(grid) == 3);

  TPlacement *placement;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 2; k++) {
        placement = t_grid_get_placement(grid, i, j, k);
        assert(t_placement_get_x(placement) == i);
        assert(t_placement_get_y(placement) == j);
        assert(t_placement_get_edge(placement) == k);
      }
    }
  }

  t_grid_destroy(grid);
}

int main(void) {
  test_t_grid_getters();
  return EXIT_SUCCESS;
}
