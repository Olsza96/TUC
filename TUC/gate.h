/**
	@file
*/
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>

#include "state.h"

/** Klasa abstrakcyjna opisuj¹ca bramkê logiczn¹, jest dziedziczona przez klasy reprezentuj¹ce konkretne bramki logiczne.
	@param Name pole teskstowe przechowuj¹ce nazwê bramki
	@param Out numer wyjœcia stanu logicznego
	@param In1 pierwszy numer wejœcia stanu logicznego
	@param In2 drugi numer wejœcia stanu logicznego */
class Gate {
protected:
	std::string Name;
	int Out = 0;
	int In1 = 0;
	int In2 = 0;
public:
	/** Czysto wirtualna metoda inicjalizuj¹ca wartoœci obiektu.
		@param name nazwa bramki logicznej
		@param out numer wyjœcia stanu logicznego
		@param in1 pierwszy numer wejœcia stanu logicznego
		@param in2 drugi numer wejœcia stanu logicznego */
	virtual void setInOutPuts(std::string name, int in1, int out, int in2) = 0;

	/** Metoda wypisuj¹ca bramkê logiczn¹.
		@param stream strumieñ okreœlaj¹cy wyjœcie */
	void printGate(std::ostream& stream) { stream << this->Name << " " << this->In1 << " " << this->In2 << " " << this->Out << std::endl; }

	/** Metoda czysto wirtualna symuluj¹ca dzia³anie bramki logicznej.
		@param input kontener zawieraj¹cy wejœciowe wartoœci stanów logicznych */
	virtual bool operate(bool stateOfInput1, bool stateOfInput2) = 0;

	/** Metoda zwracaj¹ca numer pierwszego wejœcia bramki.
		@return zwraca numer pierwszego wejœcia */
	int getIn1() {return In1;}

	/** Metoda zwracaj¹ca numer drugiego wejœcia bramki. 
		@return zwraca numer drugiego wejœcia */
	int getIn2() { return In2; }

	/** Metoda zwracaj¹ca numer wyjœcia bramki.
		@return zwraca numer wyjœcia */
	int getOut() { return Out; }
};
