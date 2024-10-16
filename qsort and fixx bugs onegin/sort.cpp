#include "sort.h"

void BubbleSort( void* data_elements, int number_of_elements , size_t size_of_element, bool (* Comparator) ( const void*, const void* ) ) // works correct
{
    assert( (char*)data_elements != NULL );
    assert( Comparator != NULL );

    int end_sort = 1;
    int i = 0;

    while( end_sort )
    {
        end_sort = 0;

        for( i = 0; i < ( number_of_elements - 1 ) ; i++ )
        {
            //printf("%d \n", i);
            if( Comparator( (char*)data_elements + i*size_of_element, (char*)data_elements + (i + 1)*size_of_element ) )
                {
                    end_sort++;
                    //printf("swap\n");
                    //printf("%d\n", i);
                    SwapElements( (char*)data_elements + i*size_of_element, (char*)data_elements + (i + 1)*size_of_element, size_of_element );
                }
        }
    }
}

/*void QuickSort( void* data_elements, int number_of_elements , size_t size_of_element, bool (* Comparator) ( const void*, const void* ) )
{
    assert( (char*)data_elements != NULL );
    assert( Comparator != NULL );

    int i = 0;  // left from middle
    int j = number_of_elements - 1;  // right from middle
    if( i >= j )
        return;
    int p = number_of_elements / 2 ;  // middle
    char* i_str = (char*)data_elements + i*size_of_element;
    char* j_str = (char*)data_elements + j*size_of_element;
    char* p_str = (char*)data_elements + p*size_of_element;
    printf("%d ", p);
    while( i < j )
    {
        if( j == p && j - i > 1)
        {
            SwapElements( (char*)data_elements + p*size_of_element, (char*)data_elements + (p - 1)*size_of_element, size_of_element );
            p--;
        }
        else if( i == p && j - i > 1)
        {
            SwapElements( (char*)data_elements + p*size_of_element, (char*)data_elements + (p + 1)*size_of_element, size_of_element );
            p++;
        }

        i_str = (char*)data_elements + i*size_of_element;
        j_str = (char*)data_elements + j*size_of_element;
        p_str = (char*)data_elements + p*size_of_element;
        printf("%d \n", p);
        if( ReversedComparetorStrings( i_str, p_str ) )
        {
            if ( ReversedComparetorStrings( p_str, j_str ) )
            {
                if( j - i == 1)
                {
                    if( i == p )
                        p++;
                    else
                        p--;
                }
                SwapElements( i_str, j_str, size_of_element );
                i++;

            }
            j--;
        }
        else
        {
            i++;
        }
    }
    if( number_of_elements != 1)
    {
        if( p )
            QuickSort( data_elements , p , size_of_element, Comparator );
        if( number_of_elements - p )
            QuickSort( (char*)data_elements + p*size_of_element, number_of_elements - p , size_of_element, Comparator );
    }
}*/


bool DirectComparetorStrings( const void* element_1, const void* element_2 ) // works correct    2
{
    assert( element_1 != NULL );
    assert( element_2 != NULL );

    const DataStrings string_1 = *(const DataStrings*)element_1;
    const DataStrings string_2 = *(const DataStrings*)element_2;

    return strcmp( string_1.string_begin , string_2.string_begin ) < 0 ;
}


bool ReversedComparetorStrings( const void* element_1, const void* element_2 )     // works correct 2
{

    assert( element_1 != NULL );
    assert( element_2 != NULL );

    const DataStrings string_1 = *(const DataStrings*)element_1;
    const DataStrings string_2 = *(const DataStrings*)element_2;

    int i = string_1.string_len - 1;
    int j = string_2.string_len - 1;

    int low_1 = 'W';
    int low_2 = 'L';

    while( i && j )
    {
        while( !isalpha( string_1.string_begin[i] ) && i)
        {
            i--;
        }

        while( !isalpha( string_2.string_begin[j] ) && j)
        {
            j--;
        }

        if( !( i && j) )
        {
            break;
        }

        low_1 = tolower( string_1.string_begin[i] );
        low_2 = tolower( string_2.string_begin[j] );

        if( low_1 != low_2 )
        {
            return low_1 < low_2;
        }

        else
        {
            i--;
            j--;
        }
    }

    return i < j;
}


void SwapElements( void* element_1 , void* element_2, size_t size_of_element ) // works correct    3
{
    assert( element_1 != NULL );
    assert( element_2 != NULL );

    char element_swapper = 'W';

    for( unsigned int i = 0; i < size_of_element; i++)
    {
        element_swapper = *( (char*)element_1 + i );
                          *( (char*)element_1 + i ) = *( (char*)element_2 + i );
                                                      *( (char*)element_2 + i ) = element_swapper;
    }
    return;
}

void QuickSort( void* data_elements, int number_of_elements , size_t size_of_element, bool (* Comparator) ( const void*, const void* ) )
{
    int i = 0;
    int j = number_of_elements - 1;
    int p = ( number_of_elements) / 2;

    if( i == j ) return;

    do
    {
        printf("a");
        while( ReversedComparetorStrings( (char*)data_elements + i*size_of_element, (char*)data_elements + p*size_of_element) )
        {
            printf("d");
            i++;
        }

        while( ReversedComparetorStrings( (char*)data_elements + j*size_of_element, (char*)data_elements + p*size_of_element) )
        {
            printf("d");
            j--;
        }
        printf("d");
        if( i <= j )
        {
            SwapElements( (char*)data_elements + i*size_of_element, (char*)data_elements + j*size_of_element, size_of_element );
            i++;
            j--;
        }

    } while( i <= j );

    if( j > 0 )
        QuickSort( data_elements , j , size_of_element, Comparator );
    if( i < number_of_elements )
        QuickSort( (char*)data_elements + i*size_of_element, number_of_elements - i , size_of_element, Comparator );
}


