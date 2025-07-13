# LEVEL 3: Makefile for Multiple Source Files
# This demonstrates object files, dependencies, and incremental compilation

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = calculator
SOURCES = main.c calculator.c utils.c
OBJECTS = main.o calculator.o utils.o
HEADERS = calculator.h utils.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	@echo "Linking object files to create executable..."
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "Build complete: $(TARGET)"

# Compile source files to object files
# Each .o file depends on its corresponding .c file
main.o: main.c calculator.h utils.h
	@echo "Compiling main.c..."
	$(CC) $(CFLAGS) -c main.c

calculator.o: calculator.c calculator.h
	@echo "Compiling calculator.c..."
	$(CC) $(CFLAGS) -c calculator.c

utils.o: utils.c utils.h
	@echo "Compiling utils.c..."
	$(CC) $(CFLAGS) -c utils.c

# Alternative: Generic rule for all .o files
# %.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	@echo "Cleaning up..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete."

# Clean only object files
clean-obj:
	rm -f $(OBJECTS)

# Run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# Show file dependencies
deps:
	@echo "File Dependencies:"
	@echo "$(TARGET) depends on: $(OBJECTS)"
	@echo "main.o depends on: main.c calculator.h utils.h"
	@echo "calculator.o depends on: calculator.c calculator.h"
	@echo "utils.o depends on: utils.c utils.h"

# Install (copy to /usr/local/bin)
install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

# Help
help:
	@echo "Available targets:"
	@echo "  all       - Build the program (default)"
	@echo "  clean     - Remove all generated files"
	@echo "  clean-obj - Remove only object files"
	@echo "  run       - Build and run the program"
	@echo "  deps      - Show file dependencies"
	@echo "  install   - Install to /usr/local/bin"
	@echo "  help      - Show this help"
	@echo ""
	@echo "Key concepts demonstrated:"
	@echo "  - Object files for incremental compilation"
	@echo "  - Header dependencies"
	@echo "  - Multiple source files"
	@echo "  - Custom clean targets"

.PHONY: all clean clean-obj run deps install help

# Benefits of this approach:
# 1. Only modified files are recompiled
# 2. Faster builds for large projects
# 3. Clear separation of compilation and linking steps
# 4. Easy to add new source files

