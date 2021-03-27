#ifndef Arguments_h
#define Arguments_h

#include "Files_reference_book.h"
#include "Files_decoding.h"
using namespace std;

void load_files(int argc, const char *argv[]);
tuple<int,string,string,string> arguments(int argc, const char *argv[]);

#endif /* Arguments_h */
