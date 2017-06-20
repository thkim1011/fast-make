# Fast Make 

## Quick Note
As of right now, fastmake will look for files in the src directory so you can't run things like `fastmake src/*.cpp -o program`. 

## Intro
GNU Make is pretty nice, but writing makefile is a pain, so use Fast Make to generate a Makefile with one command. 

To use, you simply need to run fastmake on the terminal. The default options assumes that you are using the normal directory structure

    project-directory
    ├── bin
    │   └── program
    ├── build
    │   ├── main.o
    │   ├── src1.o
    │   └── src2.o
    ├── include
    │   ├── src1.h
    │   └── src2.h
    ├── src
    │   ├── main.cpp
    │   ├── src1.cpp
    │   └── src2.cpp
    └── README.md

These default options can be changed using command line arguments. 

## Usage
To run fastmake, run 

    fastmake *.cpp -o program-name

To use other options, run

    fastmake main.cpp src1.cpp src2.cpp ... -s path/to/src/ -i path/to/include/ -b path/to/build -B path/to/bin -o program-name

For example, to use the current directory for everything, run

    fastmake main.cpp -s . -i . -b . -B . -o hello-world

Note that fastmake looks for each source file with respect to the source directory. 

## Upcoming Features
I'm probably going to have to implement other stuff so I can get unit testing to work. 

## This doesn't work for my complex and large C++ project!

You probably shouldn't be using this for a large complex project. Consider CMake instead. 

