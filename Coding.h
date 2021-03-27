#ifndef Coding_h
#define Coding_h

#include <fstream>
#include <map>
#include <list>
#include <queue>
using namespace std;


struct Huffman_node
{
    char character;
    int frequency;
    
    shared_ptr<Huffman_node> left, right;
    
    
    Huffman_node(char character_temp, int frequency_temp)
    {
        left = right = NULL;
        this->character = character_temp;
        this->frequency = frequency_temp;
    }
};


struct Compare
{
    bool operator () (shared_ptr<Huffman_node> left, shared_ptr<Huffman_node> right)
    {
        return (left->frequency > right->frequency);
    }
};


void create_huffman_tree(multimap<int,char>&character_inverted, size_t text_size, list<char>&text, string reference_book_file, string output_file);


void write_code(ofstream& file, shared_ptr<Huffman_node> root, string code, list<char>& text, size_t text_size);

#endif /* Coding_h */
