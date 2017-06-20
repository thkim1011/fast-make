SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

all: $(BUILD_DIR)/main.o $(BUILD_DIR)/make.o
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/make.o -o $(BIN_DIR)/fastmake


# main.cpp
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/make.h
	g++ -I $(INCLUDE_DIR) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

# make.cpp
$(BUILD_DIR)/make.o: $(SRC_DIR)/make.cpp $(INCLUDE_DIR)/make.h
	g++ -I $(INCLUDE_DIR) -c $(SRC_DIR)/make.cpp -o $(BUILD_DIR)/make.o
