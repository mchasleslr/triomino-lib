#include <stdlib.h>
#include <assert.h>

#include "triomino.h"
#include "set.h"

// ----------------------------------------------------------------------------
// tconstants.h

#define _UNDEFINED 0x00

#define GRID_XMIN 0x00
#define GRID_YMIN 0x00

#define EDGE_INF 0x00
#define EDGE_SUP 0x01

#define _NROT_ABS 0x03

#define ROT_ABS_A 0x01
#define ROT_ABS_B 0x02
#define ROT_ABS_C 0x03

#define ROT_REL_AA (ROT_ABS_A << 4 | ROT_ABS_A << 6)
#define ROT_REL_AB (ROT_ABS_A << 4 | ROT_ABS_B << 6)
#define ROT_REL_AC (ROT_ABS_A << 4 | ROT_ABS_C << 6)
#define ROT_REL_BA (ROT_ABS_B << 4 | ROT_ABS_A << 6)
#define ROT_REL_BB (ROT_ABS_B << 4 | ROT_ABS_B << 6)
#define ROT_REL_BC (ROT_ABS_B << 4 | ROT_ABS_C << 6)
#define ROT_REL_CA (ROT_ABS_C << 4 | ROT_ABS_A << 6)
#define ROT_REL_CB (ROT_ABS_C << 4 | ROT_ABS_B << 6)
#define ROT_REL_CC (ROT_ABS_C << 4 | ROT_ABS_C << 6)

#define _NPOS_REL 0x0c

#define POS_REL_SXY 0x01
#define POS_REL_SX 0x02
#define POS_REL_SY 0x03
#define POS_REL_CX1 0x04
#define POS_REL_CX2 0x05
#define POS_REL_CY1 0x06
#define POS_REL_CY2 0x07
#define POS_REL_CTRANS1 0x08
#define POS_REL_CTRANS2 0x09
#define POS_REL_CCIS1 0x0a
#define POS_REL_CCIS2 0x0b
#define POS_REL_COPP 0x0c

#define ADJ_DEFAULT 0x00
#define ADJ_SIDE 0x01
#define ADJ_CORNER 0x02
#define ADJ_EMPTY 0x04
#define ADJ_FULL 0x08

// ----------------------------------------------------------------------------
// ttypes.h

typedef Set TSet;

// ----------------------------------------------------------------------------
// tmem.h

void *t_malloc(size_t size);

// ----------------------------------------------------------------------------
// tutils.h

#define ARRAY_LEN(t) (sizeof(t) / sizeof(t[0]))

// ----------------------------------------------------------------------------
// tplacement.h

typedef struct _TPlacement TPlacement;
typedef bool (*adjacents_filter_func)(void *);

TPlacement *t_placement_create(unsigned int x, unsigned int y, unsigned int edge);
void t_placement_destroy(TPlacement *tp);

char *t_placement_to_string(TPlacement *tp);

TPlacement *t_placement_set_player_id(TPlacement *tp, unsigned int id);
TPlacement *t_placement_set_rotation(TPlacement *tp, unsigned int rotation);
TPlacement *t_placement_set_triomino(TPlacement *tp, Triomino *triomino);

unsigned int t_placement_get_x(TPlacement *tp);
unsigned int t_placement_get_y(TPlacement *tp);
unsigned int t_placement_get_edge(TPlacement *tp);
unsigned char t_placement_get_rotation(TPlacement *tp);
unsigned char t_placement_get_player_id(TPlacement *tp);
Triomino *t_placement_get_triomino(TPlacement *tp);

bool t_placement_empty(TPlacement *tp);

// Check if triomino placed in ref is compatible with the one in target
bool t_placement_tiles_compatibles(TPlacement *ref, TPlacement *target);

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

// ----------------------------------------------------------------------------
// tgrid.h

typedef struct _TGrid TGrid;

TGrid *t_grid_create(unsigned int size);
void t_grid_destroy(TGrid *grid);

unsigned int t_grid_get_size(TGrid *grid);
TPlacement *t_grid_get_placement(TGrid *grid, unsigned int x, unsigned int y, unsigned int edge);

TSet *t_grid_get_adjacents(TGrid *grid, TPlacement *ref, int options);

// ----------------------------------------------------------------------------
// tadjacency.h

typedef struct _TAdjacencyFinder TAdjacencyFinder;
typedef TPlacement *(*adjacency_strategy_func)(TGrid *, unsigned int, unsigned int, unsigned char);

TAdjacencyFinder *t_adjacency_finder_create(TGrid *grid, TPlacement *ref);
void t_adjacency_destroy(TAdjacencyFinder *finder);
TAdjacencyFinder *t_adjacency_finder_set_strategy(TAdjacencyFinder *finder, int context);
TPlacement *t_adjacency_finder_exec_strategy(TAdjacencyFinder *finder);

// ----------------------------------------------------------------------------
// tcompatibility.h

typedef struct _TCompatibility TCompatibility;
typedef bool (*compatibility_strategy_func)(const Triomino *, const Triomino *);

TCompatibility *t_compatibility_create(Triomino *ref);

void t_compatibility_destroy(TCompatibility *comp);

int t_compatibility_set_strategy(TCompatibility *comp, int context);

bool t_compatibility_exec_strategy(TCompatibility *comp, const Triomino *target);

// ----------------------------------------------------------------------------

int main(void)
{
  char *pos_rel_map[] = {
      "UNDEFINED",
      "POS_REL_SXY",
      "POS_REL_SX",
      "POS_REL_SY",
      "POS_REL_CX1",
      "POS_REL_CX2",
      "POS_REL_CY1",
      "POS_REL_CY2",
      "POS_REL_CTRANS1",
      "POS_REL_CTRANS2",
      "POS_REL_CCIS1",
      "POS_REL_CCIS2",
      "POS_REL_COPP"};

  TGrid *grid = t_grid_create(3);

  TPlacement *tp = t_grid_get_placement(grid, 1, 1, EDGE_SUP);

  TSet *all_adj = t_grid_get_adjacents(grid, tp, ADJ_DEFAULT);

  SetIterator *it;
  for (it = set_iterator_create(all_adj); set_iterator_has_next(it); it = set_iterator_next(it))
  {
    TPlacement *current = set_iterator_get(it);
    printf("%s\n", t_placement_to_string(current));
    int pos_rel = _get_pos_rel(tp, current);
    printf("position_relative=%s\n", pos_rel_map[pos_rel]);
    printf("\n\n");
  }

  set_iterator_destroy(it);
  t_grid_destroy(grid);

  return EXIT_SUCCESS;
}

// ----------------------------------------------------------------------------
// tmem.c

void *t_malloc(size_t size)
{
  void *ptr;

  if (NULL == (ptr = malloc(size)))
  {
    perror("malloc ");
    exit(EXIT_FAILURE);
  }

  return ptr;
}

// ----------------------------------------------------------------------------
// tplacement.c

static unsigned int t_placement_count = 0;

struct _TPlacement
{
  unsigned int id;
  unsigned int coords[3];
  unsigned char rotation;
  unsigned char player_id;
  Triomino *triomino;
};

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

TPlacement *t_placement_set_rotation(TPlacement *tp, unsigned int rotation)
{
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

// static int _get_rot_rel(TPlacement *ref, TPlacement *target)
// {
//   return t_placement_get_rotation(ref) << 4 | t_placement_get_rotation(target) << 6;
// }

bool t_placement_triomino_compatibles(TPlacement *ref, TPlacement *target)
{
  assert("t_placement_tiles_compatibles: NULL pointer" && ref && target);
  assert(ref->triomino && ref->rotation);
  assert(target->triomino && target->rotation);

  bool compatibles = false;

  TCompatibility *comp = t_compatibility_create(ref->triomino);
  // comp = t_compatibility_set_strategy(comp, _get_pos_rel(ref, target) | _get_rot_rel(ref, target));

  compatibles = t_compatibility_exec_strategy(comp, target->triomino);

  t_compatibility_destroy(comp);

  return 0;
}

// ----------------------------------------------------------------------------
// tgrid.c

struct _TGrid
{
  unsigned int size;
  TPlacement ***placements;
};

TGrid *t_grid_create(unsigned int size)
{
  TGrid *grid = t_malloc(sizeof(TGrid));

  grid->size = size;

  unsigned int x, y;

  grid->placements = t_malloc(size * sizeof(TPlacement **));

  for (y = GRID_YMIN; y < size; y++)
  {
    grid->placements[y] = t_malloc(2 * size * sizeof(TPlacement *));
    for (x = GRID_XMIN; x < size * 2; x++)
    {
      grid->placements[y][x] = t_placement_create(x / 2, y, x % 2);
    }
  }

  return grid;
}

void t_grid_destroy(TGrid *grid)
{
  unsigned int i, j;

  for (i = 0; i < grid->size; i++)
  {
    for (j = 0; j < grid->size * 2; j++)
    {
      t_placement_destroy(grid->placements[i][j]);
    }
    free(grid->placements[i]);
  }
  free(grid->placements);
  free(grid);
}

unsigned int t_grid_get_size(TGrid *grid)
{
  assert("t_grid_get_size: NULL pointer" && grid);

  return grid->size;
}

TPlacement *t_grid_get_placement(TGrid *grid, unsigned int x, unsigned int y, unsigned int edge)
{
  assert("t_grid_get_placement: NULL pointer" && grid);

  return grid->placements[y][2 * x + edge];
}

static bool _rm_full_adjacents(void *element)
{
  // Used as a callback, it removes the full slots
  TPlacement *tp = (TPlacement *)element;
  return t_placement_empty(tp);
}

static bool _rm_empty_adjacents(void *element)
{
  // Used as a callback, it removes the empty slots
  TPlacement *tp = (TPlacement *)element;
  return !t_placement_empty(tp);
}

TSet *t_grid_get_adjacents(TGrid *grid, TPlacement *ref, int options)
{
  assert("t_grid_get_adjacents: NULL pointer" && grid && ref);

  TSet *adjacents = set_create();
  TAdjacencyFinder *finder = t_adjacency_finder_create(grid, ref);

  unsigned int start, end;
  adjacents_filter_func filter;

  // In case constants get corrupted
  int pos_rel[] = {
      //          Side adjacents        //
      POS_REL_SXY,
      POS_REL_SX,
      POS_REL_SY,
      //         Corner adjacents       //
      POS_REL_CCIS1,
      POS_REL_CCIS2,
      POS_REL_COPP,
      POS_REL_CTRANS1,
      POS_REL_CTRANS2,
      POS_REL_CX1,
      POS_REL_CX2,
      POS_REL_CY1,
      POS_REL_CY2};

  // For collecting only side adjacents
  if (options & ADJ_SIDE)
  {
    start = 0;
    end = 3;
  }
  // For collecting only corner adjacents
  else if (options & ADJ_CORNER)
  {
    start = 3;
    end = _NPOS_REL;
  }
  // For collecting both
  else
  {
    start = 0;
    end = _NPOS_REL;
  }

  // Removes placements without triomino
  if (options & ADJ_FULL)
  {
    filter = _rm_empty_adjacents;
  }
  // Removes placements with triomino
  else if (options & ADJ_EMPTY)
  {
    filter = _rm_full_adjacents;
  }
  // This case should never append, just in case
  else
  {
    filter = NULL;
  }

  for (unsigned int i = start; i < end; i++)
  {
    finder = t_adjacency_finder_set_strategy(finder, pos_rel[i]);
    adjacents = set_add(adjacents, (TPlacement *)t_adjacency_finder_exec_strategy(finder));
  }

  t_adjacency_destroy(finder);

  // If <filter> set to NULL returns all adjacents previously collected
  if (filter)
  {
    adjacents = set_filter(adjacents, filter);
  }

  // Just in case
  if (set_empty(adjacents))
  {
    set_destroy(adjacents);
    return NULL;
  }

  return adjacents;
}

// ----------------------------------------------------------------------------
// tadjacency.c

struct _TAdjacencyFinder
{
  TGrid *grid;
  TPlacement *ref;
  adjacency_strategy_func strategy;
};

static TPlacement *_find_sxy(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_SXY
{
  // It exists and it's unique
  return t_grid_get_placement(grid, x, y, !edge);
}

static TPlacement *_find_sx(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_SX
{
  // Horizontal side adjacent's placement, if exists it's unique
  TPlacement *sx_adj = NULL;

  // Located before or after depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN)
  {
    sx_adj = t_grid_get_placement(grid, x - 1, y, !edge); // before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1)
  {
    sx_adj = t_grid_get_placement(grid, x + 1, y, !edge); // after
  }

  return sx_adj;
}

static TPlacement *_find_cx1(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CX1
{
  // If it exists, it's unique
  TPlacement *cx1_adj = NULL;

  // Located before or after depending on the edge
  if (edge == EDGE_INF && x < grid->size - 1)
  {
    cx1_adj = t_grid_get_placement(grid, x + 1, y, edge); // after
  }
  else if (edge == EDGE_SUP && x > GRID_XMIN)
  {
    cx1_adj = t_grid_get_placement(grid, x - 1, y, edge); // before
  }

  return cx1_adj;
}

static TPlacement *_find_cx2(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CX2
{
  // If it exists, it's unique
  TPlacement *cx2_adj = NULL;

  // Located before or after depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN)
  {
    cx2_adj = t_grid_get_placement(grid, x - 1, y, edge); // before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1)
  {
    cx2_adj = t_grid_get_placement(grid, x + 1, y, edge); // after
  }

  return cx2_adj;
}

static TPlacement *_find_sy(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_SY
{
  // Vertical side adjacent's placement, if exists it's unique
  TPlacement *y_adj = NULL;

  // Located below or above depending on the edge
  if (edge == EDGE_SUP && y > GRID_YMIN)
  {
    y_adj = t_grid_get_placement(grid, x, y - 1, !edge); // below
  }
  else if (edge == EDGE_INF && y < grid->size - 1)
  {
    y_adj = t_grid_get_placement(grid, x, y + 1, !edge); // above
  }

  return y_adj;
}

static TPlacement *_find_cy1(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CY1

{
  // If it exists, it's unique
  TPlacement *cy1_adj = NULL;

  // Located below or above depending on the edge
  if (edge == EDGE_INF && y < grid->size - 1)
  {
    cy1_adj = t_grid_get_placement(grid, x, y + 1, edge); // below
  }
  else if (edge == EDGE_SUP && y > GRID_YMIN)
  {
    cy1_adj = t_grid_get_placement(grid, x, y - 1, edge); // above
  }

  return cy1_adj;
}

static TPlacement *_find_cy2(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CY2

{
  // If it exists, it's unique
  TPlacement *cy2_adj = NULL;

  // Located below or above depending on the edge
  if (edge == EDGE_INF && y > GRID_YMIN)
  {
    cy2_adj = t_grid_get_placement(grid, x, y - 1, edge); // above
  }
  else if (edge == EDGE_SUP && y < grid->size)
  {
    cy2_adj = t_grid_get_placement(grid, x, y + 1, edge); // below
  }

  return cy2_adj;
}

static TPlacement *_find_ctrans1(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CTRANS1
{
  // If it exists, it's unique
  TPlacement *ctrans1_adj = NULL;

  // Located below and after or above and before depending on the edge
  if (edge == EDGE_INF && x < grid->size - 1 && y < grid->size - 1)
  {
    ctrans1_adj = t_grid_get_placement(grid, x + 1, y + 1, !edge); // below and after
  }
  else if (edge == EDGE_SUP && x > GRID_XMIN && y > GRID_YMIN)
  {
    ctrans1_adj = t_grid_get_placement(grid, x - 1, y - 1, !edge); // above and before
  }

  return ctrans1_adj;
}

static TPlacement *_find_ctrans2(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CTRANS2
{
  // If it exists, it's unique
  TPlacement *ctrans2_adj = NULL;

  // Located below and after or above and before depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN && y > GRID_YMIN)
  {
    ctrans2_adj = t_grid_get_placement(grid, x - 1, y - 1, !edge); // above and before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1 && y < grid->size - 1)
  {
    ctrans2_adj = t_grid_get_placement(grid, x + 1, y + 1, !edge); // below and after
  }

  return ctrans2_adj;
}

static TPlacement *_find_ccis1(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CCIS1
{
  // If it exists, it's unique
  TPlacement *ccis1_adj = NULL;

  // Located below and after or above and before depending on the edge
  if (edge == EDGE_INF && x < grid->size - 1 && y < grid->size - 1)
  {
    ccis1_adj = t_grid_get_placement(grid, x + 1, y + 1, edge); // below and after
  }
  else if (edge == EDGE_SUP && x > GRID_XMIN && y > GRID_YMIN)
  {
    ccis1_adj = t_grid_get_placement(grid, x - 1, y - 1, edge); // above and before
  }

  return ccis1_adj;
}

static TPlacement *_find_ccis2(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_CCIS2
{
  // If it exists, it's unique
  TPlacement *ccis2_adj = NULL;

  // Located below and after or above and before depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN && y > GRID_YMIN)
  {
    ccis2_adj = t_grid_get_placement(grid, x - 1, y - 1, edge); // above and before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1 && y < grid->size - 1)
  {
    ccis2_adj = t_grid_get_placement(grid, x + 1, y + 1, edge); // below and after
  }

  return ccis2_adj;
}

static TPlacement *_find_copp(TGrid *grid, unsigned int x, unsigned int y, unsigned char edge) // POS_REL_COPP
{
  // If it exists, it's unique
  TPlacement *copp_adj = NULL;

  // Located below and before or above and after depending on the edge
  if (edge == EDGE_INF && x > GRID_XMIN && y < grid->size - 1)
  {
    copp_adj = t_grid_get_placement(grid, x - 1, y + 1, !edge); // below and before
  }
  else if (edge == EDGE_SUP && x < grid->size - 1 && y > GRID_YMIN)
  {
    copp_adj = t_grid_get_placement(grid, x + 1, y - 1, !edge); // above and after
  }

  return copp_adj;
}

TAdjacencyFinder *t_adjacency_finder_create(TGrid *grid, TPlacement *ref)
{
  TAdjacencyFinder *finder = t_malloc(sizeof(TAdjacencyFinder));

  finder->grid = grid;
  finder->ref = ref;

  return finder;
}

void t_adjacency_destroy(TAdjacencyFinder *finder)
{
  // Important: it doesn't destroy the grid, either the concerned placement
  free(finder);
}

// TODO: exit code or void return.
TAdjacencyFinder *t_adjacency_finder_set_strategy(TAdjacencyFinder *finder, int context)
{
  switch (context)
  {
  case POS_REL_SXY:
    finder->strategy = _find_sxy;
    break;
  case POS_REL_SX:
    finder->strategy = _find_sx;
    break;
  case POS_REL_SY:
    finder->strategy = _find_sy;
    break;
  case POS_REL_CX1:
    finder->strategy = _find_cx1;
    break;
  case POS_REL_CX2:
    finder->strategy = _find_cx2;
    break;
  case POS_REL_CY1:
    finder->strategy = _find_cy1;
    break;
  case POS_REL_CY2:
    finder->strategy = _find_cy2;
    break;
  case POS_REL_CTRANS1:
    finder->strategy = _find_ctrans1;
    break;
  case POS_REL_CTRANS2:
    finder->strategy = _find_ctrans2;
    break;
  case POS_REL_CCIS1:
    finder->strategy = _find_ccis1;
    break;
  case POS_REL_CCIS2:
    finder->strategy = _find_ccis2;
    break;
  case POS_REL_COPP:
    finder->strategy = _find_copp;
    break;
  }

  return finder;
}

TPlacement *t_adjacency_finder_exec_strategy(TAdjacencyFinder *finder)
{
  unsigned int x = t_placement_get_x(finder->ref);
  unsigned int y = t_placement_get_y(finder->ref);
  unsigned char edge = t_placement_get_edge(finder->ref);

  return finder->strategy(finder->grid, x, y, edge);
}

// ----------------------------------------------------------------------------
// tcompatibility.h

struct _TCompatibility
{
  Triomino *ref;
  compatibility_strategy_func strategy;
};

TCompatibility *t_compatibility_create(Triomino *ref)
{
  TCompatibility *comp = t_malloc(sizeof(TCompatibility));

  comp->ref = ref;

  return comp;
}

void t_compatibility_destroy(TCompatibility *comp)
{
  // Important: it doesn't destroy the ressources
  free(comp);
}

int t_compatibility_set_strategy(TCompatibility *comp, int context)
{
  switch (context)
  {
  case (POS_REL_SXY | ROT_REL_AA): // OK
  case (POS_REL_SX | ROT_REL_BB):
  case (POS_REL_SY | ROT_REL_CC):
    comp->strategy = triomino_bc_cb_compatible;
    break;
  case (POS_REL_SXY | ROT_REL_AC): // OK
  case (POS_REL_SX | ROT_REL_BA):
  case (POS_REL_SY | ROT_REL_CB):
    //
    comp->strategy = triomino_bc_ba_compatible;
    break;
  case (POS_REL_SXY | ROT_REL_AB): // OK
  case (POS_REL_SX | ROT_REL_BC):
  case (POS_REL_SY | ROT_REL_CA):
    //
    comp->strategy = triomino_bc_ac_compatible;
    break;
  case (POS_REL_SXY | ROT_REL_CA): // OK
  case (POS_REL_SX | ROT_REL_AB):
  case (POS_REL_SY | ROT_REL_BC):
    //
    comp->strategy = triomino_ab_cb_compatible;
    break;
  case (POS_REL_SXY | ROT_REL_CC): // OK
  case (POS_REL_SX | ROT_REL_AA):
  case (POS_REL_SY | ROT_REL_BB):
    //
    comp->strategy = triomino_ab_ba_compatible;
    break;
  case (POS_REL_SXY | ROT_REL_CB): // OK
  case (POS_REL_SX | ROT_REL_AC):
  case (POS_REL_SY | ROT_REL_BA):
    //
    comp->strategy = triomino_ab_ac_compatible;
    break;
  case (POS_REL_SXY | ROT_REL_BA): // OK
  case (POS_REL_SX | ROT_REL_CB):
  case (POS_REL_SY | ROT_REL_AC):
    //
    comp->strategy = triomino_ca_cb_compatible;
    break;
  case (POS_REL_SXY | ROT_REL_BC): // OK
  case (POS_REL_SX | ROT_REL_CA):
  case (POS_REL_SY | ROT_REL_AB):
    //
    comp->strategy = triomino_ca_ba_compatible;
    break;
  case (POS_REL_SXY | ROT_REL_BB): // OK
  case (POS_REL_SX | ROT_REL_CC):
  case (POS_REL_SY | ROT_REL_AA):
    //
    comp->strategy = triomino_ca_ac_compatible;
    break;
  }
  return 1;
}

bool t_compatibility_exec_strategy(TCompatibility *comp, const Triomino *target)
{
  return comp->strategy(comp->ref, target);
}
