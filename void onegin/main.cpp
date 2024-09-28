#include "text_work.h"
#include "sort.h"

int main()
{
    DataText main_text = {};

    FILE* fonegin = fopen( "text.txt" , "r" );
    DataStrings* main_strings = ReadText( &main_text, fonegin );    // Input buffer from text
    fclose( fonegin );

    BubbleSort( main_strings, main_text.number_of_strings, sizeof( DataStrings ), &ReversedComparetorStrings );    // Sort strings

    FILE* sort_fonegin = fopen( "sort_text.txt", "w" );
    WriteText( main_strings, main_text.number_of_strings, sort_fonegin );     // Write sort text
    fclose( sort_fonegin );

    free( main_strings );
    free( main_text.buffer );

    return 0;
}

