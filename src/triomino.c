/**
 * @file       triomino.c
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

#include "triomino.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "triomino.inc"

void* (*triomino_malloc)(size_t size) = malloc;
void* (*triomino_calloc)(size_t nmemb, size_t size) = calloc;
void* (*triomino_realloc)(void* ptr, size_t size) = realloc;
void (*triomino_free)(void* ptr) = free;

static int counter = 0;

bool triomino_init(void)
{
  if (!counter++)
  {
    assert(printf("triomino: initialized\n"));
  }
  return true;
}

bool triomino_finish(void)
{
  if (counter)
  {
    if (!--counter)
    {
      assert(printf("triomino: finished\n"));
    }
    return true;
  }
  else
  {
    return false;
  }
}

Triomino* triomino_fill_full(Triomino* triomino, unsigned char a, unsigned char b, unsigned char c)
{
  assert(a <= 5);
  assert(b <= 5);
  assert(c <= 5);
  assert(a <= b);
  assert(b <= c);
  triomino->a = a;
  triomino->b = b;
  triomino->c = c;
  return triomino;
}

Triomino* triomino_reset(Triomino* triomino)
{
  triomino->a = 0;
  triomino->b = 0;
  triomino->c = 0;
  return triomino;
}

Triomino* triomino_create_full(unsigned char a, unsigned char b, unsigned char c)
{
  assert(a <= 5);
  assert(b <= 5);
  assert(c <= 5);
  assert(a <= b);
  assert(b <= c);
  Triomino* triomino = triomino_malloc(sizeof(Triomino));
  if (triomino)
  {
    return triomino_fill_full(triomino, a, b, c);
  }
  return triomino;
}

Triomino* triomino_create_default(void)
{
  return triomino_calloc(1, sizeof(Triomino));
}

void triomino_destroy(Triomino* triomino)
{
  triomino_free(triomino);
}

unsigned char triomino_get_a(const Triomino* triomino)
{
  return triomino->a;
}

unsigned char triomino_get_b(const Triomino* triomino)
{
  return triomino->b;
}

unsigned char triomino_get_c(const Triomino* triomino)
{
  return triomino->c;
}

Triomino* triomino_clone(const Triomino* triomino)
{
  return triomino_create_full(triomino->a, triomino->b, triomino->c);
}

Triomino* triomino_copy(Triomino* dest, const Triomino* src)
{
  return triomino_fill_full(dest, src->a, src->b, src->c);
}

bool triomino_is_triple(const Triomino* triomino)
{
  return triomino->a == triomino->b && triomino->b == triomino->c;
}

bool triomino_is_double(const Triomino* triomino)
{
  return (triomino->a == triomino->b && triomino->b != triomino->c) ||
    (triomino->a != triomino->b && triomino->b == triomino->c);
}

bool triomino_is_single(const Triomino* triomino)
{
  return triomino->a != triomino->b && triomino->b != triomino->c;
}

unsigned char triomino_get_value(const Triomino* triomino, int flag)
{
  switch (flag)
  {
  case GAME_START:
    if (triomino_is_triple(triomino)) {
      if (triomino->a == 0) {
        return 40; // special case MAX POINT
      }
      else {
        return(triomino->a * 3) + 10; // adding bonus points
      }
    }
    break;
  case DEFAULT:
    return triomino->a + triomino->b + triomino->c;
    break;

  default:
    return 99; // this will is an error value
    break;
  }
}

bool triomino_aa_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->a == triomino2->a;
}

bool triomino_ab_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->a == triomino2->b;
}

bool triomino_ac_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->a == triomino2->c;
}

bool triomino_ba_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->b == triomino2->a;
}

bool triomino_bb_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->b == triomino2->b;
}

bool triomino_bc_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->b == triomino2->c;
}

bool triomino_ca_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->c == triomino2->a;
}

bool triomino_cb_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->c == triomino2->b;
}

bool triomino_cc_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->c == triomino2->c;
}

bool triomino_ab_cb_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->a == triomino2->c && triomino1->b == triomino2->b;
}

bool triomino_ab_ba_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->a == triomino2->b && triomino1->b == triomino2->a;
}

bool triomino_ab_ac_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->a == triomino2->a && triomino1->b == triomino2->c;
}

bool triomino_bc_cb_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->b == triomino2->c && triomino1->c == triomino2->b;
}

bool triomino_bc_ba_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->b == triomino2->b && triomino1->c == triomino2->a;
}

bool triomino_bc_ac_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->b == triomino2->a && triomino1->c == triomino2->c;
}

bool triomino_ca_cb_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->c == triomino2->c && triomino1->a == triomino2->b;
}

bool triomino_ca_ba_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->c == triomino2->b && triomino1->a == triomino2->a;
}

bool triomino_ca_ac_compatible(const Triomino* triomino1, const Triomino* triomino2)
{
  return triomino1->c == triomino2->a && triomino1->a == triomino2->c;
}

Triomino* triomino_fwrite(const Triomino* triomino, FILE* stream)
{
  if (fwrite(triomino, sizeof(Triomino), 1, stream) == 1)
  {
    return (Triomino*)triomino; // NOLINT (readability/casting)
  }
  return NULL;
}

Triomino* triomino_fread(Triomino* triomino, FILE* stream)
{
  if (fread(triomino, sizeof(Triomino), 1, stream) == 1)
  {
    return triomino;
  }
  return NULL;
}

const char* triomino_to_string(const Triomino* triomino)
{
  static char buffer[32];
  snprintf(buffer, sizeof buffer, "%u-%u-%u", triomino->a, triomino->b, triomino->c);
  return buffer;
}
