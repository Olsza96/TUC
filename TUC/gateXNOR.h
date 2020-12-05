/**
	@file
*/
#pragma once

#include "gate.h"

/** �a�cuch znakowy okre�laj�cy nazw� bramki XNOR. */
#define gate_XNOR "XNOR"

/** Klasa pochodna, dziedzicz�ca po klasie abstrakcyjnej Gate. Reprezentuje bramk� logiczn� XNOR. */
class GateXNOR :public Gate {
public:
	/** Metoda wirtualna inicjalizuj�ca warto�ci obiektu.
	@param name nazwa bramki logicznej
	@param out numer wyj�cia stanu logicznego
	@param in1 pierwszy numer wej�cia stanu logicznego
	@param in2 drugi numer wej�cia stanu logicznego */
	virtual void setInOutPuts(std::string name, int in1, int out, int in2);

	/** Metoda wirtualna symuluj�ca dzia�anie bramki logicznej XNOR.
		@param input kontener zawieraj�cy wej�ciowe warto�ci stan�w logicznych */
	virtual bool operate(bool stateOfInput1, bool stateOfInput2);
};