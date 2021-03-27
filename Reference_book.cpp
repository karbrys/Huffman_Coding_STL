#include "Reference_book.h"
using namespace std;

void load_text_file(string input_file, string reference_book_file, string output_file)
{
    string loaded_text, loaded_text_temp;
    
    ifstream file;
    file.open(input_file);
    if (file.good() == true)
    {
        while (file)
        {
            getline(file,loaded_text_temp);
            loaded_text = loaded_text + loaded_text_temp + "";
            if (file.eof()) break;
        }
    }
    file.close();
    if(loaded_text.empty() == 1) return;
    create_reference_book(loaded_text, reference_book_file, output_file);
}

void create_reference_book(string loaded_text, string reference_book_file, string output_file)
{
    list<char> text(loaded_text.begin(), loaded_text.end());
    list<char> text_temp = text;
    size_t text_size = loaded_text.length();
    size_t text_size_temp = text_size - 1;
    
    char character_to_compare = text.front();
    text.pop_front();
    int counter;
    
    map<char,int>character;
    
    for(int i=0; i<text_size; i++)
    {
        if(character.find(character_to_compare) == character.end())
        {
            character[character_to_compare] = 1;
            character_to_compare = text.front();
            text_size_temp--;
            if(text_size_temp != 0)
            {
                text.pop_front();
            }
        }
        else
        {
            counter = character[character_to_compare];
            counter++;
            character[character_to_compare] = counter;
            character_to_compare = text.front();
            text_size_temp--;
            if(text_size_temp != 0)
            {
                text.pop_front();
            }
        }
    }
    multimap<int,char>character_inverted = sort_reference_book(character);
    create_huffman_tree(character_inverted,text_size,text_temp,reference_book_file,output_file);
}

multimap<int,char> sort_reference_book(map<char,int>&character)
{
    multimap<int,char>map_temp;
    for(auto const &pair: character)
    {
        map_temp.insert(make_pair(pair.second,pair.first));
    }
    return map_temp; 
}
