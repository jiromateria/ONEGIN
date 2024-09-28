#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "onegin.h"

void BubbleSort( void* data_elements, int number_of_elements, size_t size_of_element, bool (* Comparator) ( const void*, const void* ) ); // 1
bool DirectComparetorStrings( const void* element_1, const void* element_2 );  // 2
bool ReversedComparetorStrings( const void* element_1, const void* element_2 );  // 2
void SwapElements( void* element_1 , void* element_2, size_t size_of_element );    // 3

#endif // SORT_H_INCLUDED
