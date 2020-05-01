#ifndef tivien_piece_h
#define tivien_piece_h

#include "common.h"
#include "util.h"
#include "string.h"

void build_piece(Piece* piece, char* data_str);

int get_x(Piece* piece);
int get_y(Piece* piece);
int get_r(Piece* piece);
int get_v(Piece* piece);
int get_o(Piece* piece);
int get_m(Piece* piece);
int get_c(Piece* piece);
int get_s(Piece* piece);
int get_z(Piece* piece);

void set_x(Piece* piece, int input);
void set_y(Piece* piece, int input);
void set_r(Piece* piece, int input);
void set_v(Piece* piece, int input);
void set_o(Piece* piece, int input);
void set_m(Piece* piece, int input);
void set_c(Piece* piece, int input);
void set_s(Piece* piece, int input);
void set_z(Piece* piece, int input);

void inc_x(Piece* piece);
void inc_y(Piece* piece);
void inc_r(Piece* piece);

void dec_x(Piece* piece);
void dec_y(Piece* piece);
void dec_r(Piece* piece);

int get_cell(Piece* piece, int x, int y, int r)

#endif