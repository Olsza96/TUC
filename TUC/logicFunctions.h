/**
	@file
*/
#pragma once

#include "gateAND.h"
#include "gateNAND.h"
#include "gateNOT.h"
#include "gateNOR.h"
#include "gateOR.h"
#include "gateXNOR.h"
#include "gateXOR.h"
#include "inOut.h"

/** Kontener na wyrazy */
typedef std::vector<std::shared_ptr<std::string>> wordChain;
/** Kontener na bramki logiczne */
typedef std::vector<std::shared_ptr<Gate>> gatesContainer;

/** Funkcja odczytuj¹ca parametry podane podczas uruchamiania programu.
	@param argc liczba parametrów z lini poleceñ
	@param argv tablica s³ów z lini poleceñ
	@param fileNames obiekt przechowuj¹cy nazwy plików wydzielone z argv
	@param first okreœla miejsce przechowywania nazwy pliku zawieraj¹cego uk³ad bramek w obiekcie fileNames
	@param second okreœla miejsce przechowywania nazwy pliku zawieraj¹cego stany wejœciowe w obiekcie fileNames
	@param third okreœla miejsce przechowywania, w obiekcie fileNames, nazwy jak¹ ma zostaæ nazwany plik wynikowy
	@return zwraca wartoœæ -7 w przypadku wykrycia b³edu, a gdy funckja zosta³a zrealizowana poprawnie wartoœæ 1 */
int readParams(int argc, char* argv[], wordChain& fileNames, int& firstFile, int& secondFile, int& thirdFile);

/** Funkcja realizuj¹ca symulacje bramek logicznych.
	@param circuit obiekt przechowuj¹cy dane o uk³adzie bramek
	@param copyInput obiekt przechowuj¹cy dane o stanach pierwotnych
	@param finalInput obiekt, do którego zostaje zapisane wyniki stanów wyjœæ */
void realize(gatesContainer& circuit, std::vector<ValueState> copyInput, std::vector<ValueState>& finalInput);
