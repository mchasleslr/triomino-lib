/**
 * @file       triomino.inc
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

#include "types.h"

struct _Triomino
{
  unsigned char a;
  unsigned char b;
  unsigned char c;
};

struct _TriominoPos
{
  unsigned int coords[2];
  enum _slot_t slot;
  enum _rot_t rotation;
};

struct _TriominoPlayer
{
  unsigned int id;
  char name[32];
  struct _Triomino **triominoes;
};

struct _TriominoTile
{
  unsigned int player_id;
  struct _TriominoPos *pos;
  struct _Triomino *triomino;
  struct _TriominoTile *prev_played;
};

struct _TriominoCell
{
  struct _TriominoTile *tiles[2];
};

struct _TriominoGrid
{
  struct _TriominoCell ***cells;
  unsigned int width;
  unsigned int height;
};
