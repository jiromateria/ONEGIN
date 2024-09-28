#include "text_work.h"

DataStrings* ReadText( DataText* main_text , FILE* reading_file)  // 1
{
    assert( main_text != NULL );
    assert( reading_file != NULL );

    MakeBuffer( main_text, reading_file );
    return GetStrings( main_text );
}


void MakeBuffer( DataText* main_text, FILE* reading_file )   // 2
{
    assert( main_text != NULL );
    assert( reading_file != NULL );

    main_text -> text_size = GetSizeOfFile( reading_file );
    InputToBuffer( main_text , reading_file );

    return;
}


int GetSizeOfFile( FILE* reading_file )  // 3
{
    assert( reading_file != NULL );

    int text_size = 0;

    fseek( reading_file, 0 , SEEK_END );
    text_size = ftell( reading_file );
    fseek( reading_file, 0 , SEEK_SET );

    return text_size;
}


void InputToBuffer( DataText* main_text, FILE* reading_file )   // 4
{
    assert( main_text != NULL );
    assert( reading_file != NULL );

    main_text -> buffer = ( char* )calloc( (main_text -> text_size) + 1, sizeof(char) );
    fread( main_text -> buffer, sizeof(char), main_text -> text_size, reading_file );

    return;
}


DataStrings* GetStrings( DataText* main_text) // would never use realloc pls  5
{
    assert( main_text != NULL );;

    CountStrings( main_text );

    DataStrings* main_strings = (DataStrings*)calloc( main_text -> number_of_strings , sizeof(DataStrings) );
    InitializeDataString( main_strings, main_text -> number_of_strings );
    main_strings[0].string_begin = main_text -> buffer;

    FillStrings( main_text, main_strings );

    return main_strings;
}


void CountStrings ( DataText* main_text )   // 6
{
    assert( main_text != NULL );

    int number_strings = 1;

    for( int i = 0; i < ( main_text -> text_size ); i++ )
    {
        if( (main_text -> buffer)[i] == '\n' )
        {
            number_strings ++;
        }
    }
    //printf("%d\n", number_strings);
    main_text -> number_of_strings = number_strings;

    return;
}


void InitializeDataString( DataStrings* main_strings , int number_of_strings )    // 7
{
    assert( main_strings != NULL );

    for(int i = 0; i < number_of_strings; i++)
    {
        //printf("%d\n", i);
        main_strings[i].string_len = 0;
        main_strings[i].string_begin = 0;
    }
    return;
}


void FillStrings( DataText* main_text , DataStrings* main_strings )    // 8
{
    assert( main_text != NULL );
    assert( main_strings != NULL );

    int st_num = 1;

    for( int i = 0; i < (main_text -> text_size); i++ )
    {
        main_strings[st_num - 1].string_len ++;
        if( (main_text -> buffer)[i] == '\n' )
        {
            main_strings[st_num].string_begin = &( (main_text -> buffer)[i + 1] );

            st_num++;
        }
    }
    return;
}


void WriteText( DataStrings* const main_strings , int number_of_strings, FILE* writing_file )  // in the end
{
    assert( main_strings != NULL );
    assert( writing_file != NULL );

    for( int i = 0; i < number_of_strings; i++ )
    {
        for( int j = 0; j < (main_strings[i].string_len); j++ )
        {
            fprintf( writing_file, "%c", main_strings[i].string_begin[j] );
        }
    }
    return;
}
