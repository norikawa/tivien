#include "piece.h"

//Given the piece data and piece name, sets the relevant data for the given piece object
void build_piece(Piece* piece, char* data_str) {
    //piece->name = name;
    int parsed_data[4];
    for(int data_index = 0; data_index <= 3; data_index++) {
        int range_end = data_index * 2;
        int range_start = range_end - 1;
        if(range_start < 0) {
            range_start = 0;
        }
        insert_int(parsed_data, substring_to_int(data_str, range_start, range_end), data_index);
    }
    piece->data = parsed_data;
    size_t matrix_letters = piece->data[2] * piece->data[3] * piece->data[3];
    size_t matrix_size = matrix_letters * CHAR_SIZE;
    piece->matrix = malloc(matrix_size);
    memset(piece->matrix, '\0', matrix_size);
    for(int current_position = 0; current_position < matrix_letters; current_position++) {
        piece->matrix[current_position] = data_str[7 + current_position];
    }
}

int get_x(Piece* piece) {
    return piece->state[0];
}

int get_y(Piece* piece) {
    return piece->state[1];
}

int get_r(Piece* piece) {
    return piece->state[2];
}

int get_v(Piece* piece) {
    return piece->state[3];
}

int get_o(Piece* piece) {
    return piece->state[4];
}

int get_m(Piece* piece) {
    return piece->data[0];
}

int get_c(Piece* piece) {
    return piece->data[1];
}

int get_s(Piece* piece) {
    return piece->data[2];
}
int get_z(Piece* piece) {
    return piece->data[3];
}

void set_x(Piece* piece, int input) {
    piece->state[0] = input;
}

void set_y(Piece* piece, int input) {
    piece->state[1] = input;
}

void set_r(Piece* piece, int input) {
    piece->state[2] = input;
}

void set_v(Piece* piece, int input) {
    piece->state[3] = input;
}

void set_o(Piece* piece, int input) {
    piece->state[4] = input;
}

void set_m(Piece* piece, int input) {
    piece->data[0] = input;
}

void set_c(Piece* piece, int input) {
    piece->data[1] = input;
}

void set_s(Piece* piece, int input) {
    piece->data[2] = input;
}

void set_z(Piece* piece, int input) {
    piece->data[3] = input;
}

void inc_x(Piece* piece) {
    set_x(piece, get_x(piece) + 1);
}

void inc_y(Piece* piece) {
    set_y(piece, get_y(piece) + 1);
}

void inc_r(Piece* piece) {
    set_r(piece, get_r(piece) + 1);
}

void dec_x(Piece* piece) {
    set_x(piece, get_x(piece) - 1);
}

void dec_y(Piece* piece) {
    set_y(piece, get_y(piece) - 1);
}

void dec_r(Piece* piece) {
    set_r(piece, get_r(piece) - 1);
}

int get_cell(Piece* piece, int x, int y, int r) {
    int size = get_z(piece);
    int cell_index = (size * size * r) + (size * y) + x;
    char output = piece->matrix[cell_index] - '0';
    return (int)output;
}