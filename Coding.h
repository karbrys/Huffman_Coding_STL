//  Temat: "Kodowanie Huffmanna"
//  Coding_func.h
//  Created by Karolina Bryś on 22/11/2020.
/** @file */

#ifndef Coding_h
#define Coding_h

#include <fstream>
#include <map>
#include <list>
#include <queue>
using namespace std;

/// Stuktura opisująca węzeł drzewa Huffmana
struct Huffman_node
{
    char character;
    int frequency;
    
    shared_ptr<Huffman_node> left, right;
    
    /// Konstruktor węzła
    /// @param character_temp Zmienna przechowujaca znak.
    /// @param frequency_temp Zmienna przechowująca liczbę wystąpień danego znaku.
    Huffman_node(char character_temp, int frequency_temp)
    {
        left = right = NULL;
        this->character = character_temp;
        this->frequency = frequency_temp;
    }
};

/// Struktura potrzebna do sprawdzenia warunku ustawienia elemntów od najmniejszej do największej liczby wystapień w kolejce.
struct Compare
{
    bool operator () (shared_ptr<Huffman_node> left, shared_ptr<Huffman_node> right)
    {
        return (left->frequency > right->frequency);
    }
};

/// Funkcja tworząca na podstawie wcześniej utworzonej mapy ze słownikiem i kolejki (zawierającej uporządkowane elementy mapy ze słownikiem) drzewo Huffmana
/// @param character_inverted Struktura mapy zawierająca odwórcony i uporządkowany w kolejności rosnącej liczby wystąpień danego znaku słownik
/// @param text_size Zmienna przechowująca rozmiar wczytanego tekstu z pliku wejściowego
/// @param text Struktura listy przechowująca wczytanie tekst z pliku wejściowego.
/// @param reference_book_file Zmienna zawierająca nazwę pliku słownika.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void create_huffman_tree(multimap<int,char>&character_inverted, size_t text_size, list<char>&text, string reference_book_file, string output_file);

/// Funkcja zapisująca (na podstawie przechodzenia przez odpowiednie gałęzie drzewa Huffmana) znak z odpowiadającym mu kluczem do pliku słownika.
/// @param file Zmienna przechowująca dane odnośnie otwartego w funkcji "open_output_file" pliku słownika
/// @param root Inteligentny wskaźnik zawierający korzeń drzewa Huffmana.
/// @param code Zmienna przechowująca klucz do odpowiedniego znaku.
/// @param text Struktura listy przechowująca wczytanie tekst z pliku wejściowego.
/// @param text_size Zmienna przechowująca rozmiar wczytanego tekstu z pliku wejściowego
void write_code(ofstream& file, shared_ptr<Huffman_node> root, string code, list<char>& text, size_t text_size);

#endif /* Coding_h */
