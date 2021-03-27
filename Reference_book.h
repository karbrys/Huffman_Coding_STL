#ifndef Reference_book_h
#define Reference_book_h

#include "Files_coding.h"
#include "Files_reference_book.h"
#include "Coding.h"
using namespace std;

void create_reference_book(string loaded_text, string input_file, string output_file);

multimap<int,char> sort_reference_book(map<char,int>&character);

#endif /* Reference_book_h */
