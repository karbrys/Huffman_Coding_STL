#ifndef Files_coding_h
#define Files_coding_h

#include "Coding.h"
using namespace std;

void open_output_file(string reference_book_file, shared_ptr<Huffman_node> root, size_t text_size, list<char>&text, string output_file);

void load_reference_book(list<char>&text, size_t text_size, string reference_book_file, string output_file);

void encode_text(list<char>&text, size_t text_size, map<char,string>&reference_book_temp, string output_file);


#endif /* Files_coding_h */
