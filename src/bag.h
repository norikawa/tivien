#ifndef tivien_bag_h
#define tivien_bag_h

#include "common.h"
#include "string.h"

int get_bag_s(Bag* bag);
int get_bag_i(Bag* bag);
int get_bag_q(Bag* bag);

void set_bag_i(Bag* bag, int input);

void inc_bag_i(Bag* bag);

char* get_piece(Bag* bag);
char* draw_piece(Bag* bag);
void build_bag(Bag* bag, char* input);
void randomize_sequence(Bag* bag);

#endif