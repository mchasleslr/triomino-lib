/**
 * @file       tconstants.h
 *
 * This module provides the constants used in the project.
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#ifndef _TCONSTANTS_H
#define _TCONSTANTS_H

/** ---------------------------------------------------------------------------
 * @section General constants
 *
 *          Define the base constants used in the project.
 */

/**
 * @brief The undefined constant.
 *
 * @details This constant is used to represent an undefined value.
 */
#define _UNDEFINED 0x00

/**
 * @brief The minimum value for the x coordinate.
 */
#define GRID_XMIN 0x00

/**
 * @brief The minimum value for the y coordinate.
 */
#define GRID_YMIN 0x00

/**
 * @brief The inferior edge of a grid cell.
 */
#define EDGE_INF 0x00

/**
 * @brief The superior edge of a grid cell.
 */
#define EDGE_SUP 0x01

/** ---------------------------------------------------------------------------
 * @section Absolute rotations
 *
 *          Define the absolute rotation of a placement.
 */

/**
 * @brief The placement is on rotation A.
 *
 */
#define ROT_ABS_A 0x01

/**
 * @brief The placement is on rotation B.
 */
#define ROT_ABS_B 0x02

/**
 * @brief The placement is on rotation C.
 */
#define ROT_ABS_C 0x03

/** ---------------------------------------------------------------------------
 * @section Rotation relative
 *
 *          Define the relative rotation between two nonempty placements.
 *
 * @details The first 4 bits represent the rotation of the first placement.
 *          The last 4 bits represent the rotation of the second placement.
 *
 * @note    The first placement is the one that is used as a reference.
 *          The second placement is the one that is compared to the first one.
 */

/**
 * @brief Reference is on rotation A and target is on rotation A.
 */
#define ROT_REL_AA (ROT_ABS_A << 4 | ROT_ABS_A << 6)

/**
 * @brief Reference is on rotation A and target is on rotation B.
 */
#define ROT_REL_AB (ROT_ABS_A << 4 | ROT_ABS_B << 6)

/**
 * @brief Reference is on rotation A and target is on rotation C.
 */
#define ROT_REL_AC (ROT_ABS_A << 4 | ROT_ABS_C << 6)

/**
 * @brief Reference is on rotation B and target is on rotation A.
 */
#define ROT_REL_BA (ROT_ABS_B << 4 | ROT_ABS_A << 6)

/**
 * @brief Reference is on rotation B and target is on rotation B.
 */
#define ROT_REL_BB (ROT_ABS_B << 4 | ROT_ABS_B << 6)

/**
 * @brief Reference is on rotation B and target is on rotation C.
 */
#define ROT_REL_BC (ROT_ABS_B << 4 | ROT_ABS_C << 6)

/**
 * @brief Reference is on rotation C and target is on rotation A.
 */
#define ROT_REL_CA (ROT_ABS_C << 4 | ROT_ABS_A << 6)

/**
 * @brief Reference is on rotation C and target is on rotation B.
 */
#define ROT_REL_CB (ROT_ABS_C << 4 | ROT_ABS_B << 6)

/**
 * @brief Reference is on rotation C and target is on rotation C.
 */
#define ROT_REL_CC (ROT_ABS_C << 4 | ROT_ABS_C << 6)

/** ---------------------------------------------------------------------------
 * @section Position relative
 *
 *          Following constants define the relative position between two
 *          placements.
 *
 *          TODO: Add documentation for each constants.
 */

/**
 * @brief   The number of relative positions.
 *
 * @details This constant is used to define the number of relative positions.
 *          It is used to iterate over the relative positions.
 */
#define _NPOS_REL 0x0c
#define POS_REL_SXY 0x01
#define POS_REL_SX 0x02
#define POS_REL_SY 0x03
#define POS_REL_CX1 0x04
#define POS_REL_CX2 0x05
#define POS_REL_CY1 0x06
#define POS_REL_CY2 0x07
#define POS_REL_CTRANS1 0x08
#define POS_REL_CTRANS2 0x09
#define POS_REL_CCIS1 0x0a
#define POS_REL_CCIS2 0x0b
#define POS_REL_COPP 0x0c

/** ---------------------------------------------------------------------------
 * @section Adjacency options
 *
 *          Following constants define the options for the adjacency finder.
 */

/**
 * @brief This option is used to get all the adjacents.
 */
#define ADJ_DEFAULT 0x00

/**
 * @brief This option is used to get the side adjacents only.
 */
#define ADJ_SIDE 0x01

/**
 * @brief This option is used to get the corner adjacents only.
 */
#define ADJ_CORNER 0x02

/**
 * @brief This option is used to get the adjacents without a triomino.
 */
#define ADJ_EMPTY 0x04

/**
 * @brief This option is used to get the adjacents with a triomino.
 */
#define ADJ_FULL 0x08

#endif  // _TCONSTANTS_H
