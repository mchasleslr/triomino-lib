#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "types.h"
#include "triomino-cell.h"
#include "triomino-grid.h"

int main(void)
{
  const unsigned int grid_width = 8;
  const unsigned int grid_height = 8;

  TriominoGrid *grid = triomino_grid_init(grid_width, grid_height);

  Triomino *t1 = triomino_create_full(0, 0, 0);
  Triomino *t2 = triomino_create_full(1, 1, 1);
  Triomino *t3 = triomino_create_full(2, 2, 2);
  Triomino *t4 = triomino_create_full(3, 3, 3);
  Triomino *t5 = triomino_create_full(4, 4, 4);
  Triomino *t6 = triomino_create_full(5, 5, 5);

  triomino_grid_put_tile(grid, t1, 1, 0, 0, SLOT_BOTTOM, ROT_270, NULL);
  triomino_grid_put_tile(grid, t2, 1, 0, 0, SLOT_TOP, ROT_270, NULL);
  triomino_grid_put_tile(grid, t3, 1, 0, 1, SLOT_TOP, ROT_270, NULL);
  triomino_grid_put_tile(grid, t4, 1, 1, 0, SLOT_BOTTOM, ROT_270, NULL);
  triomino_grid_put_tile(grid, t5, 1, 1, 1, SLOT_TOP, ROT_270, NULL);
  triomino_grid_put_tile(grid, t6, 1, 1, 1, SLOT_BOTTOM, ROT_270, NULL);

  unsigned int i, j;

  for (i = 0; i < grid_height; i++)
  {
    for (j = 0; j < grid_width; j++)
    {
      printf("[");
      TriominoTile *tile_bottom = triomino_grid_get_tile(grid, j, i, SLOT_BOTTOM);
      TriominoTile *tile_top = triomino_grid_get_tile(grid, j, i, SLOT_TOP);
      if (tile_bottom)
      {
        printf("%s", triomino_to_string(triomino_tile_get_triomino(tile_bottom)));
      }
      else
      {
        printf("     ");
      }
      printf("|");
      if (tile_top)
      {
        printf("%s", triomino_to_string(triomino_tile_get_triomino(tile_top)));
      }
      else
      {
        printf("     ");
      }
      printf("]");
    }
    printf("\n");
  }

  TriominoTile *target1 = triomino_grid_get_tile(grid, 0, 0, SLOT_TOP);

  printf("Finding adjacent's tiles to target1...\n");
  // sleep(3);

  Set *target1_adjacents;

  if (NULL != (target1_adjacents = triomino_grid_get_adjacents_tiles(grid, target1)))
  {
    SetIterator *iterator;

    for (iterator = set_iterator_create(target1_adjacents); set_iterator_has_next(iterator); iterator = set_iterator_next(iterator))
    {
      TriominoTile *adj = set_iterator_get(iterator);
      printf("[%d] %s\n", set_iterator_index(iterator), triomino_to_string(triomino_tile_get_triomino(adj)));
    }

    set_iterator_destroy(iterator);
  }

  triomino_grid_destroy(grid);

  return EXIT_SUCCESS;
}
