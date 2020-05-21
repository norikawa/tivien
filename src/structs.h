#ifndef tivien_structs_h
#define tivien_structs_h

//Data: Does *not* change; Is required for building an item
//State: *Does* change; Is not required for building an item

typedef struct {
    //char* name;
    char* matrix;
    int* data;
    int* state;
} Piece;

typedef struct {
    //char* name;
    char* data;
    int* state; //Currently only contains the index, but int* just for future proofing
    int* sequence; //The integers here represent the index value of the start of each piece
} Bag;

typedef struct {
    //char* name;
    int* data;
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
    //Ruleset ruleset;
    //char* name;
    char* state;
} Game;

#endif