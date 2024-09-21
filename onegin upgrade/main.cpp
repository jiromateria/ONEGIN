#include "text_work.h"
#include "sort.h"

int main()
{
    DataText main_text = {};

    FILE* fonegin = fopen( "text.txt" , "r" );
    DataStrings* main_strings = ReadText( &main_text, fonegin );
    fclose( fonegin );

    /*printf("main: %c\n", main_strings[0].string_begin[0]);
    for( int i = 0; i < main_text.text_size; i++)
        printf( "(%c)", main_text.buffer[i] );
    printf("(%d)", main_text.number_of_strings);
    for( int i = 0; i < main_text.number_of_strings; i++)
    {
        for( int j = 0; j < 10 ; j++ )
            printf("(%p)\n", main_strings[i].string_begin );
    }*/

    BubbleSort( main_strings, main_text.number_of_strings, sizeof( DataStrings ), &ReversedComparetorStrings );

    FILE* sort_fonegin = fopen( "sort_text.txt", "w" );
    WriteText( main_strings, main_text.number_of_strings, sort_fonegin );
    fclose( sort_fonegin );

    return 0;
}

