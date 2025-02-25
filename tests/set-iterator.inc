/**
 * @file       set-iterator.inc
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "set.h"

struct _SetIterator {
  Set *set;
  SetNode *current;
  unsigned int index;
};
