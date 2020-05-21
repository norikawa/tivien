#include "playfield.h"
 
//Playfield Data Values
//m : Mode Switch; currently unused
//w : Width 
//h : Height 

int get_playfield_m(Playfield* playfield) {
    return playfield->data[0];
}

int get_playfield_w(Playfield* playfield) {
    return playfield->data[1];
}

int get_playfield_h(Playfield* playfield) {
    return playfield->data[2];
}

int get_playfield_cell(Playfield* playfield, int x, int y) {
    if(!(x >= get_playfield_w(playfield) || y >= get_playfield_h(playfield))) {
        int pos = get_playfield_w(playfield) * y + x;
        return substring_to_int(playfield->state, pos, pos);
    }
    return -1;
}

void set_playfield_cell(Playfield* playfield, int x, int y, int input) {
    if(!(x >= get_playfield_w(playfield) || y >= get_playfield_h(playfield))) {
        int pos = get_playfield_w(playfield) * y + x;
        //TODO: Would be better with an "int_to_char" function instead
        playfield->state[pos] = int_to_str(input)[0];
    }
}

void build_playfield(Playfield* playfield, char* input) {
    //TODO: Would be better with a "char_to_int" function instead
    //ADD: Actually... would it?
    playfield->data[0] = substring_to_int(input, 0, 0);
    playfield->data[1] = substring_to_int(input, 1, 3);
    playfield->data[2] = substring_to_int(input, 4, 6);
    int playfield_size = CHAR_SIZE * get_playfield_w(playfield) * get_playfield_h(playfield);
    playfield->state = malloc(playfield_size);
    memset(playfield->state, '\0', playfield_size);
}

