/**
 * @file       set.h
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#ifndef _SET_H
#define _SET_H

#include <stdbool.h>

/**
 * @brief SetNode type.
 *
 * @details A set node is used to store an element in a set.
 */
typedef struct _SetNode SetNode;

/**
 * @brief Set type.
 *
 * @details A set is a collection of unique elements.
 */
typedef struct _Set Set;

/**
 * @brief Create an empty set.
 *
 * @return The set created or NULL if an error occurred.
 */
extern Set *set_create();

/**
 * @brief Create a set node.
 *
 * @param element The element to store in the node.
 * @return The set node created or NULL if an error occurred.
 */
extern SetNode *set_create_node(void *element);

/**
 * @brief Destroy a set and the associated resources.
 *
 * @param set The set to destroy.
 */
extern void set_destroy(Set *set);

/**
 * @brief Add an element to a set if it is not already present.
 *
 * @param set The set to add the element to.
 * @param element The element to add.
 * @return The set after the addition.
 */
extern Set *set_add(Set *set, void *element);

/**
 * @brief Remove an element from a set.
 *
 * @param set The set to remove the element from.
 * @param element The element to remove.
 * @return The set after the removal. (If the element is not present, the set is unchanged.)
 */
extern Set *set_remove(Set *set, void *element);

/**
 * @brief Check if a set contains an element.
 *
 * @param set The set to check.
 * @param element The element to check.
 * @return true if the set contains the element, false otherwise.
 */
extern bool set_contains(Set *set, void *element);

/**
 * @brief Get the size of a set.
 *
 * @param set The set to get the size of.
 * @return The size of the set.
 */
extern unsigned int set_size(Set *set);

/**
 * @brief Check if a set is empty.
 *
 * @param set The set to check.
 * @return true if the set is empty, false otherwise.
 */
extern bool set_empty(Set *set);

/**
 * @brief Clear a set : remove all elements and set the size to 0.
 *
 * @param set The set to clear.
 * @return The set after the clearing.
 */
extern Set *set_clear(Set *set);

#endif
