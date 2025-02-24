#ifndef _SET_H
#define _SET_H

#include <stdbool.h>

#define _SIZEOF_SET sizeof(Set)
#define _SIZEOF_SETNODE sizeof(SetNode)

typedef struct _SetNode SetNode;
typedef struct _Set Set;

extern Set *set_create();

extern SetNode *set_create_node(void *element);

extern void set_destroy(Set *set);

extern Set *set_add(Set *set, void *element);

extern Set *set_remove(Set *set, void *element);

extern bool set_contains(Set *set, void *element);

extern unsigned int set_size(Set *set);

extern bool set_empty(Set *set);

extern Set *set_clear(Set *set);

#endif
