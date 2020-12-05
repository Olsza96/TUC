/**
	@file
*/
#pragma once

#include "logicFunctions.h"
#include "printFunctions.h"

/** Klasa reprezentuj�ca plik zewn�trzny. */
class FileManager {
public:
	/** Metoda odczytuj�ca plik z uk�adem bramek logicznych.
		@param circuit obiekt przechowuj�cy dane o odczytanym uk�adzie.
		@param fileName zmienna tekstowa przechowuj�ca nazw� pliku
		@return zwraca warto�ci od -1 do -4 w zale�no�ci od wykrytego b��du, a w przypadku poprawnej realizacji warto�� 1 */
	int loadGates(gatesContainer &circuit,const std::string &fileName);

	/** Metoda odczytuj�ca plik ze stanami pocz�tkowymi.
		@param inputs obiekt przechowuj�cy dane o odczytanych stanach logicznych
		@param fileName zmienna tekstowa przechowuj�ca nazw� pliku
		@return zwraca warto�ci -5 oraz -6 w zale�no�ci od wykrytego b��du, a w przyadku poprawnej realizacji warto�� 1 */
	int loadStates(std::vector<ValueState> &inputs, const std::string &fileName);

	/** Metoda zapisuj�ca wynik dzia�ania do pliku.
		@param initialInput obiekt zawieraj�cy stany pierwotne
		@param finalInput obiekt zawieraj�cy stany wynikowe
		@param fileName zmienna tekstowa przechowuj�ca nazw� pliku */
	void save(std::vector<ValueState> initialInput, std::vector<ValueState> finalInput, const std::string &fileName);
};
