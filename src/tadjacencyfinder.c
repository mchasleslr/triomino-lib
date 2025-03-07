/**
 * @file       tadjacencyfinder.c
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#include "tadjacencyfinder.h"

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "ttypes.h"
#include "tconstants.h"
#include "tgrid.h"
#include "tplacement.h"
#include "tmem.h"

// ----------------------------------------------------------------------------

static TPlacement *_find_sxy(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_SXY
{
  // It exists and it's unique
  return t_grid_get_placement(grid, x, y, !edge);
}

static TPlacement *_find_sx(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_SX
{
  // Horizontal side adjacent's placement, if exists it's unique
  TPlacement *sx_adj = NULL;

  // Located before or after depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN)
  {
    sx_adj = t_grid_get_placement(grid, x - 1, y, !edge); // before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1)
  {
    sx_adj = t_grid_get_placement(grid, x + 1, y, !edge); // after
  }

  return sx_adj;
}

static TPlacement *_find_cx1(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CX1
{
  // If it exists, it's unique
  TPlacement *cx1_adj = NULL;

  // Located before or after depending on the edge
  if (edge == EDGE_INF && x < grid->size - 1)
  {
    cx1_adj = t_grid_get_placement(grid, x + 1, y, edge); // after
  }
  else if (edge == EDGE_SUP && x > GRID_XMIN)
  {
    cx1_adj = t_grid_get_placement(grid, x - 1, y, edge); // before
  }

  return cx1_adj;
}

static TPlacement *_find_cx2(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CX2
{
  // If it exists, it's unique
  TPlacement *cx2_adj = NULL;

  // Located before or after depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN)
  {
    cx2_adj = t_grid_get_placement(grid, x - 1, y, edge); // before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1)
  {
    cx2_adj = t_grid_get_placement(grid, x + 1, y, edge); // after
  }

  return cx2_adj;
}

static TPlacement *_find_sy(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_SY
{
  // Vertical side adjacent's placement, if exists it's unique
  TPlacement *y_adj = NULL;

  // Located below or above depending on the edge
  if (edge == EDGE_SUP && y > GRID_YMIN)
  {
    y_adj = t_grid_get_placement(grid, x, y - 1, !edge); // below
  }
  else if (edge == EDGE_INF && y < grid->size - 1)
  {
    y_adj = t_grid_get_placement(grid, x, y + 1, !edge); // above
  }

  return y_adj;
}

static TPlacement *_find_cy1(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CY1

{
  // If it exists, it's unique
  TPlacement *cy1_adj = NULL;

  // Located below or above depending on the edge
  if (edge == EDGE_INF && y < grid->size - 1)
  {
    cy1_adj = t_grid_get_placement(grid, x, y + 1, edge); // below
  }
  else if (edge == EDGE_SUP && y > GRID_YMIN)
  {
    cy1_adj = t_grid_get_placement(grid, x, y - 1, edge); // above
  }

  return cy1_adj;
}

static TPlacement *_find_cy2(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CY2

{
  // If it exists, it's unique
  TPlacement *cy2_adj = NULL;

  // Located below or above depending on the edge
  if (edge == EDGE_INF && y > GRID_YMIN)
  {
    cy2_adj = t_grid_get_placement(grid, x, y - 1, edge); // above
  }
  else if (edge == EDGE_SUP && y < grid->size - 1)
  {
    cy2_adj = t_grid_get_placement(grid, x, y + 1, edge); // below
  }

  return cy2_adj;
}

static TPlacement *_find_ctrans1(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CTRANS1
{
  // If it exists, it's unique
  TPlacement *ctrans1_adj = NULL;

  // Located below and after or above and before depending on the edge
  if (edge == EDGE_INF && x < grid->size - 1 && y < grid->size - 1)
  {
    ctrans1_adj = t_grid_get_placement(grid, x + 1, y + 1, !edge); // below and after
  }
  else if (edge == EDGE_SUP && x > GRID_XMIN && y > GRID_YMIN)
  {
    ctrans1_adj = t_grid_get_placement(grid, x - 1, y - 1, !edge); // above and before
  }

  return ctrans1_adj;
}

static TPlacement *_find_ctrans2(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CTRANS2
{
  // If it exists, it's unique
  TPlacement *ctrans2_adj = NULL;

  // Located below and after or above and before depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN && y > GRID_YMIN)
  {
    ctrans2_adj = t_grid_get_placement(grid, x - 1, y - 1, !edge); // above and before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1 && y < grid->size - 1)
  {
    ctrans2_adj = t_grid_get_placement(grid, x + 1, y + 1, !edge); // below and after
  }

  return ctrans2_adj;
}

static TPlacement *_find_ccis1(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CCIS1
{
  // If it exists, it's unique
  TPlacement *ccis1_adj = NULL;

  // Located below and after or above and before depending on the edge
  if (edge == EDGE_INF && x < grid->size - 1 && y < grid->size - 1)
  {
    ccis1_adj = t_grid_get_placement(grid, x + 1, y + 1, edge); // below and after
  }
  else if (edge == EDGE_SUP && x > GRID_XMIN && y > GRID_YMIN)
  {
    ccis1_adj = t_grid_get_placement(grid, x - 1, y - 1, edge); // above and before
  }

  return ccis1_adj;
}

static TPlacement *_find_ccis2(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CCIS2
{
  // If it exists, it's unique
  TPlacement *ccis2_adj = NULL;

  // Located below and after or above and before depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN && y > GRID_YMIN)
  {
    ccis2_adj = t_grid_get_placement(grid, x - 1, y - 1, edge); // above and before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1 && y < grid->size - 1)
  {
    ccis2_adj = t_grid_get_placement(grid, x + 1, y + 1, edge); // below and after
  }

  return ccis2_adj;
}

static TPlacement *_find_copp(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_COPP
{
  // If it exists, it's unique
  TPlacement *copp_adj = NULL;

  // Located below and before or above and after depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN && y < grid->size - 1)
  {
    copp_adj = t_grid_get_placement(grid, x - 1, y + 1, !edge); // below and before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1 && y > GRID_YMIN)
  {
    copp_adj = t_grid_get_placement(grid, x + 1, y - 1, !edge); // above and after
  }

  return copp_adj;
}

TAdjacencyFinder *t_adjacency_finder_create(TGrid *grid, TPlacement *ref)
{
  TAdjacencyFinder *finder = t_malloc(sizeof(TAdjacencyFinder));

  finder->grid = grid;
  finder->ref = ref;

  return finder;
}

void t_adjacency_destroy(TAdjacencyFinder *finder)
{

  // Important: it doesn't destroy the grid, neither the concerned placement
  free(finder);
}

// TODO: exit code or void return.
TAdjacencyFinder *t_adjacency_finder_set_strategy(TAdjacencyFinder *finder, int context)
{
  switch (context)
  {
  case POS_REL_SXY:
    finder->strategy = _find_sxy;
    break;
  case POS_REL_SX:
    finder->strategy = _find_sx;
    break;
  case POS_REL_SY:
    finder->strategy = _find_sy;
    break;
  case POS_REL_CX1:
    finder->strategy = _find_cx1;
    break;
  case POS_REL_CX2:
    finder->strategy = _find_cx2;
    break;
  case POS_REL_CY1:
    finder->strategy = _find_cy1;
    break;
  case POS_REL_CY2:
    finder->strategy = _find_cy2;
    break;
  case POS_REL_CTRANS1:
    finder->strategy = _find_ctrans1;
    break;
  case POS_REL_CTRANS2:
    finder->strategy = _find_ctrans2;
    break;
  case POS_REL_CCIS1:
    finder->strategy = _find_ccis1;
    break;
  case POS_REL_CCIS2:
    finder->strategy = _find_ccis2;
    break;
  case POS_REL_COPP:
    finder->strategy = _find_copp;
    break;
  }

  return finder;
}

TPlacement *t_adjacency_finder_exec_strategy(TAdjacencyFinder *finder)
{
  unsigned int x = t_placement_get_x(finder->ref);
  unsigned int y = t_placement_get_y(finder->ref);
  unsigned char edge = t_placement_get_edge(finder->ref);

  return finder->strategy(finder->grid, x, y, edge);
}
