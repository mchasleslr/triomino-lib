/**
 * @file       tgrid.c
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#include "tgrid.h"

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "ttypes.h"
#include "tconstants.h"
#include "tplacement.h"
#include "tadjacencyfinder.h"

// ----------------------------------------------------------------------------

TGrid *t_grid_create(unsigned int size)
{
  TGrid *grid = t_malloc(sizeof(TGrid));

  grid->size = size;

  unsigned int x, y;

  grid->placements = t_malloc(size * sizeof(TPlacement **));

  for (y = GRID_YMIN; y < size; y++)
  {
    grid->placements[y] = t_malloc(2 * size * sizeof(TPlacement *));
    for (x = GRID_XMIN; x < size * 2; x++)
    {
      grid->placements[y][x] = t_placement_create(x / 2, y, x % 2);
    }
  }

  return grid;
}

void t_grid_destroy(TGrid *grid)
{
  unsigned int i, j;

  for (i = 0; i < grid->size; i++)
  {
    for (j = 0; j < grid->size * 2; j++)
    {
      t_placement_destroy(grid->placements[i][j]);
    }
    free(grid->placements[i]);
  }
  free(grid->placements);
  free(grid);
}

void t_grid_display(TGrid *grid)
{
  unsigned int i, j;
  for (i = 0; i < grid->size; i++)
  {
    for (j = 0; j < grid->size; j++)
    {
      printf("|");
      printf("%s / ", t_placement_to_string(t_grid_get_placement(grid, j, i, EDGE_INF)));
      printf("%s|", t_placement_to_string(t_grid_get_placement(grid, j, i, EDGE_SUP)));
    }
    printf("\n");
  }
}

unsigned int t_grid_get_size(TGrid *grid)
{
  assert("t_grid_get_size: NULL pointer" && grid);

  return grid->size;
}

TPlacement *t_grid_get_placement(TGrid *grid, unsigned int x, unsigned int y, unsigned int edge)
{
  assert("t_grid_get_placement: NULL pointer" && grid);

  return grid->placements[y][2 * x + edge];
}

TPlacement *t_grid_fill_placement(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge, unsigned char rotation, Triomino *tile)
{
  TPlacement *placement = t_grid_get_placement(grid, x, y, edge);

  t_placement_set_rotation(placement, rotation);
  t_placement_set_triomino(placement, tile);

  return placement;
}

TPlacement *t_grid_commit_placement(TGrid *grid, TPlacement *staged)
{
  assert("t_grid_commit_placement: NULL pointer" && grid);

  TPlacement *target = t_grid_get_placement(grid, t_placement_get_x(staged), t_placement_get_y(staged), t_placement_get_edge(staged));
  t_placement_set_rotation(target, staged->rotation);
  t_placement_set_triomino(target, staged->triomino);
  free(staged);

  return target;
}

static bool _rm_full_adjacents(void *element)
{
  // Used as a callback, it removes the full slots
  TPlacement *tp = (TPlacement *)element;
  return t_placement_empty(tp);
}

static bool _rm_empty_adjacents(void *element)
{
  // Used as a callback, it removes the empty slots
  TPlacement *tp = (TPlacement *)element;
  return !t_placement_empty(tp);
}

TSet *t_grid_get_adjacents(TGrid *grid, TPlacement *ref, int options)
{
  assert("t_grid_get_adjacents: NULL pointer" && grid && ref);

  TSet *adjacents = set_create();
  TAdjacencyFinder *finder = t_adjacency_finder_create(grid, ref);

  unsigned int start, end;
  bool (*filter)(void *);

  // In case constants get corrupted
  int pos_rel[] = {
      //          Side adjacents        //
      POS_REL_SXY,
      POS_REL_SX,
      POS_REL_SY,
      //         Corner adjacents       //
      POS_REL_CCIS1,
      POS_REL_CCIS2,
      POS_REL_COPP,
      POS_REL_CTRANS1,
      POS_REL_CTRANS2,
      POS_REL_CX1,
      POS_REL_CX2,
      POS_REL_CY1,
      POS_REL_CY2};

  // For collecting only side adjacents
  if (options & ADJ_SIDE)
  {
    start = 0;
    end = 3;
  }
  // For collecting only corner adjacents
  else if (options & ADJ_CORNER)
  {
    start = 3;
    end = _NPOS_REL;
  }
  // For collecting both
  else
  {
    start = 0;
    end = _NPOS_REL;
  }

  // Removes placements without triomino
  if (options & ADJ_FULL)
  {
    filter = _rm_empty_adjacents;
  }
  // Removes placements with triomino
  else if (options & ADJ_EMPTY)
  {
    filter = _rm_full_adjacents;
  }
  // This case should never append, just in case
  else
  {
    filter = NULL;
  }

  for (unsigned int i = start; i < end; i++)
  {
    finder = t_adjacency_finder_set_strategy(finder, pos_rel[i]);
    adjacents = set_add(adjacents, (TPlacement *)t_adjacency_finder_exec_strategy(finder));
  }

  t_adjacency_destroy(finder);

  // If <filter> set to NULL returns all adjacents previously collected
  if (filter)
  {
    adjacents = set_filter(adjacents, filter);
  }

  // Just in case
  if (set_empty(adjacents))
  {
    set_destroy(adjacents);
    return NULL;
  }

  return adjacents;
}

bool t_grid_valid_placement(TGrid *grid, TPlacement *candidate)
{
  assert("t_grid_valid_placement: NULL pointer" && grid && candidate);
  assert("t_grid_valid_placement: candidate rotation undefined" && candidate->rotation != _UNDEFINED);
  assert("t_grid_valid_placement: candidate triomino undefined" && candidate->triomino);

  bool valid = true;

  TSet *adjacents_tiles = t_grid_get_adjacents(grid, candidate, ADJ_DEFAULT | ADJ_FULL);

  SetIterator *it = set_iterator_create(adjacents_tiles);

  while (valid && set_iterator_has_next(it))
  {
    TPlacement *target = set_iterator_get(it);

    if (!t_placement_compatibles(candidate, target))
    {
      valid = false;
    }

    set_iterator_next(it);
  }

  set_iterator_destroy(it);
  set_destroy(adjacents_tiles);

  return valid;
}
