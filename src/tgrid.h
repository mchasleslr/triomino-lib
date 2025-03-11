/**
 * @file       tgrid.h
 *
 *             This module provides the TGrid structure
 *             and its associated functions.
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#ifndef _TGRID_H
#define _TGRID_H

#include "set.h"
#include "tmem.h"
#include "tplacement.h"

/**
 * @brief The TGrid structure represents the game grid.
 *
 * The grid is a pseudo 2D array of TPlacement structures.
 * Each cell of the grid can contain two triomino placement,
 * one on the inferior edge and one on the superior edge.
 */
typedef struct _TGrid TGrid;

/**
 * TODO: remove this
 */
typedef Set TSet;

/**
 * @brief Creates a new TGrid structure.
 *
 * @param size The size of the grid.
 * @return A pointer to the new TGrid structure.
 */
TGrid *t_grid_create(unsigned int size);

/**
 * @brief Destroys a TGrid structure.
 *
 * @param grid The TGrid structure to destroy.
 */
void t_grid_destroy(TGrid *grid);

/**
 * @brief Gets the size of a TGrid structure.
 *
 * @param grid The TGrid structure.
 * @return The size of the grid.
 */
unsigned int t_grid_get_size(TGrid *grid);

/**
 * @brief Gets a placement from a TGrid structure.
 *
 * @param grid The TGrid structure.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param edge The edge.
 * @return A pointer to the TPlacement structure.
 */
TPlacement *t_grid_get_placement(TGrid *grid, unsigned int x, unsigned int y,
                                 unsigned int edge);

/**
 * @brief Fills a placement in a TGrid structure.
 *
 * @param grid The TGrid structure.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param edge The edge.
 * @param rotation The rotation.
 * @param tile The triomino to place.
 * @return A pointer to the TPlacement structure.
 */
TPlacement *t_grid_fill_placement(TGrid *grid, unsigned int x, unsigned int y,
                                  unsigned char edge, unsigned char rotation,
                                  Triomino *tile);

/**
 * @brief Commits a staged placement in a TGrid structure.
 *
 * @param grid The TGrid structure.
 * @param staged The staged placement.
 * @return A pointer to the TPlacement structure.
 */
TPlacement *t_grid_commit_placement(TGrid *grid, TPlacement *tp);

/**
 * @brief Gets the adjacents of a placement in a TGrid structure.
 *
 * @param grid The TGrid structure.
 * @param ref The reference placement.
 * @param options The options to filter the adjacents.
 * @return A set of TPlacement structures.
 */
TSet *t_grid_get_adjacents(TGrid *grid, TPlacement *ref, int options);

/**
 * @brief Checks if a placement is valid in a TGrid structure.
 *
 * @param grid The TGrid structure.
 * @param candidate The candidate placement.
 * @return true if the placement is valid, false otherwise.
 */
bool t_grid_valid_placement(TGrid *grid, TPlacement *candidate);

/**
 * @brief Displays a TGrid structure.
 *
 * @param grid The TGrid structure to display.
 */
void t_grid_display(TGrid *grid);

#endif  // _TGRID_H
