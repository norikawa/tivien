#include "bag.h"

//TODO: Add functions to bag.h, fix get_piece (I'm rather certain it *doesn't* work, but I haven't tested it yet)
int get_s(Bag* bag) {
    return bag->data[1];
}

int get_i(Bag* bag) {
    return bag->state[0];
}

int get_q(Bag* bag) {
    return bag->sequence[get_i(bag)];
}

void inc_i(Bag* bag) {
    bag->state[0]++;
}

//This likely doesn't work, since the char* being returned will be blank outside of the function scope
//Should replace with a solution ala get_substring or int_to_str in string.c
//Although... I haven't tested this yet, so maybe it does work

//But probably not
char* get_piece(Bag* bag) {
    int piece_index = get_q(bag);
    int piece_states = get_substring(bag->data, piece_index + 3, piece_index + 4);
    int piece_size = get_substring(bag->data, piece_index + 5, piece_index + 6);
    int piece_end = index + (piece_size * piece_size * piece_states);
    char* piece_str = get_substring(bag->data, piece_index, piece_end);
    return piece_str;
}