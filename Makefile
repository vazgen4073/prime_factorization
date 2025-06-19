# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Wextra -g -gdwarf-4 -std=c++17

 

# Directories
INC_DIR = inc
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests
OBJ_DIR = $(BUILD_DIR)/obj

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Test Files 
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_FILES))

# Executable
TEST_EXEC = $(BUILD_DIR)/runTests

# Include directories
INCLUDES = -I$(INC_DIR)

# Libraries for tests (add linker search path)
LIBS = -L//usr/src/googletest/googletest/lib/ -lgtest -lgtest_main -pthread

# Default target
all: $(TEST_EXEC)

# Create directories
$(OBJ_DIR)  $(BUILD_DIR):
	mkdir -p $@ 

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compile test files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Link test executable
$(TEST_EXEC): $(OBJ_FILES) $(TEST_OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

# Run test
test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean test


























# # Compiler and flags
# CXX = clang++
# CXXFLAGS = -Wall -Wextra -g   -gdwarf-4 ...

# # Directories
# INC_DIR = inc
# SRC_DIR = src
# BUILD_DIR = build
# TEST_DIR = tests
# OBJ_DIR = $(BUILD_DIR)/obj

# # Source files
# SRC_FIlES = $(wildcard $(SRC_DIR)/*.cpp)
# OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SRC_FIlES))

# # Test Files 
# TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
# TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(TEST_FILES))

# # Excecutable
# TEST_EXEC = $(BUILD_DIR)/runTests

# # Include directories
# INCLUDES = -I$(INC_DIR)

# # Libraries for tests
# LIBS = -lgtest -lgtest_main -pthread

# # Default target
# all: $(TEST_EXEC)

# # Create directories
# $(OBJ_DIR)  $(BUILD_DIR):
# 	mkdir -p $@ 

# # Compie source files
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES)  -c $< -o $@

# # Compie test files
# $(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES)  -c $< -o $@

# # Link test executable
# $(TEST_EXEC): $(OBJ_FILES) $(TEST_OBJ_FILES) | $(BUILD_DIR)
# 	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

# # Run test
# test: $(TEST_EXEC)
# 	./$(TEST_EXEC)

# clean:
# 	rm -rf $(BUILD_DIR)

# .PHONY: all clean test
