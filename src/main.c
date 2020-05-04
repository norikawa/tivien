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
    char* test_bag_data = "0030070403001111000010010011000111100110010010005040301011100001001101000011101001011001000401021111";
    Bag test_bag;
    build_bag(&test_bag, test_bag_data);
    char* test_piece = get_piece(&test_bag);
    printf("%s\n", test_piece);
    return 0;
}