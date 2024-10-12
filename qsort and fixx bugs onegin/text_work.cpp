#include "text_work.h"

DataStrings* ReadText( DataText* main_text , FILE* reading_file)  // 1
{
    assert( main_text != NULL );
    assert( reading_file != NULL );

    if( MakeBuffer( main_text, reading_file ) )
    {
        return NULL;
    }

    return GetStrings( main_text );
}


bool MakeBuffer( DataText* main_text, FILE* reading_file )   // 2
{
    assert( main_text != NULL );
    assert( reading_file != NULL );

    main_text -> text_size = GetSizeOfFile( reading_file );
    return InputToBuffer( main_text , reading_file );
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


bool InputToBuffer( DataText* main_text, FILE* reading_file )   // 4
{
    assert( main_text != NULL );
    assert( reading_file != NULL );

    main_text -> buffer = ( char* )calloc( (main_text -> text_size) + 1, sizeof(char) );
    if( main_text -> buffer == NULL )
    {
        return 1;
    }

    fread( main_text -> buffer, sizeof(char), main_text -> text_size, reading_file );

    return 0;
}


DataStrings* GetStrings( DataText* main_text) // would never use realloc pls  5
{
    assert( main_text != NULL );

    CountStrings( main_text );

    DataStrings* main_strings = (DataStrings*)calloc( main_text -> number_of_strings , sizeof(DataStrings) );
    if( main_strings == NULL )
        return NULL;

    InitializeDataString( main_strings, main_text -> number_of_strings );

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

    int st_num = 0;
    main_strings[st_num++].string_begin = main_text -> buffer;

    for( int i = 0; i < (main_text -> text_size); i++ )
    {
        if( (main_text -> buffer)[i] == '\r' )
        {
            main_strings[st_num++].string_begin = &( (main_text -> buffer)[i + 2] );
            (main_text -> buffer)[i++] = '\0';
            continue;
        }
        main_strings[st_num - 1].string_len ++;
    }
    return;
}


void WriteText( DataStrings* const main_strings , int number_of_strings, FILE* writing_file )  // in the end
{
    assert( main_strings != NULL );
    assert( writing_file != NULL );


    for( int i = 0; i < number_of_strings; i++)
    {
        fprintf( writing_file, "%s\n", main_strings[i].string_begin );
    }
    /*for( int i = 0; i < number_of_strings; i++ )
    {
        for( int j = 0; j < (main_strings[i].string_len); j++ )
        {
            fprintf( writing_file, "%c", main_strings[i].string_begin[j] );
        }
    }*/
    return;
}
//
