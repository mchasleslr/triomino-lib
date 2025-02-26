/**
 * @file       triomino-pos.h
 *
 * @author     Maxime Chasles
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#ifndef _TRIOMINO_POS_H
#define _TRIOMINO_POS_H

#include <stdbool.h>

#include "types.h"

typedef struct _TriominoPos TriominoPos;

extern TriominoPos *triomino_pos_set_full(TriominoPos *pos, coord_t x, coord_t y, slot_t slot, rot_t rotation);
extern TriominoPos *triomino_pos_create_full(coord_t x, coord_t y, slot_t slot, rot_t rotation);
extern coord_t triomino_pos_get_x(TriominoPos *pos);
extern coord_t triomino_pos_get_y(TriominoPos *pos);
extern slot_t triomino_pos_get_slot(TriominoPos *pos);
extern rot_t triomino_pos_get_rotation(TriominoPos *pos);
extern void triomino_pos_destroy(TriominoPos *pos);

#endif // _TRIOMINO_POS_H
