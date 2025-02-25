#include "set.h"

struct _SetIterator {
  Set *set;
  SetNode *current;
  unsigned int index;
};
