/**
 * @file       triomino_plcmt.c
 *
 * @author     Maxime Chasles <mchasles@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include "triomino_plcmt.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "triomino.h"

#include "triomino_plcmt.inc"

TriominoPlcmt *triomino_plcmt_fill_full(TriominoPlcmt *plcmt, Triomino *triomino, unsigned int player, unsigned int x, unsigned int y, unsigned int rotation)
{
  plcmt->triomino = (Triomino *)triomino;
  plcmt->player = player;
  plcmt->pos[0] = x;
  plcmt->pos[1] = y;
  plcmt->rotation = rotation;

  return plcmt;
}

TriominoPlcmt *triomino_plcmt_create_default()
{
  TriominoPlcmt *plcmt;

  if (NULL == (plcmt = malloc(sizeof(TriominoPlcmt))))
  {
    perror("Malloc error");
    exit(EXIT_FAILURE);
  }

  return triomino_plcmt_fill_full(plcmt, NULL, default_player, default_pos[0], default_pos[1], default_rotation);
}

void triomino_plcmt_destroy(TriominoPlcmt *plcmt)
{
  if (plcmt->triomino)
  {
    triomino_destroy(plcmt->triomino);
  }
  free(plcmt);
}

TriominoPlcmt *triomino_plcmt_create_full(Triomino *triomino, unsigned int player, unsigned int x, unsigned int y, unsigned int rotation)
{
  TriominoPlcmt *plcmt = triomino_plcmt_create_default();

  return triomino_plcmt_fill_full(plcmt, triomino, player, x, y, rotation);
}

TriominoPlcmt *triomino_plcmt_create_random(Triomino *triomino, unsigned int player)
{
  TriominoPlcmt *plcmt = triomino_plcmt_create_default();

  srand(getpid());

  unsigned int rand_x = rand() % MAX_X;
  unsigned int rand_y = rand() % MAX_Y;
  unsigned int rand_index = rand() % 8;

  unsigned int rotations[] = {N,
                              E,
                              S,
                              W,
                              N | W,
                              N | E,
                              S | W,
                              S | E};

  unsigned int rand_rotation = rotations[rand_index];

  return triomino_plcmt_fill_full(plcmt, triomino, player, rand_x, rand_y, rand_rotation);
}
