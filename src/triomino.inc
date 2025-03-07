/**
 * @file       triomino.inc
 *                  ___
 *             a  a     b  c
 *           /   \ \   / /   \
 *          c ___ b  c  b ___ a
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

struct _Triomino
{
  unsigned char a;
  unsigned char b;
  unsigned char c;
};

struct _TPlacement
{
  unsigned int id;
  unsigned int coords[3];
  unsigned char rotation;
  unsigned char player_id;
  struct _Triomino *triomino;
};

struct _TGrid
{
  unsigned int size;
  struct _TPlacement ***placements;
};

struct _TCompatibility
{
  struct _Triomino *ref;
  bool (*strategy)(const struct _Triomino *, const struct _Triomino *);
};

struct _TAdjacencyFinder
{
  struct _TGrid *grid;
  struct _TPlacement *ref;
  struct _TPlacement *(*strategy)(struct _TGrid *, unsigned int, unsigned int, unsigned char);
};
