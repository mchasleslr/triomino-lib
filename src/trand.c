/**
 * @file       trand.c
 *
 * @author     Maxime Chasles
 * @date       2025
 * @copyright  BSD 3-Clause License
 */

#include "trand.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int t_rand_randint(int min, int max) {
  srand(getpid() * getppid());
  int r = rand() % (max - min + 1) + min;
  return r;
}
