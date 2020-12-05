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

/** Klasa abstrakcyjna opisuj�ca bramk� logiczn�, jest dziedziczona przez klasy reprezentuj�ce konkretne bramki logiczne.
	@param Name pole teskstowe przechowuj�ce nazw� bramki
	@param Out numer wyj�cia stanu logicznego
	@param In1 pierwszy numer wej�cia stanu logicznego
	@param In2 drugi numer wej�cia stanu logicznego */
class Gate {
protected:
	std::string Name;
	int Out = 0;
	int In1 = 0;
	int In2 = 0;
public:
	/** Czysto wirtualna metoda inicjalizuj�ca warto�ci obiektu.
		@param name nazwa bramki logicznej
		@param out numer wyj�cia stanu logicznego
		@param in1 pierwszy numer wej�cia stanu logicznego
		@param in2 drugi numer wej�cia stanu logicznego */
	virtual void setInOutPuts(std::string name, int in1, int out, int in2) = 0;

	/** Metoda wypisuj�ca bramk� logiczn�.
		@param stream strumie� okre�laj�cy wyj�cie */
	void printGate(std::ostream& stream) { stream << this->Name << " " << this->In1 << " " << this->In2 << " " << this->Out << std::endl; }

	/** Metoda czysto wirtualna symuluj�ca dzia�anie bramki logicznej.
		@param input kontener zawieraj�cy wej�ciowe warto�ci stan�w logicznych */
	virtual bool operate(bool stateOfInput1, bool stateOfInput2) = 0;

	/** Metoda zwracaj�ca numer pierwszego wej�cia bramki.
		@return zwraca numer pierwszego wej�cia */
	int getIn1() {return In1;}

	/** Metoda zwracaj�ca numer drugiego wej�cia bramki. 
		@return zwraca numer drugiego wej�cia */
	int getIn2() { return In2; }

	/** Metoda zwracaj�ca numer wyj�cia bramki.
		@return zwraca numer wyj�cia */
	int getOut() { return Out; }
};
