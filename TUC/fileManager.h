/**
	@file
*/
#pragma once

#include "logicFunctions.h"
#include "printFunctions.h"

/** Klasa reprezentuj¹ca plik zewnêtrzny. */
class FileManager {
public:
	/** Metoda odczytuj¹ca plik z uk³adem bramek logicznych.
		@param circuit obiekt przechowuj¹cy dane o odczytanym uk³adzie.
		@param fileName zmienna tekstowa przechowuj¹ca nazwê pliku
		@return zwraca wartoœci od -1 do -4 w zale¿noœci od wykrytego b³êdu, a w przypadku poprawnej realizacji wartoœæ 1 */
	int loadGates(gatesContainer &circuit,const std::string &fileName);

	/** Metoda odczytuj¹ca plik ze stanami pocz¹tkowymi.
		@param inputs obiekt przechowuj¹cy dane o odczytanych stanach logicznych
		@param fileName zmienna tekstowa przechowuj¹ca nazwê pliku
		@return zwraca wartoœci -5 oraz -6 w zale¿noœci od wykrytego b³êdu, a w przyadku poprawnej realizacji wartoœæ 1 */
	int loadStates(std::vector<ValueState> &inputs, const std::string &fileName);

	/** Metoda zapisuj¹ca wynik dzia³ania do pliku.
		@param initialInput obiekt zawieraj¹cy stany pierwotne
		@param finalInput obiekt zawieraj¹cy stany wynikowe
		@param fileName zmienna tekstowa przechowuj¹ca nazwê pliku */
	void save(std::vector<ValueState> initialInput, std::vector<ValueState> finalInput, const std::string &fileName);
};
