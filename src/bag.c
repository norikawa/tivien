#include "bag.h"

int get_bag_s(Bag* bag) {
    return substring_to_int(bag->data, 1, 2);
}

int get_bag_i(Bag* bag) {
    return bag->index;
}

int get_bag_q(Bag* bag) {
    return bag->sequence[get_bag_i(bag)];
}

void set_bag_i(Bag* bag, int input) {
    bag->index = input;
}

void inc_bag_i(Bag* bag) {
    bag->index++;
}

char* get_piece(Bag* bag) {
    int piece_index = get_bag_q(bag);
    int piece_states = substring_to_int(bag->data, piece_index + 3, piece_index + 4);
    int piece_size = substring_to_int(bag->data, piece_index + 5, piece_index + 6);
    int piece_end = 6 + piece_index + (piece_size * piece_size * piece_states);
    char* piece_str = get_substring(bag->data, piece_index, piece_end);
    return piece_str;
}

char* draw_piece(Bag* bag) {
    int size = get_bag_s(bag);
    int index = get_bag_i(bag);
    char* piece = get_piece(bag);
    if(index + 1 >= size) {
        set_bag_i(bag, 0);
        randomize_sequence(bag);
    } else {
        inc_bag_i(bag);
    }
    return piece;
}

void randomize_sequence(Bag* bag) {
    int size = get_bag_s(bag);
    for(int first_index = 0; first_index < size - 1; first_index++) {
        int second_index = first_index + rand() / (RAND_MAX / (size - first_index) + 1);
        int holder = bag->sequence[second_index];
        bag->sequence[second_index] = bag->sequence[first_index];
        bag->sequence[first_index] = holder;
    }
}

void build_bag(Bag* bag, char* input) {
    bag->index = 0;
    bag->data = input;
    int bag_size = get_bag_s(bag);
    bag->sequence = malloc(sizeof(int) * bag_size);
    int current_index = 3;
    for(int current_piece = 0; current_piece < get_bag_s(bag); current_piece++) {
        int states = substring_to_int(bag->data, current_index + 3, current_index + 4);
        int size = substring_to_int(bag->data, current_index + 5, current_index + 6);
        bag->sequence[current_piece] = current_index;
        current_index += states * size * size + 7;
    }
    randomize_sequence(bag);
}