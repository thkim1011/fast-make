#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

#include "make.h"

#define MAJOR_VERSION 1
#define MINOR_VERSION 0

// IO
using std::cout;
using std::setw;
using std::endl;
using std::ifstream;
using std::ofstream;

// String
using std::strcmp;
using std::string;

// Vector
using std::vector;

int main(int argc, char **argv)
{

    // Source File Names
    vector<string> srcFileNames;

    // Directory Structure
    string srcDir = "src/";
    string includeDir = "include/";
    string buildDir = "build/";
    string binDir = "bin/";

    // Output Name
    string out = "a.out";

    if (argc == 1)
    {
        cout << "Fast Make v" << MAJOR_VERSION << "." << MINOR_VERSION << endl;

        cout << "\nUsage: fastmake [OPTION]... [FILE]..." << endl;

        cout << setw(5) << "-o"
             << " or" << setw(10) << "--output\n";
        cout << setw(5) << "-s"
             << " or" << setw(10) << "--source\n";
        cout << setw(5) << "-i"
             << " or" << setw(10) << "--include\n";

        return 0;
    }

    bool pass = false;

    for (int i = 1; i < argc; i++)
    {
        if (pass) {
            pass = false;
            continue;
        }

        if (argv[i][0] == '-')
        {
            if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0)
            {
                out = argv[i + 1];
                pass = true;
            }

            if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--source") == 0)
            {
                srcDir = argv[i + 1];
                pass = true;
            }

            if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--include") == 0)
            {
                includeDir = argv[i + 1];
                pass = true;
            }

            if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--build") == 0)
            {
                buildDir = argv[i + 1];
                pass = true;
            }

            if (strcmp(argv[i], "-B") == 0 || strcmp(argv[i], "--bin") == 0)
            {
                binDir = argv[i + 1];
                pass = true;
            }
        }

        else
        {
            srcFileNames.push_back(argv[i]);
        }
    }

	// Reformat Directories
	formatDirectory(srcDir);
	formatDirectory(includeDir);
	formatDirectory(buildDir);
	formatDirectory(binDir);

    // Set up variables
    ofstream makefile ("./Makefile");

    addVariable(makefile, "SRC_DIR", srcDir);
    addVariable(makefile, "INCLUDE_DIR", includeDir);
    addVariable(makefile, "BUILD_DIR", buildDir);
    addVariable(makefile, "BIN_DIR", binDir);

    makefile << endl;

	addLink(makefile, srcFileNames, out);
    
	makefile << endl;

	for (auto i = srcFileNames.begin(); i != srcFileNames.end(); i++) {
		addCompile(makefile, *i, srcDir);
	}
	
    return 0;
}
