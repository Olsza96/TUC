#include "gateXOR.h"

void GateXOR::setInOutPuts(std::string name, int In1, int Out, int In2) {
	this->In1 = In1;
	this->In2 = In2;
	this->Out = Out;
	this->Name = name;
}

bool GateXOR::operate(bool stateOfInput1, bool stateOfInput2){

	return (stateOfInput1 == stateOfInput2) ? 0 : 1;
}

