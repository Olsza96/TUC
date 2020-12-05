/**
	@file
*/
#pragma once

#include "gate.h"

/** Klasa pochodna, dziedzicz¹ca po klasie abstrakcyjnej Gate. Reprezentuje stany pierwotne oraz stan wynikowy. */
class InOut :public Gate {
public:
	/** Metoda wirtualna inicjalizuj¹ca wartoœci obiektu.
	@param name nazwa wejœcia lub wyjœcia logicznego
	@param out numer wyjœcia stanu logicznego
	@param in1 pierwszy numer wejœcia stanu logicznego
	@param in2 drugi numer wejœcia stanu logicznego */
	virtual void setInOutPuts(std::string name, int in1, int out, int in2);

	/** Metoda wirtualna symuluj¹ca dzia³anie.
		@param input kontener zawieraj¹cy wejœciowe wartoœci stanów logicznych */
	virtual bool operate(bool stateOfInput1, bool stateOfInput2);
};
