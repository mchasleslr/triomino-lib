/**
 * @file       test-plcmt-struct.c
 *
 * @author     Maxime Chasles <mchasles@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "triomino.h"
#include "triomino_plcmt.h"
#include "triomino.inc"
#include "triomino_plcmt.inc"

int main(void)
{
  triomino_init();
  {
    Triomino *triomino1 = triomino_create_full(2, 2, 2);
    Triomino *triomino2 = triomino_create_full(2, 2, 2);

    TriominoPlcmt *default_plcmt = triomino_plcmt_create_default();

    assert("" && default_plcmt->player == default_player);
    assert("" && default_plcmt->pos[0] == default_pos[0]);
    assert("" && default_plcmt->pos[1] == default_pos[1]);
    assert("" && default_plcmt->rotation == default_rotation);
    assert("" && !default_plcmt->triomino);

    TriominoPlcmt *full_plcmt = triomino_plcmt_create_full(triomino1, 2, 1, 2, N | W);

    assert("" && full_plcmt->player == 2);
    assert("" && full_plcmt->pos[0] == 1);
    assert("" && full_plcmt->pos[1] == 2);
    assert("" && full_plcmt->rotation == (N | W));
    assert("" && full_plcmt->triomino == triomino1);

    TriominoPlcmt *random_plcmt = triomino_plcmt_create_random(triomino2, 2);

    printf("player: %d\n", random_plcmt->player);
    printf("x: %d\n", random_plcmt->pos[0]);
    printf("y: %d\n", random_plcmt->pos[1]);
    printf("rotation: %d\n", random_plcmt->rotation);

    assert("" && random_plcmt->triomino == triomino2);
    assert("" && random_plcmt->player == 2);
    assert("" && random_plcmt->pos[0] && random_plcmt->pos[0] <= MAX_X);
    assert("" && random_plcmt->pos[1] && random_plcmt->pos[1] <= MAX_Y);
    assert("" && ((random_plcmt->rotation == N) ||
                  (random_plcmt->rotation == E) ||
                  (random_plcmt->rotation == S) ||
                  (random_plcmt->rotation == W) ||
                  (random_plcmt->rotation == (N | E)) ||
                  (random_plcmt->rotation == (N | W)) ||
                  (random_plcmt->rotation == (S | E)) ||
                  (random_plcmt->rotation == (S | W))));

    triomino_plcmt_destroy(default_plcmt);
    triomino_plcmt_destroy(full_plcmt);
    triomino_plcmt_destroy(random_plcmt);
  }

  triomino_finish();

  return EXIT_SUCCESS;
}
