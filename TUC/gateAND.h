/**
	@file
*/
#pragma once

#include "gate.h"

/** £añcuch znakowy okreœlaj¹cy nazwê bramki AND. */
#define gate_AND "AND"

/** Klasa pochodna, dziedzicz¹ca po klasie abstrakcyjnej Gate. Reprezentuje bramkê logiczn¹ AND. */
class GateAND :public Gate {
public:
	/** Metoda wirtualna inicjalizuj¹ca wartoœci obiektu.
		@param name nazwa bramki logicznej
		@param out numer wyjœcia stanu logicznego
		@param in1 pierwszy numer wejœcia stanu logicznego
		@param in2 drugi numer wejœcia stanu logicznego */
	virtual void setInOutPuts(std::string name, int in1, int out, int in2);

	/** Metoda wirtualna symuluj¹ca dzia³anie bramki logicznej AND.
		@param input kontener zawieraj¹cy wejœciowe wartoœci stanów logicznych */
	virtual bool operate(bool stateOfInput1, bool stateOfInput2);
};
