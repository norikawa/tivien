#include "string.h"

//Takes a string as input, and converts it into the int it represents
//Only functions if all characters in the input are 0-9
int str_to_int(char* input) {
    char* unused;
    int output = (int)strtol(input, &unused, 10);
    return output;
}

//Returns a char* representing the string for the number
//e.g. an int of 126 is returned as a char* of form {'1', '2', '6'}
char* int_to_str(int input) {
    size_t size = count_characters(input) * CHAR_SIZE;
    char* output = malloc(size);
    memset(output, '\0', size);
    sprintf(output, "%i", input);
    return output;
}

//Adds char addition to the end of char* string (increasing its length by one)
void add_char(char* string, char addition) {
    size_t letter_count = strlen(string);
    size_t old_size = letter_count * CHAR_SIZE;
    size_t new_size = old_size + CHAR_SIZE;
    char* holder = malloc(old_size);
    memset(holder, '\0', new_size);
    strncpy(holder, string, old_size);
    holder[letter_count] = addition;
    string = realloc(string, new_size);
    strncpy(string, holder, new_size);
}

//Returns an array of the values string[low] to string[high]
char* get_substring(char* string, int low, int high) {
    size_t output_size = CHAR_SIZE * (high - low + 1);
    char* output = malloc(output_size);
    memset(output, '\0', output_size);
    for(int current_char = low; current_char <= high; current_char++) {
        output[current_char - low] = string[current_char];
    }
    return output;
}

//Sets strlen(replacement) values starting from start_index into what's represented in replacement
//e.g., set_substring("hello", "ome", 1) changes string into "homeo"
void set_substring(char* string, char* replacement, int start_index) {
    for(int current_position = start_index; current_position <= strlen(replacement); current_position++) {
        string[current_position] = replacement[current_position - start_index];
    }
} 

//Gets the substring string[low] to string[high], and then returns its representation as an int
//Only works if the specified substring is 0-9 only
int substring_to_int(char* string, int low, int high) {
    int output;
    char* substring = get_substring(string, low, high);
    output = str_to_int(substring);
    return output;
}

//Appends addition to the end of destination
void append_str(char* destination, char* addition) {
    size_t dest_size = strlen(destination);
    size_t add_size = strlen(addition);
    size_t new_size = CHAR_SIZE * (dest_size + add_size);
    char* holder = malloc(new_size);
    memset(holder, '\0', new_size);
    strncpy(holder, destination, dest_size);
    for(int current_char = 0; current_char < add_size; current_char++) {
        holder[dest_size + current_char] = addition[current_char];
    }
    destination = realloc(destination, new_size);
    strncpy(destination, holder, new_size);
}