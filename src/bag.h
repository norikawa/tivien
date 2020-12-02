#ifndef tivien_bag_h
#define tivien_bag_h

#include "common.h"
#include "string.h"

typedef struct {
    //char* name;
    char* data;
    int* state; //Currently only contains the index, but int* just for future proofing
    int* sequence; //The integers here represent the index value of the start of each piece
} Bag;

int get_bag_s(Bag* bag);
int get_bag_i(Bag* bag);
int get_bag_q(Bag* bag);

void set_bag_i(Bag* bag, int input);

void inc_bag_i(Bag* bag);

char* get_bag_piece(Bag* bag);
char* draw_bag_piece(Bag* bag);
void build_bag(Bag* bag, char* input);
void randomize_sequence(Bag* bag);

#endif