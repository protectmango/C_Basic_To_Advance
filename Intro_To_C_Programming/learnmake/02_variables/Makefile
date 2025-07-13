# LEVEL 2: Makefile with Variables and Clean Target
# Variables make Makefiles more maintainable and flexible

# Variables (can be overridden from command line)
CC = gcc                    # Compiler
CFLAGS = -Wall -Wextra -g   # Compiler flags
TARGET = math               # Output executable name
SOURCE = math.c             # Source file

# Default target (first target in file)
all: $(TARGET)

# Main compilation rule
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

# Clean target - removes generated files
clean:
	rm -f $(TARGET)

# Run target - compile and execute
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  clean   - Remove generated files"
	@echo "  run     - Build and run the program"
	@echo "  help    - Show this help"

# Phony targets (targets that don't create files)
.PHONY: all clean run help

# To use:
# make          - builds the program
# make clean    - removes executable
# make run      - builds and runs
# make CC=clang - uses clang instead of gcc

