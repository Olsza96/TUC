/**
	@file
*/
#pragma once
#include <iostream>

/** Klasa reprezentuj¹ca pojedynczy stan logiczny.
	@param In numer stanu
	@param state wartoœæ stanu */
class ValueState {
	int In;
	bool state;
public:
	/** Metoda ustawiaj¹ca wartoœci pól obiektu.
		@param in numer stanu
		@param state wartoœæ stanu */
	void setState(int in, bool state);

	/** Metoda wypisuj¹ca pocz¹tkowy stan logiczny na podane wyjœcie.
		@param stream strumieñ okreœlaj¹cy wyjœcie */
	void printState(std::ostream &stream);

	/** Metoda wypisuj¹ca wynikowy stan logiczny na podane wyjœcie.
		@param stream strumieñ okreœlaj¹cy wyjœcie */
	void printFinalState(std::ostream& stream);

	/** Metoda zwracaj¹ca numer stanu logicznego.
		@return zwraca numer stanu */
	int getIn();

	/** Metoda zwracaj¹ca wartoœæ stanu logicznego.
		@return zwraca wartoœæ stanu */
	bool getState();
};
