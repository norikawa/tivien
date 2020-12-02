//TODO: Get rid of this entire file!!!

#ifndef tivien_structs_h
#define tivien_structs_h

#include "piece.h"
#include "bag.h"
#include "playfield.h"

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