#include <fstream>
#include <string>
using std::ofstream;
using std::string;

void addComment(string str);
void addVariable(ofstream& makefile, string varName, string varValue);