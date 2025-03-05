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

struct _TriominoCompatibility
{
  bool (*strategy)(const Triomino *, const Triomino *);
};
