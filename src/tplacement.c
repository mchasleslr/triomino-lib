/**
 * @file       tplacement.c
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

// ----------------------------------------------------------------------------

#include "tplacement.h"

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "ttypes.h"
#include "tconstants.h"
#include "tgrid.h"
#include "tplacement.h"
#include "tcompatibility.h"

// ----------------------------------------------------------------------------

static unsigned int t_placement_count = 0;

// const char *rot_abs_map[] = {
//     "UNDEFINED",
//     "ROT_ABS_A",
//     "ROT_ABS_B",
//     "ROT_ABS_C"};

// const char *pos_rel_map[] = {
//     "UNDEFINED",
//     "POS_REL_SXY",
//     "POS_REL_SX",
//     "POS_REL_SY",
//     "POS_REL_CX1",
//     "POS_REL_CX2",
//     "POS_REL_CY1",
//     "POS_REL_CY2",
//     "POS_REL_CTRANS1",
//     "POS_REL_CTRANS2",
//     "POS_REL_CCIS1",
//     "POS_REL_CCIS2",
//     "POS_REL_COPP"};

// TODO: add player_id, rotation et triomino to params
TPlacement *t_placement_create(unsigned int x, unsigned int y, unsigned int edge)
{
  TPlacement *tp = t_malloc(sizeof(TPlacement));

  tp->id = t_placement_count++;

  tp->player_id = _UNDEFINED;
  tp->rotation = _UNDEFINED;
  tp->triomino = NULL;

  tp->coords[0] = x;
  tp->coords[1] = y;
  tp->coords[2] = edge;

  return tp;
}

TPlacement *t_placement_create_full(
    unsigned char player_id,
    unsigned int x,
    unsigned int y,
    unsigned int edge,
    unsigned char rotation,
    Triomino *triomino)
{
  TPlacement *tp = t_placement_create(x, y, edge);
  tp->player_id = player_id;
  tp->rotation = rotation;
  tp->triomino = triomino;
  return tp;
}

TPlacement *t_placement_stage(TPlacement *dest, TPlacement *src)
{
  if (dest)
  {
    free(dest);
  }

  dest = t_placement_create_full(src->player_id, t_placement_get_x(src), t_placement_get_y(src), t_placement_get_edge(src), src->rotation, src->triomino);

  return dest;
}

void t_placement_destroy(TPlacement *tp)
{
  if (tp->triomino)
  {
    triomino_destroy(tp->triomino);
  }
  free(tp);
}

char *t_placement_to_string(TPlacement *tp)
{
  static char str[128];
  int bytes;

  bytes = snprintf(str, sizeof str, "[");

  if (tp->coords[2] == EDGE_INF)
  {
    bytes += snprintf(str + bytes, sizeof str - bytes, "-");
  }
  else
  {
    bytes += snprintf(str + bytes, sizeof str - bytes, "+");
  }

  bytes += snprintf(str + bytes, sizeof str - bytes, "(%d, %d),", t_placement_get_x(tp), t_placement_get_y(tp));

  if (!t_placement_empty(tp))
  {
    bytes += snprintf(str + bytes, sizeof str - bytes, "%s]", triomino_to_string(t_placement_get_triomino(tp)));
  }
  else
  {
    bytes += snprintf(str + bytes, sizeof str - bytes, "(empty)]");
  }

  return str;
}

TPlacement *t_placement_set_player_id(TPlacement *tp, unsigned int id)
{
  if (tp)
  {
    tp->player_id = id;
  }
  return tp;
}

TPlacement *t_placement_set_rotation(TPlacement *tp, unsigned char rotation)
{
  assert("t_placement_set_rotation: NULL pointer" && tp);
  if (tp)
  {
    tp->rotation = rotation;
  }

  return tp;
}

TPlacement *t_placement_set_triomino(TPlacement *tp, Triomino *triomino)
{
  assert("t_placement_set_triomino: NULL pointer" && tp);
  assert("t_placement_set_triomino: cannot set NULL" && triomino);

  if (tp)
  {
    tp->triomino = triomino;
  }
  return tp;
}

void t_placement_clear_out(TPlacement *tp)
{
  tp->rotation = _UNDEFINED;
  tp->triomino = NULL;
}

unsigned int t_placement_get_x(TPlacement *tp)
{
  assert("t_placement_get_x: NULL pointer" && tp);

  return tp->coords[0];
}

unsigned int t_placement_get_y(TPlacement *tp)
{
  assert("t_placement_get_y: NULL pointer" && tp);

  return tp->coords[1];
}

unsigned int t_placement_get_edge(TPlacement *tp)
{
  assert("t_placement_get_edge: NULL pointer" && tp);

  return tp->coords[2];
}

unsigned char t_placement_get_rotation(TPlacement *tp)
{
  assert("t_placement_get_rotation: NULL pointer" && tp);

  return tp->rotation;
}

unsigned char t_placement_get_player_id(TPlacement *tp)
{
  assert("t_placement_get_player_id: NULL pointer" && tp);

  return tp->player_id;
}

Triomino *t_placement_get_triomino(TPlacement *tp)
{
  assert("t_placement_get_triomino: NULL pointer" && tp);

  return tp->triomino;
}

bool t_placement_empty(TPlacement *tp)
{
  assert("t_placement_empty: NULL pointer" && tp);

  return tp->triomino == NULL;
}

static int _get_rot_rel(TPlacement *ref, TPlacement *target)
{
  return t_placement_get_rotation(ref) << 4 | t_placement_get_rotation(target) << 6;
}

static int _get_pos_rel(TPlacement *ref, TPlacement *target)
{
  unsigned int pos_rel;
  unsigned int x_ref, y_ref, x_target, y_target;
  unsigned char edge_ref, edge_target;

  x_ref = t_placement_get_x(ref);
  y_ref = t_placement_get_y(ref);
  edge_ref = t_placement_get_edge(ref);
  x_target = t_placement_get_x(target);
  y_target = t_placement_get_y(target);
  edge_target = t_placement_get_edge(target);

  if (x_ref == x_target && y_ref == y_target && edge_ref == !edge_target)
  {
    pos_rel = POS_REL_SXY;
  }
  else if ((x_ref == x_target + 1 || x_ref == x_target - 1) && y_ref == y_target && edge_ref == !edge_target)
  {
    pos_rel = POS_REL_SX;
  }
  else if ((y_ref == y_target + 1 || y_ref == y_target - 1) && x_ref == x_target && edge_ref == !edge_target)
  {
    pos_rel = POS_REL_SY;
  }
  else if (y_ref == y_target + 1 && x_ref == x_target && edge_ref == edge_target)
  {
    if (edge_ref == EDGE_INF)
    {
      pos_rel = POS_REL_CY1;
    }
    else
    {
      pos_rel = POS_REL_CY2;
    }
  }
  else if (y_ref == y_target - 1 && x_ref == x_target && edge_ref == edge_target)
  {
    if (edge_ref == EDGE_INF)
    {
      pos_rel = POS_REL_CY2;
    }
    else
    {
      pos_rel = POS_REL_CY1;
    }
  }
  else if (x_ref == x_target + 1 && y_ref == y_target && edge_ref == edge_target)
  {
    if (edge_ref == EDGE_INF)
    {
      pos_rel = POS_REL_CX1;
    }
    else
    {
      pos_rel = POS_REL_CX2;
    }
  }
  else if (x_ref == x_target - 1 && y_ref == y_target && edge_ref == edge_target)
  {
    if (edge_ref == EDGE_INF)
    {
      pos_rel = POS_REL_CX2;
    }
    else
    {
      pos_rel = POS_REL_CX1;
    }
  }

  else if (x_ref == x_target + 1 && y_ref == y_target + 1 && edge_ref == !edge_target)
  {
    if (edge_ref == EDGE_INF)
    {
      pos_rel = POS_REL_CTRANS1;
    }
    else
    {
      pos_rel = POS_REL_CTRANS2;
    }
  }
  else if (x_ref == x_target - 1 && y_ref == y_target - 1 && edge_ref == !edge_target)
  {
    if (edge_ref == EDGE_INF)
    {
      pos_rel = POS_REL_CTRANS2;
    }
    else
    {
      pos_rel = POS_REL_CTRANS1;
    }
  }

  else if (x_ref == x_target + 1 && y_ref == y_target + 1 && edge_ref == edge_target)
  {
    if (edge_ref == EDGE_INF)
    {
      pos_rel = POS_REL_CCIS1;
    }
    else
    {
      pos_rel = POS_REL_CCIS2;
    }
  }
  else if (x_ref == x_target - 1 && y_ref == y_target - 1 && edge_ref == edge_target)
  {
    if (edge_ref == EDGE_INF)
    {
      pos_rel = POS_REL_CCIS2;
    }
    else
    {
      pos_rel = POS_REL_CCIS1;
    }
  }
  else if (x_ref == x_target - 1 && y_ref == y_target + 1 && edge_ref == !edge_target)
  {
    pos_rel = POS_REL_COPP;
  }
  else if (x_ref == x_target + 1 && y_ref == y_target - 1 && edge_ref == !edge_target)
  {
    pos_rel = POS_REL_COPP;
  }
  else
  {
    pos_rel = _UNDEFINED;
  }

  return pos_rel;
}

bool t_placement_compatibles(TPlacement *ref, TPlacement *target)
{
  assert("t_placement_tiles_compatibles: NULL pointer" && ref && target);
  assert(ref->triomino && ref->rotation);
  assert(target->triomino && target->rotation);

  bool compatibles = false;

  TCompatibility *comp = t_compatibility_create(ref->triomino);
  t_compatibility_set_strategy(comp, _get_pos_rel(ref, target) | _get_rot_rel(ref, target));

  compatibles = t_compatibility_exec_strategy(comp, target->triomino);

  t_compatibility_destroy(comp);

  return compatibles;
}
