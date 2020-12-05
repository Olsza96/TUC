#include "fileManager.h"

int main(int argc, char* argv[]) {

	FileManager file;

	gatesContainer circuit;
	wordChain fileNames;

	std::vector<ValueState> input, finalInput;

	int first = 0, second = 0, third = 0;

	if (!printErrorGates(readParams(argc, argv, fileNames, first, second, third))) {
		return 0;
	}

	if (!printErrorGates(file.loadGates(circuit, *fileNames[first]))) {
		return 0;
	}

	if (!printErrorGates(file.loadStates(input, *fileNames[second]))) {
		return 0;
	}

	realize(circuit, input, finalInput);

	print(circuit, input, finalInput);

	file.save(input, finalInput, *fileNames[third]);

	return 0;
}
