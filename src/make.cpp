#include <fstream>
#include <string>
#include <vector>

#include "make.h"

using std::ofstream;
using std::ifstream;
using std::string;
using std::endl;
using std::vector;

void formatDirectory(string& dir) {
	if (dir[dir.length() - 1] == '/') {
		dir = dir.substr(0, dir.length() - 1);
	}
}

void addVariable(ofstream& makefile, string varName, string varValue) {
	makefile << varName << " = " << varValue << endl;
}

string removeEnd(string file) {
	size_t slash = file.find_last_of('/');
	if (slash == string::npos) {
		slash = 0;
	}
	file = file.substr(slash, file.length());
	file = file.substr(0, file.find_last_of('.'));
	return file;
}

void addLink(ofstream& makefile, vector<string> srcFileNames, string out) {
	makefile << "all:";

	for (auto i = srcFileNames.begin(); i != srcFileNames.end(); i++) {
		makefile << " $(BUILD_DIR)/" << removeEnd(*i) << ".o";
	}

	makefile << "\n\tg++ ";

	for (auto i = srcFileNames.begin(); i != srcFileNames.end(); i++) {
		makefile << "$(BUILD_DIR)/" << removeEnd(*i) << ".o ";
	}

	makefile << "-o $(BIN_DIR)/" << out << endl;
}

void addCompile(ofstream& makefile, string srcFileName, string srcDir) {
	makefile << "\n# " + srcFileName << endl;
	
	makefile << "$(BUILD_DIR)/"
		<< removeEnd(srcFileName) << ".o: $(SRC_DIR)/"
		<< srcFileName;

	ifstream srcFile(srcDir + '/' + srcFileName);

	vector<string> includeFileNames;

	while (!srcFile.eof()) {
		string line;
		getline(srcFile, line);

		if (line.size() > 8 && line.substr(0, 8) == "#include") {
			size_t first = line.find_first_of('"');
			size_t last = line.find_last_of('"');

			if (first == string::npos || last == string::npos) {
				continue;
			}
			includeFileNames.push_back(line.substr(first + 1, last - first - 1));
		}
	}

	for (auto i = includeFileNames.begin(); i != includeFileNames.end(); i++) {
		makefile << " $(INCLUDE_DIR)/" << *i;
	}
	makefile << endl;

	srcFile.close();

	makefile << "\tg++ -I $(INCLUDE_DIR) -c $(SRC_DIR)/" << srcFileName
		<< " -o $(BUILD_DIR)/" << removeEnd(srcFileName) << ".o";

	makefile << endl;
}