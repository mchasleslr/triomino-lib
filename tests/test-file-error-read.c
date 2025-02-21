/**
 * @file       test-file-error-read.c
 *
 * @author     Christophe Demko <christophe.demko@univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "triomino.h"
#include "triomino.inc"

int main(void) {
  triomino_init();
  {
    FILE* stream = fopen("empty", "w");
    fclose(stream);
    Triomino* triomino = triomino_create_default();
    stream = fopen("empty", "r");
    assert(triomino_fread(triomino, stream) == NULL);
    fclose(stream);
    triomino_destroy(triomino);
  }
  triomino_finish();

  return EXIT_SUCCESS;
}
