//Project-wide TODO:
//Bag processing
//Playfield processing
//Ruleset processing
//File handling
//Sound 
//Graphics
//Player Input
//Scoring??
//Timing??
//Game setup in general
//INI Parser (likely)

#include "string.h"
#include "util.h"
#include "piece.h"
#include "structs.h"
#include "defines.h"
#include "common.h"
#include "bag.h"

int main(int argc, char** argv) {
    srand(time(NULL));
    char* test_bag_data = "007004010211110060404000011110000000000100010001000100000000011110000010001000100010000504030101110000100110100001110100101100100020403011110000010011001000011110100110010001040311001100000101101000011001101011010000304031001110000110100100001110010100101100070403001111000010010011000111100110010010";
    Bag test_bag;
    build_bag(&test_bag, test_bag_data);
    char* test_piece = get_piece(&test_bag);
    printf("%s\n", test_piece);
    return 0;
}