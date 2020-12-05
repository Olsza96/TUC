/**
	@file
*/
#pragma once

#include "logicFunctions.h"

/** Funkcja wypisuje na ekran informacje o b��dzie w zale�no��i od przyj�tej warto�ci.
	@param bug przyjmuje warto�� o b��dzie
	@return zwraca false w momencie znalezienia dopasowania warto�ci do b��du w przeciwnym wypadku zwraca true */
bool printErrorGates(int bug);

/** Funkcja wypisuje na ekran zawarto�� odczytanych plik�w oraz zawarto�� utworzonego pliku wynikowego. 
	@param copyCircuit obiekt zawiera dane o odczytanym uk�adzie bramek
	@param copyInput obiekt zazwiera dane o odczytanych stanach pocz�tkowych
	@param copyFinalInput obiekt zawiera dane o stanach wynikowych */
void print(gatesContainer copyCircuit, std::vector<ValueState> copyInput, std::vector<ValueState> copyFinalInput);

/** Funkcja wypisuje na ekran instrukcje obs�ugi przy b��dnie uruchomionym programie */
void printHelp();
