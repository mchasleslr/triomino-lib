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

#include "triomino-types.h"

/**
 * @brief Triomino type.
 *
 * @details A triomino is a tile composed of three numbers.
 */
struct _Triomino
{
  unsigned char a;
  unsigned char b;
  unsigned char c;
};

/**
 * @brief Triomino tile type.
 *
 * @details A triomino tile is a triomino associated to a player and a rotation.
 */
struct _TriominoTile
{
  struct _Triomino *triomino;
  unsigned int player_id;
  rotation_t rotation;
};

// TODO: add an <adjacent_slots> member ??
/**
 * @brief Triomino slot type.
 *
 * @details A triomino slot is a slot on the grid that can contain a tile.
 */
struct _TriominoSlot
{
  unsigned int coord[2];
  edge_t edge;
  struct _TriominoTile *tile;
};

/**
 * @brief Triomino cell type.
 *
 * @details A triomino cell is a container for two slots.
 */
struct _TriominoCell
{
  struct _TriominoSlot *slots[2];
};

/**
 * @brief Triomino grid type.
 *
 * @details A triomino grid is a grid of cells.
 */
struct _TriominoGrid
{
  unsigned int width;
  unsigned int height;
  struct _TriominoCell ***cells;
};

struct _TriominoCompatibilityCtx
{
  bool (*compatibility_strategy)(const Triomino *, const Triomino *);
};
