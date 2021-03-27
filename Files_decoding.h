//  Temat: "Kodowanie Huffmanna"
//  Files_decoding.h
//  Created by Karolina Bryś on 22/11/2020.
/** @file */

#ifndef Files_decoding_h
#define Files_decoding_h

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

/// Funkcja wczytująca słownik z pliku słownika. Funkcja zapisuje wczytany słownik do struktury mapy, która w kolejnych krokach będzie przeszukiwana w celu odnalezienia odpowiedniego klucza i zdekodowania zakodowanego testu wejściowego.
/// @param input_file Zmienna zawierająca nazwę pliku wejściowego.
/// @param reference_book_file Zmienna zawierająca nazwę pliku słownika.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void load_encoded_reference_book(string input_file, string reference_book_file, string output_file);

/// Funckja wczytująca z pliku wejściowego zakodowany tekst wejściowy, który zostanie zdekodowany.
/// @param input_file Zmienna zawierająca nazwę pliku wejściowego.
/// @param reference_book Struktura mapy przechowująca wczytany słownik.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void load_encoded_text(string input_file, map<string,char>&reference_book, string output_file);

/// Funkcja dekoduje zakodowany test wejściowy poprzez przeszukiwanie mapy i porównywanie zawartych w niej kluczy. Fukcja dodatkowow zapisuje zdekodowany test do pliku wyjściowego.
/// @param loaded_text Zmienna przechowująca wczytany zakodowany tekst.
/// @param reference_book Struktura mapy przechowująca wczytany słownik.
/// @param output_file Zmienna zawierająca nazwę pliku wyjściowego.
void decode(string loaded_text, map<string,char>&reference_book, string output_file);

#endif /* Files_decoding_h */
