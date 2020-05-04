#ifndef tivien_piece_h
#define tivien_piece_h

#include "common.h"
#include "util.h"
#include "string.h"

void build_piece(Piece* piece, char* data_str);

int get_piece_x(Piece* piece);
int get_piece_y(Piece* piece);
int get_piece_r(Piece* piece);
int get_piece_v(Piece* piece);
int get_piece_o(Piece* piece);
int get_piece_m(Piece* piece);
int get_piece_c(Piece* piece);
int get_piece_s(Piece* piece);
int get_piece_z(Piece* piece);

void set_piece_x(Piece* piece, int input);
void set_piece_y(Piece* piece, int input);
void set_piece_r(Piece* piece, int input);
void set_piece_v(Piece* piece, int input);
void set_piece_o(Piece* piece, int input);
void set_piece_m(Piece* piece, int input);
void set_piece_c(Piece* piece, int input);
void set_piece_s(Piece* piece, int input);
void set_piece_z(Piece* piece, int input);

void inc_piece_x(Piece* piece);
void inc_piece_y(Piece* piece);
void inc_piece_r(Piece* piece);

void dec_piece_x(Piece* piece);
void dec_piece_y(Piece* piece);
void dec_piece_r(Piece* piece);

int get_piece_cell(Piece* piece, int x, int y, int r);

#endif