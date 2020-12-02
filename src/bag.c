#include "bag.h"

//TODO: get_bag_m, Rewrite get_bag_piece to take a second argument int index representing the index of the piece desired, to allow for access of arbitrary pieces in the bag
//data[0] = mode, data[1..2] = size, data[3+] = pieces

int get_bag_s(Bag* bag) {
    return substring_to_int(bag->data, BAG_S, BAG_S + 1);
}

int get_bag_i(Bag* bag) {
    return bag->state[BAG_I];
}

int get_bag_q(Bag* bag) {
    return bag->sequence[get_bag_i(bag)];
}

void set_bag_i(Bag* bag, int input) {
    bag->state[BAG_I] = input;
}

void inc_bag_i(Bag* bag) {
    bag->state[BAG_I]++;
}

char* get_bag_piece(Bag* bag) {
    //Magic Numbers via size/locations of piece->data/piece->matrix information
    int piece_index = get_bag_q(bag);
    int piece_states = substring_to_int(bag->data, piece_index + 3, piece_index + 4);
    int piece_size = substring_to_int(bag->data, piece_index + 5, piece_index + 6);
    int piece_end = 6 + piece_index + (piece_size * piece_size * piece_states);
    char* piece_str = get_substring(bag->data, piece_index, piece_end);
    return piece_str;
}

void randomize_bag_sequence(Bag* bag) {
    int size = get_bag_s(bag);
    for(int first_index = 0; first_index < size - 1; first_index++) {
        int second_index = first_index + rand() / (RAND_MAX / (size - first_index) + 1);
        int holder = bag->sequence[second_index];
        bag->sequence[second_index] = bag->sequence[first_index];
        bag->sequence[first_index] = holder;
    }
}

char* draw_bag_piece(Bag* bag) {
    int size = get_bag_s(bag);
    int index = get_bag_i(bag);
    char* piece = get_bag_piece(bag);
    if(index + 1 >= size) {
        set_bag_i(bag, 0);
        randomize_bag_sequence(bag);
    } else {
        inc_bag_i(bag);
    }
    return piece;
}

void build_bag(Bag* bag, char* input) {
    bag->state = malloc(sizeof(int) * BAG_STATE_SIZE);
    bag->state[BAG_I] = 0; //[0] = index, default value: 0
    int data_char_count = strlen(input);
    bag->data = malloc(CHAR_SIZE * data_char_count);
    memset(bag->data, '\0', CHAR_SIZE * data_char_count);
    strncpy(bag->data, input, data_char_count);
    int bag_size = substring_to_int(input, 1, 2);//[1..2] = size
    bag->sequence = malloc(sizeof(int) * bag_size);
    int current_index =  3; //0 = mode, 1..2 = size
    for(int current_piece = 0; current_piece < get_bag_s(bag); current_piece++) {
        int states = substring_to_int(bag->data, current_index + 3, current_index + 4);
        int size = substring_to_int(bag->data, current_index + 5, current_index + 6);
        bag->sequence[current_piece] = current_index;
        current_index += states * size * size + 7;
    }

    randomize_bag_sequence(bag);
}