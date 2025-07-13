# Makefile for Student Database Program

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = student_database
SOURCE = student_database.c

# Default target
all: $(TARGET)

# Compile the program
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run with command line arguments
run-with-args: $(TARGET)
	./$(TARGET) demo_mode student_count=5 debug=on

# Clean compiled files
clean:
	rm -f $(TARGET) students.dat

# Clean only executable
clean-exe:
	rm -f $(TARGET)

# Clean only data file
clean-data:
	rm -f students.dat

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Compile the program"
	@echo "  run          - Compile and run the program"
	@echo "  run-with-args- Run with sample command line arguments"
	@echo "  clean        - Remove executable and data file"
	@echo "  clean-exe    - Remove only executable"
	@echo "  clean-data   - Remove only data file"
	@echo "  help         - Show this help message"

.PHONY: all run run-with-args clean clean-exe clean-data help

