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

/** Funkcja odczytuj�ca parametry podane podczas uruchamiania programu.
	@param argc liczba parametr�w z lini polece�
	@param argv tablica s��w z lini polece�
	@param fileNames obiekt przechowuj�cy nazwy plik�w wydzielone z argv
	@param first okre�la miejsce przechowywania nazwy pliku zawieraj�cego uk�ad bramek w obiekcie fileNames
	@param second okre�la miejsce przechowywania nazwy pliku zawieraj�cego stany wej�ciowe w obiekcie fileNames
	@param third okre�la miejsce przechowywania, w obiekcie fileNames, nazwy jak� ma zosta� nazwany plik wynikowy
	@return zwraca warto�� -7 w przypadku wykrycia b�edu, a gdy funckja zosta�a zrealizowana poprawnie warto�� 1 */
int readParams(int argc, char* argv[], wordChain& fileNames, int& firstFile, int& secondFile, int& thirdFile);

/** Funkcja realizuj�ca symulacje bramek logicznych.
	@param circuit obiekt przechowuj�cy dane o uk�adzie bramek
	@param copyInput obiekt przechowuj�cy dane o stanach pierwotnych
	@param finalInput obiekt, do kt�rego zostaje zapisane wyniki stan�w wyj�� */
void realize(gatesContainer& circuit, std::vector<ValueState> copyInput, std::vector<ValueState>& finalInput);
