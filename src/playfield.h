#ifndef tivien_playfield_h
#define tivien_playfield_h

#include "string.h"
#include "common.h"

typedef struct {
    //char* name;
    int* data;
    char* state;
} Playfield;

int get_playfield_m(Playfield* playfield);
int get_playfield_w(Playfield* playfield);
int get_playfield_h(Playfield* playfield);

int get_playfield_cell(Playfield* playfield, int x, int y);
void set_playfield_cell(Playfield* playfield, int x, int y, int input);

void build_playfield(Playfield* playfield, char* input);
#endif