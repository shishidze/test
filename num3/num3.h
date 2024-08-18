#ifndef NUM3_H
#define NUM3_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 50

typedef struct Dict{
    char key[MAX_WORD_LENGTH];
    char value[MAX_LINE_LENGTH - MAX_WORD_LENGTH];
} Dict;

void generate_dict_from_file(const char *file_path, int count);
int open_file(const char *file_path);

#endif