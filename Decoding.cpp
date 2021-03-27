#include "Files_decoding.h"
using namespace std;

void load_encoded_reference_book(string input_file, string reference_book_file, string output_file)
{
    map<string,char>reference_book;
    char loaded_character, loaded_colon;
    string loaded_code;
    
    ifstream file;
    file.open(reference_book_file);
    if (file.good() == true)
    {
        while (file)
        {
            file >> loaded_character >> loaded_colon >> loaded_code;
            if(loaded_character == ':')
            {
                loaded_code = loaded_colon + loaded_code;
                loaded_character = ' ';
            }
            reference_book[loaded_code] = loaded_character;
            if (file.eof()) break;
        }
    }
    file.close();
    if(loaded_code.empty() == 1) return;
    load_encoded_text(input_file, reference_book, output_file);
}

void load_encoded_text(string input_file, map<string,char>&reference_book, string output_file)
{
    string loaded_text;
    ifstream file;
    file.open(input_file);
    if (file.good() == true)
    {
        while (file)
        {
            file >> loaded_text;
            if (file.eof()) break;
        }
    }
    file.close();
    if(loaded_text.empty() == 1) return;
    
    decode(loaded_text,reference_book,output_file);
}

void decode(string loaded_text, map<string,char>&reference_book, string output_file)
{
    list<char> coded_text(loaded_text.begin(), loaded_text.end());
    char character;
    size_t coded_text_size = loaded_text.length();
    
    int counter=0;
    string to_compare;
    
    ofstream file;
    file.open(output_file);
    while(counter<coded_text_size)
    {
        character = coded_text.front();
        to_compare.push_back(character);
        coded_text.pop_front();
        if(reference_book.find(to_compare) == reference_book.end())
        {
            counter++;
        }
        else
        {
            file << reference_book.find(to_compare)->second;
            to_compare.clear();
            counter++;
        }
    }
    file.close();
}
