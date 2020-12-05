/**
	@file
*/
#pragma once
#include <iostream>

/** Klasa reprezentuj�ca pojedynczy stan logiczny.
	@param In numer stanu
	@param state warto�� stanu */
class ValueState {
	int In;
	bool state;
public:
	/** Metoda ustawiaj�ca warto�ci p�l obiektu.
		@param in numer stanu
		@param state warto�� stanu */
	void setState(int in, bool state);

	/** Metoda wypisuj�ca pocz�tkowy stan logiczny na podane wyj�cie.
		@param stream strumie� okre�laj�cy wyj�cie */
	void printState(std::ostream &stream);

	/** Metoda wypisuj�ca wynikowy stan logiczny na podane wyj�cie.
		@param stream strumie� okre�laj�cy wyj�cie */
	void printFinalState(std::ostream& stream);

	/** Metoda zwracaj�ca numer stanu logicznego.
		@return zwraca numer stanu */
	int getIn();

	/** Metoda zwracaj�ca warto�� stanu logicznego.
		@return zwraca warto�� stanu */
	bool getState();
};
