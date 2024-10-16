#include "text_work.h"
#include "sort.h"

int main()
{
    DataText main_text = {};

    FILE* fonegin = fopen( "test.txt" , "rb" );
    if( !fonegin )
    {
        printf("text.txt for reading doesn't exist\n");
        return -1;
    }

    DataStrings* main_strings = ReadText( &main_text, fonegin );  // Input buffer from text
    if( main_strings == NULL )
        {
            printf("ERROR of working calloc: &main_strings == NULL\n");
            free( main_strings );
            free( main_text.buffer );
            fclose( fonegin );
            return -1;
        }

    fclose( fonegin );
    BubbleSort( main_strings, main_text.number_of_strings, sizeof( DataStrings ), &ReversedComparetorStrings );    // Sort strings

    FILE* sort_fonegin = fopen( "test_wr.txt", "wb" );

    printf("Sorted text was written to sort_text.txt\n");
    WriteText( main_strings, main_text.number_of_strings, sort_fonegin );   // Write revers sorted text

    //BubbleSort( main_strings, main_text.number_of_strings, sizeof( DataStrings ), &DirectComparetorStrings );
    //WriteText( main_strings, main_text.number_of_strings, sort_fonegin );  // Write direct sorted text

    fclose( sort_fonegin );

    free( main_strings );
    free( main_text.buffer );

    return 0;
}

