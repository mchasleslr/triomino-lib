#ifndef _SET_ITERATOR_H
#define _SET_ITERATOR_H

#include <stdbool.h>

#include "set.h"

typedef struct _SetIterator SetIterator;

extern SetIterator *set_iterator_create(Set *set);
extern void set_iterator_destroy(SetIterator *iterator);
extern bool set_iterator_has_next(SetIterator *iterator);
extern SetIterator *set_iterator_next(SetIterator *iterator);
extern SetIterator *set_iterator_reset(SetIterator *iterator);
extern void *set_iterator_get(SetIterator *iterator);

#endif // _SET_ITERATOR_H
