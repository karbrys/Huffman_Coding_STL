//  Temat: "Kodowanie Huffmanna"
//  Files_reference_book.h
//  Created by Karolina Bryś on 22/11/2020.
/** @file */

#ifndef Files_reference_book_h
#define Files_reference_book_h

#include <string>
using namespace std;

/// Funkcja wczytująca z pliku wejściowego tekst, na podstawie którego zostanie utworzone drzewo Huffmana i słownik.
/// @param input_file Zmienna zawierająca nazwę pliku wejściowego.
/// @param reference_book_file Zmienna zawierająca nazwę pliku słownika.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void load_text_file(string input_file, string reference_book_file, string output_file);

#endif /* Files_reference_book_h */
