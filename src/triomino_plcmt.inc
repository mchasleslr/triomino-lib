#include "triomino.h"

struct _TriominoPlcmt {
    Triomino *triomino;
    unsigned int pos[2];
    unsigned int player;
    unsigned int rotation;
};