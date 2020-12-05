/**
	@file
*/
#pragma once

#include "logicFunctions.h"

/** Funkcja wypisuje na ekran informacje o b³êdzie w zale¿noœæi od przyjêtej wartoœci.
	@param bug przyjmuje wartoœæ o b³êdzie
	@return zwraca false w momencie znalezienia dopasowania wartoœci do b³êdu w przeciwnym wypadku zwraca true */
bool printErrorGates(int bug);

/** Funkcja wypisuje na ekran zawartoœæ odczytanych plików oraz zawartoœæ utworzonego pliku wynikowego. 
	@param copyCircuit obiekt zawiera dane o odczytanym uk³adzie bramek
	@param copyInput obiekt zazwiera dane o odczytanych stanach pocz¹tkowych
	@param copyFinalInput obiekt zawiera dane o stanach wynikowych */
void print(gatesContainer copyCircuit, std::vector<ValueState> copyInput, std::vector<ValueState> copyFinalInput);

/** Funkcja wypisuje na ekran instrukcje obs³ugi przy b³êdnie uruchomionym programie */
void printHelp();
