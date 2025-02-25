/**
 * @file       set-iterator.h
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#ifndef _SET_ITERATOR_H
#define _SET_ITERATOR_H

#include <stdbool.h>

#include "set.h"

/**
 * @brief Set iterator type.
 *
 * @details A set iterator is used to iterate over the elements of a set.
 */
typedef struct _SetIterator SetIterator;

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

#endif // _SET_ITERATOR_H
