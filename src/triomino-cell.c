/**
 * @file       triomino-cell.c
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include "triomino-cell.h"

#include <stdlib.h>
#include <stdio.h>

#include "triomino-types.h"

#include "triomino.inc"

TriominoCell *triomino_cell_create_empty()
{
  TriominoCell *cell;

  if (NULL != (cell = malloc(sizeof(TriominoCell))))
  {
    cell->tiles[0] = NULL;
    cell->tiles[1] = NULL;
  }

  return cell;
}

void triomino_cell_destroy(TriominoCell *cell)
{
  if (cell->tiles[0])
  {
    triomino_tile_destroy(cell->tiles[0]);
  }
  if (cell->tiles[1])
  {
    triomino_tile_destroy(cell->tiles[1]);
  }

  free(cell);
}
