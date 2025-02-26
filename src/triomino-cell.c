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
#include "triomino-slot.h"

#include "triomino.inc"

TriominoCell *triomino_cell_create()
{
  TriominoCell *cell;

  if (NULL != (cell = malloc(sizeof(TriominoCell))))
  {
    cell->slots[EDGE_INF] = NULL;
    cell->slots[EDGE_SUP] = NULL;
  }

  return cell;
}

void triomino_cell_destroy(TriominoCell *cell)
{
  if (cell->slots[EDGE_INF])
  {
    triomino_slot_destroy(cell->slots[EDGE_INF]);
  }
  if (cell->slots[EDGE_SUP])
  {
    triomino_slot_destroy(cell->slots[EDGE_SUP]);
  }

  free(cell);
}
