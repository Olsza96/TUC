/**
	@file
*/
#pragma once

#include "logicFunctions.h"
#include "printFunctions.h"

/** Klasa reprezentująca plik zewnętrzny. */
class FileManager {
public:
	/** Metoda odczytująca plik z układem bramek logicznych.
		@param circuit obiekt przechowujący dane o odczytanym układzie.
		@param fileName zmienna tekstowa przechowująca nazwę pliku
		@return zwraca wartości od -1 do -4 w zależności od wykrytego błędu, a w przypadku poprawnej realizacji wartość 1 */
	int loadGates(gatesContainer &circuit,const std::string &fileName);

	/** Metoda odczytująca plik ze stanami początkowymi.
		@param inputs obiekt przechowujący dane o odczytanych stanach logicznych
		@param fileName zmienna tekstowa przechowująca nazwę pliku
		@return zwraca wartości -5 oraz -6 w zależności od wykrytego błędu, a w przyadku poprawnej realizacji wartość 1 */
	int loadStates(std::vector<ValueState> &inputs, const std::string &fileName);

	/** Metoda zapisująca wynik działania do pliku.
		@param initialInput obiekt zawierający stany pierwotne
		@param finalInput obiekt zawierający stany wynikowe
		@param fileName zmienna tekstowa przechowująca nazwę pliku */
	void save(std::vector<ValueState> initialInput, std::vector<ValueState> finalInput, const std::string &fileName);
};
