//  Temat: "Kodowanie Huffmanna"
//  Files_coding.h
//  Created by Karolina Bryś on 22/11/2020.
/** @file */

#ifndef Files_coding_h
#define Files_coding_h

#include "Coding.h"
using namespace std;

/// Funkcja otwierajaca plik słownika, do którego zostanie zapisany klucz, utworzony na podstawie przechodzenia przez drzewo Huffmana
/// @param reference_book_file Zmienna zawierająca nazwę pliku słownika.
/// @param root Inteligentny wskaźnik zawierający korzeń drzewa Huffmana.
/// @param text_size Zmienna przechowująca rozmiar wczytanego tekstu z pliku wejściowego
/// @param text Struktura listy przechowująca wczytanie tekst z pliku wejściowego.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void open_output_file(string reference_book_file, shared_ptr<Huffman_node> root, size_t text_size, list<char>&text, string output_file);

/// Funkcja otwierajaca plik słownika, z którego zostanie odczytany słownik do struktury mapy i na podstawie którego zostanie zakodowany test z pliku wejściowego.
/// @param text Struktura listy przechowująca wczytanie tekst z pliku wejściowego.
/// @param text_size Zmienna przechowująca rozmiar wczytanego tekstu z pliku wejściowego
/// @param reference_book_file Zmienna zawierająca nazwę pliku słownika.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void load_reference_book(list<char>&text, size_t text_size, string reference_book_file, string output_file);

/// Funkcja kodująca tekst wczytany z pliku wejściowego i zapisująca zakodowany tekst do pliku wyjściowego.
/// @param text Struktura listy przechowująca wczytanie tekst z pliku wejściowego.
/// @param text_size Zmienna przechowująca rozmiar wczytanego tekstu z pliku wejściowego
/// @param reference_book_temp Struktura mapy przechowująca wczytany słownik.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void encode_text(list<char>&text, size_t text_size, map<char,string>&reference_book_temp, string output_file);


#endif /* Files_coding_h */
