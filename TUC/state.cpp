#include "state.h"

void ValueState::setState(int in, bool state){
	this->In = in;
	this->state = state;
}

void ValueState::printState(std::ostream& stream){
	stream << this->In << ":" << this->state << " ";
}

void ValueState::printFinalState(std::ostream& stream){
	stream << this->In << ":" << this->state << std::endl;
}

int ValueState::getIn(){
	return this->In;
}

bool ValueState::getState(){
	return this->state;
}
