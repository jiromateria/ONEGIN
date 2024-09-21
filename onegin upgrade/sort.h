#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "onegin.h"

void BubbleSort( void* data_elements, int number_of_elements, size_t size_of_element, int (* comparator) ( const void*, const void* ) );
bool DirectComparetorStrings( const char* string_1, const char* string_2 );
void SwapElements( void* element_1 , void* element_2, size_t size_of_element );
int ReversedComparetorStrings( const void* element_1, const void* element_2 );

#endif // SORT_H_INCLUDED
