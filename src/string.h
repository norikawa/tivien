#ifndef tivien_string_h
#define tivien_string_h

#include "common.h"
#include "util.h"

int str_to_int(char* input);
char* int_to_str(int input);
void add_char(char* string, char addition);
char* get_substring(char* string, int low, int high);
void set_substring(char* string, char* replacement, int start_index);
int substring_to_int(char* string, int low, int high);
void append_str(char* destination, char* addition);

#endif