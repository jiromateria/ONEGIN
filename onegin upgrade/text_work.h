#ifndef TEXT_WORK_H_INCLUDED
#define TEXT_WORK_H_INCLUDED

#include "onegin.h"

DataStrings* ReadText( DataText* main_text , FILE* reading_file );
void MakeBuffer( DataText* main_text, FILE* reading_file);
int GetSizeOfFile( FILE* fonegin );
void InputToBuffer( DataText* main_text , FILE* fonegin );
DataStrings* GetStrings( DataText* main_text );
void CountStrings( DataText* main_text );
void InitializeDataString( DataStrings* main_strings, int number_of_strings );
void FillStrings( DataText* main_text , DataStrings* main_strings );
void WriteText( DataStrings* const main_strings , int number_of_strings, FILE* writing_file);

#endif // TEXT_WORK_H_INCLUDED
