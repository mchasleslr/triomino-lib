/**
 * @file       test-set_create_node.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "set.h"
#include "set.inc"

int main(void) {
  int n = 1;

  SetNode *node = set_create_node(&n);

  assert("" && *(int *)node->data == n);
  assert("" && node->next == NULL);

  free(node);

  return EXIT_SUCCESS;
}
