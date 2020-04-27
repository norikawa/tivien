#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_x(char* state, int x) {
    char new_x[3];
    memset(new_x, '\0', sizeof(new_x));
    sprintf(new_x, "%i", x);
    if(x < 10) {
        state[2] = new_x[0];
        state[1] = '0';
        state[0] = '0';
    } else if(x < 100) {
        state[2] = new_x[1];
        state[1] = new_x[0];
        state[0] = '0';
    } else {
        state[2] = new_x[2];
        state[1] = new_x[1];
        state[0] = new_x[0];
    }
}

int get_x(char* state) {
    char x[3];
    memset(x, '\0', sizeof(x));
    char* ptr;
    strncpy(x, state, 3);
    int output = (int)strtol(x, &ptr, 10);
    return output;
}


int main(int argc, char** argv) {
    char* prewritten = "00501102000";
    char* state = malloc(sizeof(char) * 11);
    strncpy(state, prewritten, 11);
    printf("%s\n", state);
    set_x(state, 457);
    printf("%s\n", state);
    free(state);
    return 0;
}