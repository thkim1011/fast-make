SRC_DIR = /src
INCLUDE_DIR = /include
BUILD_DIR = /build
BIN_DIR = /bin

all: $(BUILD_DIR)/*.o
	g++ $(BUILD_DIR)/*.o

main.o: main.cpp
	g++ -c main.cpp
