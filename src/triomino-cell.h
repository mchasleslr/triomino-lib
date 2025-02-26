/**
 * @file       triomino-cell.h
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#ifndef _TRIOMINO_CELL_H
#define _TRIOMINO_CELL_H

#include "triomino-types.h"
#include "triomino-tile.h"

typedef struct _TriominoCell TriominoCell;

extern TriominoCell *triomino_cell_create_empty();
extern void triomino_cell_destroy(TriominoCell *cell);

#endif // _TRIOMINO_CELL_H
