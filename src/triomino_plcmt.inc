#include "triomino.h"

struct _Coord {
    unsigned int x;
    unsigned int y;
};

struct _TriominoPlcmt {
    Triomino *triomino;
    struct _Coord *pos;
    unsigned int player;
    unsigned int rotation;
};