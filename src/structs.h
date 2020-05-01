#ifndef tivien_structs_h
#define tivien_structs_h

typedef struct {
    //char* name;
    char* matrix;
    int* data;
    int* state;
} Piece;

typedef struct {
    //char* name;
    char* data;
    char* state;
    int* sequence; //The integers here represent the index value of the start of each piece
} Bag;

typedef struct {
    //char* name;
    char* data;
    char* state;
} Playfield;

typedef struct {
    char* name;
    char* data;
} Ruleset;

typedef struct {
    Piece current;
    Piece hold;
    Bag bag;
    Playfield playfield;
    Ruleset ruleset;
    char* name;
    char* state;
} Game;

#endif