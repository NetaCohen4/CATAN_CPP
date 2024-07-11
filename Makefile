# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SOURCES = player.cpp catan.cpp demo.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Test source files
TEST_SOURCES = Testing/TestCounter.cpp Testing/TestPlayer.cpp #Testing/TestBoard.cpp #Testing/TestCatan # # # 
#


# Test object files
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Executable names
EXECUTABLE = demo
TEST_EXECUTABLE = test

# Default rule
all: $(EXECUTABLE)

# Rule to link object files to create main executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the test executable
$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to run the test executable
test: $(TEST_EXECUTABLE)

# Clean rule to remove object files and executables
clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE) $(TEST_EXECUTABLE)

.PHONY: all clean test
