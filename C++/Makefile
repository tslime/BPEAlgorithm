CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I./inc
TARGET = bpe_algorithm
SRCDIR = .
INCDIR = ./inc
SOURCES = BPEAlgorithm.cpp

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Clean build artifacts
clean:
	rm -f $(TARGET) *.o

# Run the program
run: $(TARGET)
	./$(TARGET)

# Install dependencies (placeholder for future use)
install:
	@echo "No external dependencies required for C++ implementation"

.PHONY: all clean run install