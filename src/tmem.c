/**
 * @file       tmem.c
 *
 *             This module provides memory management functions.
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#include "tmem.h"

#include <stdio.h>  // perror
#include <stdlib.h>

// ----------------------------------------------------------------------------

/**
 * @brief Allocates memory.
 *
 * @param size The size of the memory to allocate.
 * @return A pointer to the allocated memory.
 */
void* t_malloc(size_t size) {
  void* ptr;

  if (NULL == (ptr = malloc(size))) {
    perror("malloc ");
    exit(EXIT_FAILURE);
  }

  return ptr;
}
