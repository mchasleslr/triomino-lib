/**
 * @file       triomino.inc
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

#include "triomino-types.h"

struct _Triomino
{
  unsigned char a;
  unsigned char b;
  unsigned char c;
};

struct _TriominoTile
{
  unsigned char player_id;
  struct _Triomino *triomino;
  rot_t rotation;
};

struct _TriominoSlot
{
  coord_t coord[2];
  edge_t edge;
  struct _TriominoTile *tile;
};

struct _TriominoCell
{
  struct _TriominoSlot *slots[2];
};

struct _TriominoGrid
{
  unsigned int width;
  unsigned int height;
  struct _TriominoCell ***cells;
};
