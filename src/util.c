#include "util.h"

size_t count_digits(int input) {
    size_t output;
    input = abs(input);
    for(int power_of_ten = 1; power_of_ten <= input; power_of_ten *= 10) {
        output++;
    }
    return output;
}

size_t count_characters(int input) {
    size_t output;
    if(input < 0) {
        output++;
    }
    output += count_digits(input);
    return output;
}

//Inserts addition at index in array
void insert_int(int* array, int addition, int index) {
    array[index] = addition;
}