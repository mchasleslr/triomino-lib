/**
 * @file       triomino-constants.h
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

#ifndef _TRIOMINO_CONSTANTS_H
#define _TRIOMINO_CONSTANTS_H

// ----------------------------------------------------------------------------

/**
 * Following constants define the edge of a slot.
 *
 * @see wiki/edge-specs
 */

/**
 * @brief The tile is on the inferior edge of the slot.
 */
#define EDGE_INF 0x00

/**
 * @brief The tile is on the superior edge of the slot.
 */
#define EDGE_SUP 0x01

// ----------------------------------------------------------------------------

/**
 * Following constants define the absolute rotation of a tile.
 *
 * @see wiki/absolute-rotations-specs
 */

/**
 * @brief The tile is oriented on rotation A.
 */
#define ROT_ABS_A 0x00

/**
 * @brief The tile is oriented on rotation B.
 */
#define ROT_ABS_B 0x01

/**
 * @brief The tile is oriented on rotation C.
 */
#define ROT_ABS_C 0x02

// ----------------------------------------------------------------------------

/**
 * Following constants define the relative position between two tiles.
 *
 * @see wiki/relative-positions-specs
 */

/**
 * @brief Error in the relative position of two tiles.
 */
#define POS_REL_ERR 0x00

/**
 * @brief Side opposites relation.
 */
#define POS_REL_SOPP 0x01

/**
 * @brief Side by side relation on the X axis.
 */
#define POS_REL_SX 0x02

/**
 * @brief Side by side relation on the Y axis.
 */
#define POS_REL_SY 0x03

/**
 * @brief Corner opposites relation.
 */
#define POS_REL_COPP 0x04

/**
 * @brief Corner by corner relation on a diagonal translation I.
 */
#define POS_REL_CDTR1 0x05

/**
 * @brief Corner by corner relation on a diagonal translation II.
 */
#define POS_REL_CDTR2 0x06

/**
 * @brief Corner by corner relation on a diagonal symetry I.
 */
#define POS_REL_CDSYM1 0x07

/**
 * @brief Corner by corner relation on a diagonal symetry II.
 */
#define POS_REL_CDSYM2 0x08

/**
 * @brief Corner by corner relation on X axis after is inf and before is sup.
 */
#define POS_REL_CXAIBS 0x09

/**
 * @brief Corner by corner relation on X axis before is inf and after is sup.
 */
#define POS_REL_CXBIAS 0x0a

/**
 * @brief Corner by corner relation on Y axis after is inf and before is sup.
 */
#define POS_REL_CYAIBS 0x0b

/**
 * @brief Corner by corner relation on Y axis before is inf and after is sup.
 */
#define POS_REL_CYBIAS 0x0c

// ----------------------------------------------------------------------------

/**
 * Following constants define the relative rotation between two tiles.
 *
 * @see wiki/relative-rotations-specs
 */

/**
 * @brief Error in the relative rotation of two tiles.
 */
#define ROT_REL_ERR 0x0

/**
 * @brief Tile 1 is rotated on A and tile 2 is rotated on A.
 */
#define ROT_REL_AA 0x10

/**
 * @brief Tile 1 is rotated on A and tile 2 is rotated on B.
 */
#define ROT_REL_AB 0x20

/**
 * @brief Tile 1 is rotated on A and tile 2 is rotated on C.
 */
#define ROT_REL_AC 0x30

/**
 * @brief Tile 1 is rotated on B and tile 2 is rotated on A.
 */
#define ROT_REL_BA 0x40

/**
 * @brief Tile 1 is rotated on B and tile 2 is rotated on B.
 */
#define ROT_REL_BB 0x50

/**
 * @brief Tile 1 is rotated on B and tile 2 is rotated on C.
 */
#define ROT_REL_BC 0x60

/**
 * @brief Tile 1 is rotated on C and tile 2 is rotated on A.
 */
#define ROT_REL_CA 0x70

/**
 * @brief Tile 1 is rotated on C and tile 2 is rotated on B.
 */
#define ROT_REL_CB 0x80

/**
 * @brief Tile 1 is rotated on C and tile 2 is rotated on C.
 */
#define ROT_REL_CC 0x90

#endif // _TRIOMINO_CONSTANTS_H
