CPP=g++
CPP_FLAGS=-std=c++20 -O3 -Wall -Wextra -Wpedantic -Wconversion -Wshadow
CPP_INCLUDES=-I/home/linuxbrew/.linuxbrew/include/
CPP_DEFINITIONS=-DFMT_HEADER_ONLY

BUILD_DIR=../../build
BIN=day01

all: $(BIN)

$(BIN): $(BIN).cpp
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) $(CPP_DEFINITIONS) -o $(BIN) $(BIN).cpp
	mkdir -p $(BUILD_DIR)
	mv $(BIN) $(BUILD_DIR)/$(BIN)

run: $(BUILD_DIR)/$(BIN)
	$(BUILD_DIR)/$(BIN) $(args)

clean:
	rm $(BUILD_DIR)/$(BIN)
