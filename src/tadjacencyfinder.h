/**
 * @file       tadjacencyfinder.h
 *
 *             This module provides the TAdjacencyFinder structure
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#ifndef _TADJACENCYFINDER_H
#define _TADJACENCYFINDER_H

#include "tgrid.h"

/**
 * @brief The TAdjacencyFinder structure is used to find the adjacents of a placement.
 *
 *        It is define by a grid and a reference placement.
 *        The adjacents are found by a strategy depending of the context.
 */
typedef struct _TAdjacencyFinder TAdjacencyFinder;

/**
 * @brief The adjacency strategy type.
 *
 *        This type is used to define the adjacency strategy.
 *        TODO: is this really useful?
 */
typedef bool (*adjacency_strategy)(TGrid *, unsigned int, unsigned int, unsigned char);

/**
 * @brief Creates a new TAdjacencyFinder structure.
 *
 * @param grid The grid.
 * @param ref The reference placement.
 * @return A pointer to the new TAdjacencyFinder structure.
 */
TAdjacencyFinder *t_adjacency_finder_create(TGrid *grid, TPlacement *ref);

/**
 * @brief Destroys a TAdjacencyFinder structure.
 *
 * @param finder The TAdjacencyFinder structure to destroy.
 */
void t_adjacency_destroy(TAdjacencyFinder *finder);

/**
 * @brief Sets the adjacency strategy of a TAdjacencyFinder structure.
 *
 * @param finder The TAdjacencyFinder structure.
 * @param context The context of the strategy.
 * @return The TAdjacencyFinder structure updated.
 */
TAdjacencyFinder *t_adjacency_finder_set_strategy(TAdjacencyFinder *finder, int context);

/**
 * @brief Executes the adjacency strategy of a TAdjacencyFinder structure.
 *
 * @param finder The TAdjacencyFinder structure.
 * @return The placement found.
 */
TPlacement *t_adjacency_finder_exec_strategy(TAdjacencyFinder *finder);

#endif // _TADJACENCYFINDER_H
