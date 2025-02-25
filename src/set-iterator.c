/**
 * @file       set-iterator.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "set-iterator.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "set.inc"
#include "set-iterator.inc"

#define _SIZEOF_SET_ITERATOR sizeof(SetIterator)

SetIterator *set_iterator_create(Set *set)
{
  SetIterator *iterator;

  if (NULL != (iterator = malloc(_SIZEOF_SET_ITERATOR)))
  {
    iterator->set = set;
    iterator->current = set->head;
    iterator->index = 0;
  }

  return iterator;
}

void set_iterator_destroy(SetIterator *iterator)
{
  if (iterator)
  {
    set_destroy(iterator->set);
    free(iterator);
  }
}

bool set_iterator_has_next(SetIterator *iterator)
{
  return NULL != iterator->current;
}

SetIterator *set_iterator_next(SetIterator *iterator)
{
  if (set_iterator_has_next(iterator))
  {
    iterator->current = iterator->current->next;
    iterator->index++;
  }
  return iterator;
}

SetIterator *set_iterator_reset(SetIterator *iterator)
{
  iterator->current = iterator->set->head;
  iterator->index = 0;
  return iterator;
}

void *set_iterator_get(SetIterator *iterator)
{
  return iterator->current->data;
}

unsigned int set_iterator_index(SetIterator *iterator)
{
  return iterator->index;
}
