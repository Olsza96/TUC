/**
	@file
*/
#pragma once

#include "gate.h"

/** Klasa pochodna, dziedzicz�ca po klasie abstrakcyjnej Gate. Reprezentuje stany pierwotne oraz stan wynikowy. */
class InOut :public Gate {
public:
	/** Metoda wirtualna inicjalizuj�ca warto�ci obiektu.
	@param name nazwa wej�cia lub wyj�cia logicznego
	@param out numer wyj�cia stanu logicznego
	@param in1 pierwszy numer wej�cia stanu logicznego
	@param in2 drugi numer wej�cia stanu logicznego */
	virtual void setInOutPuts(std::string name, int in1, int out, int in2);

	/** Metoda wirtualna symuluj�ca dzia�anie.
		@param input kontener zawieraj�cy wej�ciowe warto�ci stan�w logicznych */
	virtual bool operate(bool stateOfInput1, bool stateOfInput2);
};
