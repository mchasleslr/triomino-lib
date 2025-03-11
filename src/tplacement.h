/**
 * @file       tplacement.h
 *
 *             This module provides the TPlacement structure and
 *             its associated functions.
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#ifndef _TPLACEMENT_H
#define _TPLACEMENT_H

#include "triomino.h"

/**
 * @brief The TPlacement structure represents a triomino placement on the grid.
 *
 * A placement is defined by its coordinates (x, y) and its edge (EDGE_INF or
 * EDGE_SUP). If a triomino is placed, the player id, the rotation and the
 * triomino are also stored.
 */
typedef struct _TPlacement TPlacement;

/**
 * @brief Creates a new TPlacement structure.
 *
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param edge The edge.
 * @return A pointer to the new TPlacement structure.
 */
TPlacement *t_placement_create(unsigned int x, unsigned int y,
                               unsigned int edge);

/**
 * @brief Creates a new TPlacement structure with all its fields.
 *
 * @param player_id The player id.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param edge The edge.
 * @param rotation The rotation.
 * @param triomino The triomino.
 * @return A pointer to the new TPlacement structure.
 */
TPlacement *t_placement_create_full(unsigned char player_id, unsigned int x,
                                    unsigned int y, unsigned int edge,
                                    unsigned char rotation, Triomino *triomino);

/**
 * @brief Copies a TPlacement structure.
 *
 * @param dest The destination TPlacement structure.
 * @param src The source TPlacement structure.
 * @return The destination TPlacement structure updated.
 */
TPlacement *t_placement_cpy(TPlacement *dest, TPlacement *src);

/**
 * @brief Destroys a TPlacement structure.
 *
 * @param tp The TPlacement structure to destroy.
 * @return void
 */
void t_placement_destroy(TPlacement *tp);

/**
 * @brief Converts a TPlacement structure to a string.
 *
 * @param tp The TPlacement structure.
 * @return A pointer to the string.
 */
char *t_placement_to_string(TPlacement *tp);

/**
 * @brief Sets the player id of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @param id The player id.
 * @return The TPlacement structure updated.
 */
TPlacement *t_placement_set_player_id(TPlacement *tp, unsigned int id);

/**
 * @brief Sets the rotation of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @param rotation The rotation.
 * @return The TPlacement structure updated.
 */
TPlacement *t_placement_set_rotation(TPlacement *tp, unsigned char rotation);

/**
 * @brief Sets the triomino of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @param triomino The triomino.
 * @return The TPlacement structure updated.
 */
TPlacement *t_placement_set_triomino(TPlacement *tp, Triomino *triomino);

/**
 * @brief Clears the player id, the rotation and the triomino of a TPlacement
 * structure.
 *
 * @note The triomino is not destroyed.
 *
 * @param tp The TPlacement structure.
 * @return void
 */
void t_placement_clear_out(TPlacement *tp);

/**
 * @brief Gets the x coordinate of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @return The x coordinate.
 */
unsigned int t_placement_get_x(TPlacement *tp);

/**
 * @brief Gets the y coordinate of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @return The y coordinate.
 */
unsigned int t_placement_get_y(TPlacement *tp);

/**
 * @brief Gets the edge of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @return The edge.
 */
unsigned int t_placement_get_edge(TPlacement *tp);

/**
 * @brief Gets the rotation of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @return The rotation.
 */
unsigned char t_placement_get_rotation(TPlacement *tp);

/**
 * @brief Gets the player id of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @return The player id.
 */
unsigned char t_placement_get_player_id(TPlacement *tp);

/**
 * @brief Gets the triomino of a TPlacement structure.
 *
 * @param tp The TPlacement structure.
 * @return A pointer to the triomino.
 */
Triomino *t_placement_get_triomino(TPlacement *tp);

/**
 * @brief Checks if a triomino is placed on a TPlacement structure.
 *
 * // TODO:
 * @note The player id, the rotation and the triomino are checked.
 *
 * @param tp The TPlacement structure.
 * @return true if the TPlacement structure is empty, false otherwise.
 */
bool t_placement_empty(TPlacement *tp);

/**
 * @brief Checks if two TPlacement structures are compatible.
 *
 * @pre The two TPlacement structures are not empty.
 *
 * They're compatibles if the triominos has their commons corners equals.
 *
 * @param ref The reference TPlacement structure.
 * @param target The target TPlacement structure.
 * @return true if the placements are compatible, false otherwise.
 */
bool t_placement_compatibles(TPlacement *ref, TPlacement *target);

#endif  // _TPLACEMENT_H
