# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lstdc++ -lm

# Source files
SOURCES = player.cpp catan.cpp demo.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

TEST_DIR = Testing

# Test source files
TEST_SOURCES = $(TEST_DIR)/TestCounter.cpp $(TEST_DIR)/TestBoard.cpp

# Test object files
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)


# Executable
EXECUTABLE = demo
TEST_EXECUTABLE = test

# Default rule
all: $(EXECUTABLE)

# Rule to link object files to create executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the test executable
$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	@echo "Compiling test executable..."
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ 
	@echo "Test executable created."

# Separate rule for the 'test' target
test: $(TEST_EXECUTABLE)

# Clean rule to remove object files and executables
clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE) $(TEST_EXECUTABLE)

.PHONY: all clean
