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
 * @brief Set iterator type.
 *
 * @details A set iterator is used to iterate over the elements of a set.
 */
typedef struct _SetIterator SetIterator;

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
 * @brief Merge two sets.
 *
 * @details Add all elements of the source set to the destination set.
 *
 * @note The source set is destroyed.
 *
 * @param dest The set to merge into.
 * @param src The set to merge from.
 * @return The set after the merge.
 */
extern Set *set_merge(Set *dest, Set *src);

/**
 * @brief Remove an element from a set.
 *
 * @param set The set to remove the element from.
 * @param element The element to remove.
 * @return The set after the removal. (If the element is not present, the set is
 * unchanged.)
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

/**
 * @brief Filter a set with a given function.
 *
 * @param set The set to filter.
 * @param filter The filter function.
 */
extern Set *set_filter(Set *set, bool (*filter)(void *));

/**
 * @brief Create a set iterator.
 *
 * @param set The set to iterate over.
 * @return The set iterator created or NULL if an error occurred.
 */
extern SetIterator *set_iterator_create(Set *set);

/**
 * @brief Destroy a set iterator and the associated resources.
 *
 * @param iterator The set iterator to destroy.
 */
extern void set_iterator_destroy(SetIterator *iterator);

/**
 * @brief Check if a set iterator has a next element.
 *
 * @param iterator The set iterator.
 * @return true if the set iterator has a next element, false otherwise.
 */
extern bool set_iterator_has_next(SetIterator *iterator);

/**
 * @brief Iterate over the next element of a set iterator.
 *
 * @param iterator The set iterator.
 * @return The iterator after the iteration.
 */
extern SetIterator *set_iterator_next(SetIterator *iterator);

/**
 * @brief Reset a set iterator to the first element.
 *
 * @param iterator The set iterator.
 * @return The iterator reset.
 */
extern SetIterator *set_iterator_reset(SetIterator *iterator);

/**
 * @brief Get the current element of a set iterator.
 *
 * @param iterator The set iterator.
 * @return The current element.
 */
extern void *set_iterator_get(SetIterator *iterator);

/**
 * @brief Get the index of the current element of a set iterator.
 *
 * @param iterator The set iterator.
 * @return The index of the current element.
 */
extern unsigned int set_iterator_index(SetIterator *iterator);

#endif
