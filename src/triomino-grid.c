/**
 * @file       triomino-grid.c
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include "triomino-grid.h"

#include <stdlib.h>
#include <stdio.h>

#include "triomino-types.h"
#include "triomino-slot.h"
#include "triomino-cell.h"
#include "set.h"

#include "triomino.inc"

TriominoGrid *triomino_grid_create(unsigned int width, unsigned int height)
{
  TriominoGrid *grid;

  if (NULL != (grid = malloc(sizeof(TriominoGrid))))
  {
    grid->height = height;
    grid->width = width;
    grid->cells = NULL;
  }

  return grid;
}

TriominoGrid *triomino_grid_init(unsigned int width, unsigned int height)
{
  TriominoGrid *grid = triomino_grid_create(width, height);

  if (grid == NULL)
  {
    return grid;
  }

  unsigned int i, j;

  grid->cells = malloc(height * sizeof(TriominoCell *));

  for (i = GRID_YMIN; i < height; i++)
  {
    grid->cells[i] = malloc(width * sizeof(TriominoCell));

    for (j = GRID_XMIN; j < width; j++)
    {
      grid->cells[i][j] = triomino_cell_create();
    }
  }

  return grid;
}

void triomino_grid_destroy(TriominoGrid *grid)
{
  unsigned int i, j;

  for (i = GRID_YMIN; i < grid->height; i++)
  {
    for (j = GRID_XMIN; j < grid->width; j++)
    {
      TriominoCell *c = grid->cells[i][j];
      triomino_cell_destroy(c);
    }
    free(grid->cells[i]);
  }

  free(grid->cells);
  free(grid);
}

TriominoTile *triomino_grid_insert_tile(TriominoGrid *grid, TriominoTile *tile, coord_t x, coord_t y, edge_t edge)
{
  grid->cells[y][x]->slots[edge] = tile;

  return tile;
}

TriominoTile *triomino_grid_get_tile(TriominoGrid *grid, coord_t x, coord_t y, edge_t edge)
{
  return grid->cells[y][x]->slots[edge];
}

TriominoSlot *triomino_grid_get_slot_above(TriominoGrid *grid, TriominoSlot *slot)
{
  TriominoSlot *s_above = NULL;

  if (slot)
  {
    coord_t x = triomino_slot_get_x(slot);
    coord_t y = triomino_slot_get_y(slot);

    if (triomino_slot_on_inf_edge(slot))
    {
      s_above = triomino_grid_get_tile(grid, x, y, EDGE_SUP);
    }
    else if (triomino_slot_on_sup_edge(slot) && !triomino_slot_ymin(slot, GRID_YMIN))
    {
      s_above = triomino_grid_get_tile(grid, x, y - 1, EDGE_INF);
    }
  }

  return s_above;
}

TriominoTile *triomino_grid_get_slot_below(TriominoGrid *grid, TriominoSlot *slot)
{
  TriominoTile *s_below = NULL;
  if (slot)
  {
    coord_t x = triomino_slot_get_x(slot);
    coord_t y = triomino_slot_get_y(slot);

    if (triomino_slot_on_sup_edge(slot))
    {
      s_below = triomino_grid_get_tile(grid, x, y, SLOT_BOTTOM);
    }
    else if (triomino_tile_on_bottom_slot(tile) && !triomino_tile_ymax(tile, grid->height))
    {
      s_below = triomino_grid_get_tile(grid, x, y + 1, SLOT_TOP);
    }
  }

  return tile_below;
}

TriominoTile *triomino_grid_get_tile_before(TriominoGrid *grid, TriominoTile *tile)
{
  TriominoTile *tile_before = NULL;

  if (tile)
  {
    coord_t x = triomino_tile_get_x(tile);
    coord_t y = triomino_tile_get_y(tile);

    if (triomino_tile_on_bottom_slot(tile) && !triomino_tile_xmin(tile, GRID_XMIN))
    {
      tile_before = triomino_grid_get_tile(grid, x - 1, y, SLOT_TOP);
    }
  }

  return tile_before;
}

TriominoTile *triomino_grid_get_tile_after(TriominoGrid *grid, TriominoTile *tile)
{
  TriominoTile *tile_after = NULL;

  if (tile)
  {
    coord_t x = triomino_tile_get_x(tile);
    coord_t y = triomino_tile_get_y(tile);

    if (triomino_tile_on_top_slot(tile) && !triomino_tile_xmax(tile, grid->width))
    {
      tile_after = triomino_grid_get_tile(grid, x + 1, y, SLOT_BOTTOM);
    }
  }

  return tile_after;
}

Set *triomino_grid_get_adjacents_tiles(TriominoGrid *grid, TriominoTile *tile)
{
  Set *adjacents = set_create();

  adjacents = set_add(adjacents, (TriominoTile *)triomino_grid_get_tile_above(grid, tile));
  adjacents = set_add(adjacents, (TriominoTile *)triomino_grid_get_tile_after(grid, tile));
  adjacents = set_add(adjacents, (TriominoTile *)triomino_grid_get_tile_below(grid, tile));
  adjacents = set_add(adjacents, (TriominoTile *)triomino_grid_get_tile_before(grid, tile));

  if (set_empty(adjacents))
  {
    set_destroy(adjacents);
    return NULL;
  }

  return adjacents;
}
