#include <fstream>
#include <string>
#include <vector>
using std::ofstream;
using std::string;
using std::vector;

void formatDirectory(string& dir);
void addComment(string str);
void addVariable(ofstream& makefile, string varName, string varValue);
void addLink(ofstream& makefile, vector<string> srcFileNames, string out);
void addCompile(ofstream& makefile, string srcFileName, string srcDir);