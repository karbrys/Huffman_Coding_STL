//  Temat: "Kodowanie Huffmanna"
//  Arguments_func.h
//  Created by Karolina Bryś on 22/11/2020.
/** @file */

#ifndef Arguments_h
#define Arguments_h

#include "Files_reference_book.h"
#include "Files_decoding.h"
using namespace std;

/// Funkcja odpowiadająca za uruchomienie programu w odpowiednim trybie: kompresji lud dekompresji.
/// @param argc Zmienna przechowująca liczbę podanych do programu argumentów.
/// @param argv Wskaźnik na wczytane poszczególne parametry.
void load_files(int argc, const char *argv[]);

/// Funkcja wczytująca parametry podawane w linii poleceń przy uruchamianiu programu w terminalu.
/// @param argc Zmienna przechowująca liczbę podanych do programu argumentów.
/// @param argv Wskaźnik na wczytane poszczególne parametry.
tuple<int,string,string,string> arguments(int argc, const char *argv[]);

#endif /* Arguments_h */
