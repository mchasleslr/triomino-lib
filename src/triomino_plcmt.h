/**
 * @file       triomino_plcmt.h
 *
 * @author     Maxime Chasles <mchasles@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#ifndef _PLACEMENT_H
#define _PLACEMENT_H

#include "triomino.h"

#define N 1
#define E (N << 1) // 2
#define S (E << 1) // 4
#define W (S << 1) // 8

#define MAX_X 56
#define MAX_Y 56

const unsigned int default_player = 0;
const unsigned int default_pos[] = {0, 0};
const unsigned int default_rotation = N;

typedef struct _TriominoPlcmt TriominoPlcmt;

extern TriominoPlcmt *triomino_plcmt_fill_full(TriominoPlcmt *plcmt, Triomino *triomino, unsigned int player, unsigned int x, unsigned int y, unsigned int rotation);
extern TriominoPlcmt *triomino_plcmt_create_default();
extern void triomino_plcmt_destroy(TriominoPlcmt *plcmt);
extern TriominoPlcmt *triomino_plcmt_create_full(Triomino *triomino, unsigned int player, unsigned int x, unsigned int y, unsigned int rotation);
extern TriominoPlcmt *triomino_plcmt_create_random(Triomino *triomino, unsigned int player);

#endif // _PLACEMENT_H
