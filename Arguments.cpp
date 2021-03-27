//  Temat: "Kodowanie Huffmanna"
//  Arguments.cpp
//  Created by Karolina Bryś on 22/11/2020.
/** @file */

#include "Arguments.h"
using namespace std;

void load_files(int argc, const char *argv[])
{
    int mode;
    string input_file = "", reference_book_file = "", output_file = "";
    tie(mode,input_file,reference_book_file,output_file) = arguments(argc,argv);
    
    if(mode == 0)
    {
        return;
    }
    else
    {
        if(mode == 2)
        {
            load_text_file(input_file,reference_book_file,output_file);
        }
        else
        {
            load_encoded_reference_book(input_file,reference_book_file,output_file);
        }
    }
}

tuple<int,string,string,string> arguments(int argc, const char *argv[])
{
    string input_file = "", reference_book_file = "", output_file = "", d = "", k = "";
    int mode = 1;
    if(argc<9)
    {
        cout << "Program wymaga podania nastepujacych przelacznikow w dowolnej kolejnosci: " << endl;
        cout << "TRYB KOMPRESJI: -k KOMPRESJA -i PLIK_WEJSCIOWY -s PLIK_SLOWNIK -o PLIK_WYJSCIOWY" << endl;
        cout << "TRYB DEKOMPRESJI: -d DEKOMPRESJA -i PLIK_WEJSCIOWY -s PLIK_SLOWNIK -o PLIK_WYJSCIOWY" << endl;
        return make_tuple(0,"\0","\0","\0");
    }
    else
    {
        for (int i = 0; i < argc; i++)
        {
            cout<< argv[i] << endl;
            if (strcmp(argv[i], "-i") == 0 && i + 1 < argc)
            {
                input_file = argv[i + 1];
                i++;
            }
            if (strcmp(argv[i], "-s") == 0 && i + 1 < argc)
            {
                reference_book_file = argv[i + 1];
                i++;
            }
            if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
            {
                output_file = argv[i + 1];
                i++;
            }
            if (strcmp(argv[i], "-k") == 0 && i + 1 < argc)
            {
                k = argv[i + 1];
                mode++;
                i++;
            }
            if (strcmp(argv[i], "-d") == 0 && i + 1 < argc)
            {
                d = argv[i + 1];
                i++;
            }
            if (strcmp(argv[i], "-h") == 0 && i + 1 < argc)
            {
                cout << "Program wymaga podania nastepujacych przelacznikow w dowolnej kolejnosci: " << endl;
                cout << "TRYB KOMPRESJI: -k KOMPRESJA -i PLIK_WEJSCIOWY -s PLIK_SLOWNIK -o PLIK_WYJSCIOWY" << endl;
                cout << "TRYB DEKOMPRESJI: -d DEKOMPRESJA -i PLIK_WEJSCIOWY -s PLIK_SLOWNIK -o PLIK_WYJSCIOWY" << endl;
                return make_tuple(0,"\0","\0","\0");
            }
        }
    }
    return make_tuple(mode,input_file,reference_book_file,output_file);
}
