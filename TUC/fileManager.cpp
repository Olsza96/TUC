#include "fileManager.h"

int FileManager::loadGates(gatesContainer &circuit, const std::string &fileName){
	std::fstream file(fileName, std::ios::in);

	if (!file) {
		return -1;
	}

	std::string lineText, category, inputText, outputText;
	char separator;
	int nameOfInput1, nameOfInput2, nameOfOutput;

	std::shared_ptr<InOut> ingate = std::make_shared<InOut>();

	if (!(file >> inputText >> separator >> nameOfInput1 >> nameOfInput2)) {
		return -2;
	}

	if (!(file >> outputText >> nameOfOutput)) {
		return -3;
	}

	ingate->setInOutPuts(inputText, nameOfInput1, nameOfOutput, nameOfInput2);
	circuit.push_back(ingate);

	while (std::getline(file, lineText)) {
		if (lineText.empty())
			continue;

		std::stringstream ss(lineText);
		if (!(ss >> category >> nameOfInput1 >> nameOfInput2 >> nameOfOutput)) {
			return -4;
		}

		if (category == gate_AND) {
	
			std::shared_ptr<GateAND> G = std::make_shared<GateAND>();
			G->setInOutPuts(gate_AND, nameOfInput1, nameOfOutput, nameOfInput2);
			circuit.push_back(G);
		}
		else if (category == gate_NAND) {
			
			std::shared_ptr<GateNAND> G = std::make_shared<GateNAND>();
			G->setInOutPuts(gate_NAND, nameOfInput1, nameOfOutput, nameOfInput2);
			circuit.push_back(G);
		}
		else if (category == gate_NOT) {
			
			std::shared_ptr<GateNOT> G = std::make_shared<GateNOT>();
			G->setInOutPuts(gate_NOT, nameOfInput1, nameOfOutput, nameOfInput2);
			circuit.push_back(G);
		}
		else if (category == gate_NOR) {
			
			std::shared_ptr<GateNOR> G = std::make_shared<GateNOR>();
			G->setInOutPuts(gate_NOR, nameOfInput1, nameOfOutput, nameOfInput2);
			circuit.push_back(G);
		}
		else if (category == gate_OR) {
			
			std::shared_ptr<GateOR> G = std::make_shared<GateOR>();
			G->setInOutPuts(gate_OR, nameOfInput1, nameOfOutput, nameOfInput2);
			circuit.push_back(G);
		}
		else if (category == gate_XNOR) {
			
			std::shared_ptr<GateXNOR> G = std::make_shared<GateXNOR>();
			G->setInOutPuts(gate_XNOR, nameOfInput1, nameOfOutput, nameOfInput2);
			circuit.push_back(G);
		}
		else if (category == gate_XOR) {
			
			std::shared_ptr<GateXOR> G = std::make_shared<GateXOR>();
			G->setInOutPuts(gate_XOR, nameOfInput1, nameOfOutput, nameOfInput2);
			circuit.push_back(G);
		}
		else {
			std::cout << "Nieznana bramka logiczna: " << category << std::endl;
			continue;
		}
	}

	file.close();

	return 1;
}

int FileManager::loadStates(std::vector<ValueState> &inputs, const std::string& fileName) {
	std::fstream file(fileName, std::ios::in);

	if (!file) {
		return -5;
	}

	int nameOfInput1, nameOfInput2;
	bool stateOfInput1, stateOfInput2;
	char separator;
	std::string lineText;
	ValueState input;

	while (std::getline(file, lineText)) {
		if (lineText.empty()) {
			continue;
		}

		std::stringstream ss(lineText);

		if (!(ss >> nameOfInput1 >> separator >> stateOfInput1 >> nameOfInput2 >> separator >> stateOfInput2)) {
			return -6;
		}

		input.setState(nameOfInput1, stateOfInput1);
		inputs.push_back(input);

		input.setState(nameOfInput2, stateOfInput2);
		inputs.push_back(input);

	}

	file.close();

	return 1;
}

void FileManager::save(std::vector<ValueState> initialInput, std::vector<ValueState> finalInput, const std::string& fileName){
	std::fstream file(fileName, std::ios::out);

	size_t i = 0, k = 0;
	while (i < finalInput.size() and k < initialInput.size()) {
		file << "IN: ";

		initialInput[k].printState(file);
		initialInput[k + 1].printState(file);

		file << "OUT: ";
		finalInput[i].printFinalState(file);

		i++;
		k = k + 2;
	}

	file.close();
}
