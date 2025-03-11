/**
 * @file       tcompatibility.h
 *
 *             This module provides the TCompatibility structure
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#ifndef _TCOMPATIBILITY_H
#define _TCOMPATIBILITY_H

#include <stdbool.h>

#include "triomino.h"

/**
 * @brief The TCompatibility is a strategy pattern to compare two triominos.
 *
 *        The compatibility is defined by a reference triomino
 *        and a strategy to compare it with another triomino.
 *
 *        The strategy is defined by a context that is a combination
 *        of the relative position and the relative rotation between
 *        the two triominos.
 */
typedef struct _TCompatibility TCompatibility;

/**
 * @brief Creates a new TCompatibility structure.
 *
 * @param ref The reference triomino.
 * @return A pointer to the new TCompatibility structure.
 */
TCompatibility *t_compatibility_create(Triomino *ref);

/**
 * @brief Destroys a TCompatibility structure.
 *
 * @param comp The TCompatibility structure to destroy.
 */
void t_compatibility_destroy(TCompatibility *comp);

/**
 * @brief Sets the strategy of a TCompatibility structure.
 *
 * TODO: change the return type to bool or other...
 *
 * @param comp The TCompatibility structure.
 * @param context The context of the strategy.
 * @return true if the strategy is set, false otherwise.
 */
int t_compatibility_set_strategy(TCompatibility *comp, int context);

/**
 * @brief Executes the strategy of a TCompatibility structure.
 *
 * @param comp The TCompatibility structure.
 * @param target The target triomino.
 * @return true if the triominos are compatible, false otherwise.
 */
bool t_compatibility_exec_strategy(TCompatibility *comp,
                                   const Triomino *target);

#endif  // _TCOMPATIBILITY_H
