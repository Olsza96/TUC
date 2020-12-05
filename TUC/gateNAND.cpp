#include "gateNAND.h"

void GateNAND::setInOutPuts(std::string name, int in1, int out, int in2){
	this->In1 = in1;
	this->In2 = in2;
	this->Out = out;
	this->Name = name;
}

bool GateNAND::operate(bool stateOfInput1, bool stateOfInput2) {

	return !(stateOfInput1 && stateOfInput2);
}