#include "gateNOT.h"

void GateNOT::setInOutPuts(std::string name, int in1, int out, int in2) {
	this->In1 = in1;
	this->Out = out;
	this->Name = name;
}

bool GateNOT::operate(bool stateOfInput1, bool stateOfInput2 = 0) {

	return !stateOfInput1;
}
