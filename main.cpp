//  Temat: "Kodowanie Huffmanna"
//  main.cpp
//  Created by Karolina Bryś on 22/11/2020.
/** @file */

#include "Arguments.h"
using namespace std;

int main(int argc, const char * argv[])
{
    load_files(argc,argv);
    return 0;
}


//cd Library/Developer/Xcode/DerivedData/HuffmanSTL-dukgdhiunukkavgrpkfsahzifyxy/Build/Products/Debug ./HuffmanSTL -k KOMPRESJA -i tekst.txt -s slownik.txt -o zakodowany.txt
//./HuffmanSTL -d DEKOMPRESJA -i zakodowany.txt -s slownik.txt -o dekodowany.txt
