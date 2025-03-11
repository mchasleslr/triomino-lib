/**
 * @file       tutils.h
 *
 *             This module provides general purpose utility functions.
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#ifndef _TUTILS_H
#define _TUTILS_H

/**
 * @brief Gets the length of an array.
 *
 * @param t The array.
 * @return The length of the array.
 */
#define ARRAY_LEN(t) (sizeof(t) / sizeof(t[0]))

#endif  // _TUTILS_H
