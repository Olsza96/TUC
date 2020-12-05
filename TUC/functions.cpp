#include "logicFunctions.h"
#include "printFunctions.h"

bool printErrorGates(int bug){

	if (bug == -1) {
		std::cout << "Brak pliku dotyczacego schematu bramek o podanej nazwie\n";
		return false;
	}
	else if (bug == -2) {
		std::cout << "Podano nieodpowiedni format wejscia schematu bramek(1 linia pliku)\n";
		return false;
	}
	else if (bug == -3) {
		std::cout << "Podano nieodpowiedni format wyjscia schematu bramek(2 linia pliku)\n";
		return false;
	}
	else if (bug == -4) {
		std::cout << "Podano nieodpowiedni format bramek\n";
		return false;
	}
	else if (bug == -5) {
		std::cout << "Brak pliku dotyczacego wartosci stanow wejsc\n";
		return false;
	}
	else if (bug == -6) {
		std::cout << "Podano nieodpowiedni format stanow wejsc\n";
		return false;
	}
	else if (bug == -7) {
		printHelp();
		return false;
	}

	return true;
}

void print(gatesContainer copyCircuit, std::vector<ValueState> copyInput, std::vector<ValueState> copyFinalInput){

	for (int i = 0; i < (int)copyCircuit.size(); i++) {
		copyCircuit[i]->printGate(std::cout);
	}

	std::cout << "-------------------------------------\n";

	for (int i = 0; i < (int)copyInput.size(); i = i + 2) {
		copyInput[i].printState(std::cout);
		copyInput[i + 1].printState(std::cout);
		std::cout << std::endl;
	}

	std::cout << "-------------------------------------\n";

	int i = 0, k = 0;
	while (i < (int)copyFinalInput.size() and k < (int)copyInput.size()) {

		std::cout << "IN: ";

		copyInput[k].printState(std::cout);
		copyInput[k + 1].printState(std::cout);

		std::cout << "OUT: ";
		copyFinalInput[i].printFinalState(std::cout);

		i++;
		k = k + 2;
	}
}

void realize(gatesContainer& circuit, std::vector<ValueState> copyInput, std::vector<ValueState> &finalInput){
	std::vector<ValueState> tmpInput;

	int circuitSize = (int)circuit.size(), inputSize = (int)copyInput.size();
	for (int i = 0; i < inputSize; i = i + 2) {

		tmpInput.push_back(copyInput[i]);
		tmpInput.push_back(copyInput[i + 1]);

		for (int ii = 1; ii < circuitSize; ii++) {
			bool state;
			int value1 = 0, value2 = 0;

			while (true) {

				if(circuit[ii]->getIn1() == tmpInput[value1].getIn()){

					if (circuit[ii]->getIn2() == tmpInput[value2].getIn()) {
						state = circuit[ii]->operate(tmpInput[value1].getState(), tmpInput[value2].getState());
						break;
					}

					value2++;
					continue;
				}

				value1++;
			}

			ValueState s;
			s.setState(circuit[ii]->getOut(), state);
			tmpInput.push_back(s);
		}

		for (int k = 2; k < (int)tmpInput.size(); k++) {

			if (circuit[0]->getOut() == tmpInput[k].getIn() or circuit[0]->getIn1() == tmpInput[k].getIn() or circuit[0]->getIn2() == tmpInput[k].getIn())
				finalInput.push_back(tmpInput[k]);
		}
		tmpInput.clear();
	}
}

void printHelp() {
	std::cout << "------------------------------------\nPOMOC\n------------------------------------\n";
	std::cout << "Dostepne przelaczniki:\n";
	std::cout << "\n-u plik wejsciowy z ukladem bramek\n(nalezy podac nazwe pliku z opisanym ukladem bramek logicznych)\n";
	std::cout << "\n-i plik wejsciowy ze stanami wejsciowymi\n(nalezy podac nazwe pliku z opisanymi stanami wejsc)\n";
	std::cout << "\n-o plik wyjsciowy z stanami wyjsc\n(nalezy podac nazwe w jakiej ma zostac nazwany plik wynikowy)\n";
	std::cout << "\n-h wyswietla niniejszy opis\n";
}

int readParams(int argc, char* argv[], wordChain& fileNames, int &firstFile, int &secondFile, int &thirdFile){
	
	if (argc != 7 or !strcmp(argv[1], "-h")) {
		return -7;
	}

	int iterator = 1, flag = 0;
	while (iterator < 7) {

		if (!strcmp(argv[iterator], "-u")) {
			std::shared_ptr<std::string> p = std::make_shared<std::string>(argv[iterator + 1]);
			fileNames.push_back(p);
			firstFile = flag;
			flag++;
		}
		else if (!strcmp(argv[iterator], "-i")) {
			std::shared_ptr<std::string> p = std::make_shared<std::string>(argv[iterator + 1]);
			fileNames.push_back(p);
			secondFile = flag;
			flag++;
		}
		else if (!strcmp(argv[iterator], "-o")) {
			std::shared_ptr<std::string> p = std::make_shared<std::string>(argv[iterator + 1]);
			fileNames.push_back(p);
			thirdFile = flag;
			flag++;
		}

		if (flag == 3)
			break;

		iterator++;
	}

	if (flag != 3) {
		return -7;
	}

	return 1;
}
