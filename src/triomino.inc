/**
 * @file       triomino.inc
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

enum _rotation_t
{
  ROT_45,
  ROT_135,
  ROT_225,
  ROT_270
};

enum _slot_t
{
  SLOT_BOTTOM,
  SLOT_TOP
};

struct _coords_t
{
  unsigned int x;
  unsigned int y;
};

struct _Triomino
{
  unsigned char a;
  unsigned char b;
  unsigned char c;
};

struct _TriominoPos
{
  struct _coords_t coords;
  enum _rotation_t rotation;
  enum _slot_t slot;
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
  struct _Triomino *triomino;
  struct _TriominoPos *pos;
  struct _TriominoTile *prev;
};

struct _TriominoCell
{
  struct _TriominoTile *tiles[2];
};

struct _TriominoGrid
{
  struct _TriominoCell **cells;
  unsigned int width;
  unsigned int height;
};
