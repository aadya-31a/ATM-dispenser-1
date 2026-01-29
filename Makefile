# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Directories
SRC_DIR = src
BUILD_DIR = build

# Target
TARGET = atm

# Source files
SRC = $(SRC_DIR)/atm.cpp

# Object files
OBJ = $(BUILD_DIR)/atm.o

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Compile
$(BUILD_DIR)/atm.o: $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets
.PHONY: all clean
