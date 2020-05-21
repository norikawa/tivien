#include "piece.h"

//Piece Data Values
//m : Mode Switch
//c : Color/Texture
//s : Rotation States Count
//z : Bounding Box Size

//Piece State Values
//x : x-position
//y : y-position
//r : Current Rotation State
//v : Mode Override
//o : Color/Texture Override

//TODO: Add rotation functions to piece.h

//Given the piece data and piece name, sets the relevant data for the given piece object
void build_piece(Piece* piece, char* input) {
    //piece->name = name;
    int parsed_data[4];
    for(int data_index = 0; data_index <= 3; data_index++) {
        int range_end = data_index * 2;
        int range_start = range_end - 1;
        if(range_start < 0) {
            range_start = 0;
        }
        insert_int(parsed_data, substring_to_int(input, range_start, range_end), data_index);
    }
    piece->data = parsed_data;
    size_t matrix_letters = piece->data[2] * piece->data[3] * piece->data[3];
    size_t matrix_size = matrix_letters * CHAR_SIZE;
    piece->matrix = malloc(matrix_size);
    memset(piece->matrix, '\0', matrix_size);
    //TODO: Fix this for loop's existence. This should probably be a call to strncpy() or similar
    for(int current_position = 0; current_position < matrix_letters; current_position++) {
        piece->matrix[current_position] = input[7 + current_position];
    }
}

int get_piece_x(Piece* piece) {
    return piece->state[0];
}

int get_piece_y(Piece* piece) {
    return piece->state[1];
}

int get_piece_r(Piece* piece) {
    return piece->state[2];
}

int get_piece_v(Piece* piece) {
    return piece->state[3];
}

int get_piece_o(Piece* piece) {
    return piece->state[4];
}

int get_piece_m(Piece* piece) {
    return piece->data[0];
}

int get_piece_c(Piece* piece) {
    return piece->data[1];
}

int get_piece_s(Piece* piece) {
    return piece->data[2];
}
int get_piece_z(Piece* piece) {
    return piece->data[3];
}

void set_piece_x(Piece* piece, int input) {
    piece->state[0] = input;
}

void set_piece_y(Piece* piece, int input) {
    piece->state[1] = input;
}

void set_piece_r(Piece* piece, int input) {
    piece->state[2] = input;
}

void set_piece_v(Piece* piece, int input) {
    piece->state[3] = input;
}

void set_piece_o(Piece* piece, int input) {
    piece->state[4] = input;
}

void set_piece_m(Piece* piece, int input) {
    piece->data[0] = input;
}

void set_piece_c(Piece* piece, int input) {
    piece->data[1] = input;
}

void set_piece_s(Piece* piece, int input) {
    piece->data[2] = input;
}

void set_piece_z(Piece* piece, int input) {
    piece->data[3] = input;
}

void inc_piece_x(Piece* piece) {
    set_piece_x(piece, get_piece_x(piece) + 1);
}

void inc_piece_y(Piece* piece) {
    set_piece_y(piece, get_piece_y(piece) + 1);
}

void inc_piece_r(Piece* piece) {
    set_piece_r(piece, get_piece_r(piece) + 1);
}

void dec_piece_x(Piece* piece) {
    set_piece_x(piece, get_piece_x(piece) - 1);
}

void dec_piece_y(Piece* piece) {
    set_piece_y(piece, get_piece_y(piece) - 1);
}

void dec_piece_r(Piece* piece) {
    set_piece_r(piece, get_piece_r(piece) - 1);
}

int get_piece_cell(Piece* piece, int x, int y, int r) {
    int size = get_piece_z(piece);
    int cell_index = (size * size * r) + (size * y) + x;
    char output = piece->matrix[cell_index] - '0';
    return (int)output;
}

void rotate_piece_cw(Piece* piece) {
    if(get_piece_r(piece) >= get_piece_s(piece) - 1) {
        set_piece_r(piece, 0);
    } else {
        inc_piece_r(piece);
    }
}

void rotate_piece_ccw(Piece* piece) {
    if(get_piece_r(piece) <= 0) {
        set_piece_r(piece, get_piece_s(piece) - 1);
    } else {
        dec_piece_r(piece);
    }
}