#include "Files_coding.h"
using namespace std;

void create_huffman_tree(multimap<int,char>&character_inverted, size_t text_size, list<char>&text, string reference_book_file, string output_file)
{
    shared_ptr<Huffman_node> left_temp, right_temp, top;

    priority_queue<shared_ptr<Huffman_node>, vector<shared_ptr<Huffman_node>>, Compare  > minimal_node;
    
    for (auto const &pair: character_inverted)
    {
        minimal_node.push(make_shared<Huffman_node>(pair.second,pair.first));
    }
    
    while (minimal_node.size() != 1)
    {
        left_temp = minimal_node.top();
        minimal_node.pop();
        right_temp = minimal_node.top();
        minimal_node.pop();
        
        top = make_shared<Huffman_node>('$', left_temp->frequency + right_temp->frequency);
        top->left = left_temp;
        top->right = right_temp;
        minimal_node.push(top);
    }
    open_output_file(reference_book_file, minimal_node.top(), text_size, text, output_file);
}

void open_output_file(string reference_book_file, shared_ptr<Huffman_node> root, size_t text_size, list<char>&text, string output_file)
{
    ofstream file;
    file.open(reference_book_file);
    write_code(file, root, "", text, text_size);
    file.close();
    
    load_reference_book(text, text_size,reference_book_file,output_file);
}

void write_code(ofstream &file, shared_ptr<Huffman_node> root, string code, list<char>&text, size_t text_size)
{
    if (root)
    {
        if(root->character != '$')
        {
            file << root->character << " : " << code << "\n";
        }
        write_code(file, root->left, code + "0", text, text_size);
        write_code(file, root->right, code + "1", text, text_size);
    }
}

void load_reference_book(list<char>&text, size_t text_size, string reference_book_file, string output_file)
{
    map<char,string>reference_book_temp;
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
            reference_book_temp[loaded_character] = loaded_code;
            if (file.eof()) break;
        }
    }
    file.close();
    encode_text(text, text_size, reference_book_temp, output_file);
}

void encode_text(list<char>&text, size_t text_size, map<char,string>&reference_book_temp, string output_file)
{
    char character_to_compare = text.front();
    text.pop_front();
    int counter=0;
    size_t text_size_temp = text_size - 1;
    
    ofstream file;
    file.open(output_file);
    
    while(counter<text_size)
    {
        file << reference_book_temp.find(character_to_compare)->second;
        counter++;
        character_to_compare = text.front();
        text_size_temp--;
        if(text_size_temp != 0)
        {
            text.pop_front(); 
        }
    }
    file.close();
}
