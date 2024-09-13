#include <stdio.h>
#include <stdlib.h>
#include <TXlib.h>
#include <assert.h>
#include <malloc.h>

const int CHUNK = 12; // number of strings in one CHUNK

enum GET_TEXT{
    FULL_LINE = 0, // GetLine reached '\n'
    FULL_CHUNK = 0, // CHUNK had been fulled
    EOF_VALUE = 1,  // GetLine read EOF

};

struct text // text CHUNK
{
    int n; // number of strings
    int* str_length; // data of lengths of strings
    char** number_of_string; // data of pointers to strings
};

bool ReadChunk( text* main_text, FILE* text_file); // read CHUNK
bool GetLine(text* main_text, FILE* text_file,int i); // read string
int ReadText(text** text_chunks, FILE* text_file);
void Reallocing(char** number_of_string, int ch, int counter, int i); // add place in string for symbol
void LineSort(text* main_text); // sort lines

int main()
{
    FILE* text_file = fopen("text.txt", "r");

    text** text_chunks = (text**)calloc(1, sizeof(text*));
    text_chunks[0] = (text*)calloc(1, sizeof(text));
    *(text_chunks[0]) = {
    CHUNK,
    (int*)calloc(CHUNK, sizeof(int)),
    (char**)calloc(CHUNK, sizeof(char*))
    };

    int number_of_chunks = ReadText(text_chunks, text_file);

    for(int j = 0; j < number_of_chunks + 1; j++)
    {
        for(int k = 0; k < CHUNK; k++)
        {
            for(int i = 0; i < (text_chunks[j] -> str_length)[k]; i++)
            printf("%c", (text_chunks[j] -> number_of_string)[k][i]);
        }
    }

    return 0;
}

bool ReadChunk( text* main_text, FILE* text_file)
{
    assert(main_text -> str_length != NULL);
    assert(main_text -> number_of_string != NULL);

    for(int i = 0; i < CHUNK; i++)
    {
        if(GetLine(main_text, text_file, i))
            return EOF_VALUE;
    }
    return FULL_CHUNK;
}

bool GetLine( text* main_text, FILE* text_file,int i)
{
    assert(main_text -> str_length != NULL);
    assert(main_text -> number_of_string != NULL);

    int ch = 'a';
    int counter = 1;
    while((ch = fgetc(text_file)) != '\n' && ch != EOF)
    {
        counter++;
        Reallocing(main_text -> number_of_string, ch, counter, i);
    }
    if( ch == EOF)
    {
        return EOF_VALUE;
    }
    if(ch == '\n')
        Reallocing(main_text -> number_of_string, '\n', counter, i);
    main_text -> str_length[i] = counter ;
    return FULL_LINE;
}

void Reallocing(char** number_of_string, int ch, int counter, int i)
{
    assert(number_of_string != NULL);

    number_of_string[i] = (char*)realloc(number_of_string[i], counter*sizeof(char));
    if(number_of_string == NULL)
    {
        printf("Ошибка работы realloc\n");
    }
    number_of_string[i][counter - 1] = (char)ch;
}

int ReadText(text** text_chunks, FILE* text_file)
{
    assert(text_chunks != NULL);

    int number_of_chunks = 0;

    while(!ReadChunk(text_chunks[number_of_chunks], text_file))
    {
        number_of_chunks++;
        text_chunks = (text**)realloc(text_chunks, (number_of_chunks)*sizeof(text*));
        text_chunks[number_of_chunks] = (text*)calloc(1, sizeof(text));

        *(text_chunks[number_of_chunks]) = {
            CHUNK,
            (int*)calloc(CHUNK, sizeof(int)),
            (char**)calloc(CHUNK, sizeof(char*))
            };
    }
    return number_of_chunks;
}



