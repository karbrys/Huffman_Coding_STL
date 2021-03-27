#ifndef Files_decoding_h
#define Files_decoding_h

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

void load_encoded_reference_book(string input_file, string reference_book_file, string output_file);

void load_encoded_text(string input_file, map<string,char>&reference_book, string output_file);

void decode(string loaded_text, map<string,char>&reference_book, string output_file);

#endif /* Files_decoding_h */
