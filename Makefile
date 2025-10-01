# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

# Source files
SRCS := boggle.cpp trie.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Output binary
TARGET := boggle

# Default target
all: $(TARGET)

# Link object files to create the binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean