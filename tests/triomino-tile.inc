/**
 * @file triomino-tile.inc
 * @brief Triomino tile structure
 *
 * @author Maxime Chasles
 * @date 2025
 * @copyright BSD 3-Clause License
 */

#include "triomino.h"
#include "triomino-pos.h"
#include "triomino-player.h"

struct _TriominoTile {
    TriominoPos *pos;
    TriominoPlayer *player;
    Triomino *triomino;
};
