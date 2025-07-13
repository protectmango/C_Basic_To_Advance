# Makefile for Advanced Linked List Demonstration Program

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O0
TARGET = linked_list_demo
SOURCE = advanced_linked_list_demo.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	@echo "🔧 Compiling $(SOURCE)..."
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "✅ Compilation successful!"
	@echo "📦 Executable created: $(TARGET)"
	@echo "🚀 Run with: ./$(TARGET)"

# Clean build artifacts
clean:
	@echo "🧹 Cleaning up..."
	rm -f $(TARGET)
	@echo "✅ Cleanup complete!"

# Run the program
run: $(TARGET)
	@echo "🚀 Running $(TARGET)..."
	./$(TARGET)

# Debug build with additional flags
debug: CFLAGS += -DDEBUG -fsanitize=address -fsanitize=undefined
debug: $(TARGET)
	@echo "🐛 Debug build complete with sanitizers enabled"

# Memory check with valgrind (if available)
memcheck: $(TARGET)
	@echo "🔍 Running memory check..."
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Help target
help:
	@echo "📚 Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug flags and sanitizers"
	@echo "  memcheck - Run with valgrind memory checking"
	@echo "  help     - Show this help message"

.PHONY: all clean run debug memcheck help

