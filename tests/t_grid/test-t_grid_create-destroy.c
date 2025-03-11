#include "test-config.h"

#include "tgrid.h"

#include "triomino.inc"

static void test_t_grid_create_destroy(void)
{
  TGrid *grid = t_grid_create(3);

  assert(grid != NULL);

  t_grid_destroy(grid);
}

int main(void)
{
  test_t_grid_create_destroy();

  return 0;
}
