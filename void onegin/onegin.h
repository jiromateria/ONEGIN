#ifndef ONEGIN_H_INCLUDED
#define ONEGIN_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

struct DataText{

    int text_size;
    int number_of_strings;
    char* buffer;
};

struct DataStrings{

    int string_len;
    char* string_begin;
};

#endif // ONEGIN_H_INCLUDED
