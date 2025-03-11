/**
 * @file       test-t_grid_create-destroy.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "test-config.h"
#include "tgrid.h"
#include "triomino.inc"

static void test_t_grid_create_destroy(void) {
  TGrid *grid = t_grid_create(3);

  assert(grid != NULL);

  t_grid_destroy(grid);
}

int main(void) {
  test_t_grid_create_destroy();

  return 0;
}
