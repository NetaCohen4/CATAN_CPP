# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SOURCES = player.cpp catan.cpp board.cpp demo.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXECUTABLE = demo

# Default rule
all: $(EXECUTABLE)

# Rule to link object files to create executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
