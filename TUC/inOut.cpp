#include "inOut.h"

void InOut::setInOutPuts(std::string name, int in1, int out, int in2){
	this->In1 = in1;
	this->In2 = in2;
	this->Out = out;
	this->Name = name;
}

bool InOut::operate(bool stateOfInput1, bool stateOfInput2){
	return false;
}
