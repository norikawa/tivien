#ifndef tivien_structs_h
#define tivien_structs_h

typedef struct {
    char* name, matrix;
    int x, y, r, color, state, size, mode;
} Piece;

typedef struct {
    Piece* pieces;
    int size, max;
} Bag;

typedef struct {
    Bag bag;
    Piece current, hold;
    //Playfield playfield;
} Game;

#endif