/**
 * @file       triomino-types.h
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#ifndef _TRIOMINO_TYPES_H
#define _TRIOMINO_TYPES_H

// ----------------------------------------------------------------------------

#include <stdint.h>

#include "set.h"

// ----------------------------------------------------------------------------

/**
 * @brief Alias for a set of triominos.
 */
typedef Set TriominoSet;

/**
 * @brief Alias for an edge of a slot.
 */
typedef uint8_t edge_t;

/**
 * @brief An alias for a rotation.
 */
typedef uint8_t rotation_t;

/**
 * @brief An 8-bit flags for general purpose.
 */
typedef uint8_t flags8_t;

#endif // _TRIOMINO_TYPES_H
