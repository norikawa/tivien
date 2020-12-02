#ifndef tivien_defines_h
#define tivien_defines_h

#define CHAR_SIZE sizeof(char)

//Used for sizes of particular points of data/state
#define SINGLE 1
#define DOUBLE 2
#define TRIPLE 3

//See format reference for details
#define PIECE_MANIFEST_SIZE 7

#define PIECE_DATA_SIZE 4
#define PIECE_M 0
#define PIECE_C 1
#define PIECE_R 2
#define PIECE_S 3

#define PIECE_STATE_SIZE 5
#define PIECE_X 0
#define PIECE_Y 1
#define PIECE_R 2
#define PIECE_V 3
#define PIECE_O 4

#define BAG_DATA_SIZE 2
#define BAG_M 0
#define BAG_S 1

#define BAG_STATE_SIZE 1
#define BAG_I 0

#define PLAYFIELD_DATA_SIZE 3
#define PLAYFIELD_M 0
#define PLAYFIELD_W 1
#define PLAYFIELD_H 2

#endif