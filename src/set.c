/**
 * @file       set.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "set.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "set.inc"

#define _SIZEOF_SET sizeof(Set)
#define _SIZEOF_SETNODE sizeof(SetNode)
#define _SIZEOF_SET_ITERATOR sizeof(SetIterator)

Set* set_create() {
  Set* set;

  if (NULL != (set = malloc(_SIZEOF_SET))) {
    set->head = NULL;
  }
  return set;
}

SetNode* set_create_node(void* element) {
  SetNode* node;

  if (NULL != (node = malloc(_SIZEOF_SETNODE))) {
    node->data = element;
    node->next = NULL;
  }
  return node;
}

Set* set_clear(Set* set) {
  SetNode* current = set->head;

  while (current) {
    SetNode* prev = current;
    current = current->next;
    free(prev);
  }

  return set;
}

void set_destroy(Set* set) {
  set = set_clear(set);
  free(set);
}

bool set_contains(Set* set, void* element) {
  bool found = false;
  SetNode* current = set->head;

  while (current && !found) {
    if (current->data == element) {
      found = !found;
    }

    current = current->next;
  }

  return found;
}

Set* set_add(Set* set, void* element) {
  if (set_contains(set, element) || element == NULL) {
    return set;
  }

  SetNode* new;

  if (NULL != (new = set_create_node(element))) {
    new->next = set->head;
    set->head = new;
  }

  return set;
}

Set* set_merge(Set* dest, Set* src) {
  SetIterator* it;
  for (it = set_iterator_create(src); set_iterator_has_next(it);
       it = set_iterator_next(it)) {
    set_add(dest, set_iterator_get(it));
  }
  set_destroy(src);
  set_iterator_destroy(it);

  return dest;
}

Set* set_remove(Set* set, void* element) {
  if (set_empty(set)) {
    return set;
  }

  if (set->head && set->head->data == element) {
    SetNode* tmp_p = set->head;
    set->head = set->head->next;
    free(tmp_p);
  } else {
    bool found = false;
    SetNode* prev = set->head;
    SetNode* current = set->head->next;

    while (current && !found) {
      if (current->data == element) {
        found = true;
        current = current->next;
        free(prev->next);
        prev->next = current;
      }

      if (!found) {
        prev = current;
        current = current->next;
      }
    }
  }

  return set;
}

bool set_empty(Set* set) { return set->head == NULL; }

unsigned int set_size(Set* set) {
  unsigned int size = 0;

  SetNode* current = set->head;

  while (current) {
    size++;
    current = current->next;
  }

  return size;
}

Set* set_filter(Set* set, bool (*filter)(void*)) {
  SetIterator* iterator;
  Set* to_remove = set_create();

  for (iterator = set_iterator_create(set); set_iterator_has_next(iterator);
       iterator = set_iterator_next(iterator)) {
    void* element = set_iterator_get(iterator);

    if (!filter(element)) {
      set_add(to_remove, element);
    }
  }
  free(iterator);

  for (iterator = set_iterator_create(to_remove);
       set_iterator_has_next(iterator);
       iterator = set_iterator_next(iterator)) {
    void* element = set_iterator_get(iterator);
    set = set_remove(set, element);
  }
  free(iterator);
  set_destroy(to_remove);

  return set;
}

SetIterator* set_iterator_create(Set* set) {
  if (!set) {
    return NULL;
  }

  SetIterator* iterator;

  if (NULL != (iterator = malloc(_SIZEOF_SET_ITERATOR))) {
    iterator->set = set;
    iterator->current = set->head;
    iterator->index = 0;
  }

  return iterator;
}

void set_iterator_destroy(SetIterator* iterator) { free(iterator); }

bool set_iterator_has_next(SetIterator* iterator) {
  if (!iterator) {
    return false;
  }
  return NULL != iterator->current;
}

SetIterator* set_iterator_next(SetIterator* iterator) {
  if (set_iterator_has_next(iterator)) {
    iterator->current = iterator->current->next;
    iterator->index++;
  }
  return iterator;
}

SetIterator* set_iterator_reset(SetIterator* iterator) {
  iterator->current = iterator->set->head;
  iterator->index = 0;
  return iterator;
}

void* set_iterator_get(SetIterator* iterator) {
  return iterator->current->data;
}

unsigned int set_iterator_index(SetIterator* iterator) {
  return iterator->index;
}
