//  Temat: "Kodowanie Huffmanna"
//  Reference_book_func.h
//  Created by Karolina Bryś on 22/11/2020.
/** @file */

#ifndef Reference_book_h
#define Reference_book_h

#include "Files_coding.h"
#include "Files_reference_book.h"
#include "Coding.h"
using namespace std;

/// Funkcja tworząca (na podstawie wcześniej wczytanego tekstu z pliku wejściowego) słownik zapissywany w strkturze mapy
/// @param loaded_text Zmienna przechowująca wczytany tekst.
/// @param input_file Zmienna zawierająca nazwę pliku wejściowego.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void create_reference_book(string loaded_text, string input_file, string output_file);

/// Funckja odwracająca wczesniej utworzoną mapę zawierającą uporządkowany słownik.
/// @param character Zmienna zawierajaca strukturę mapy z nieodwróconym słownikiem.
multimap<int,char> sort_reference_book(map<char,int>&character);

#endif /* Reference_book_h */
