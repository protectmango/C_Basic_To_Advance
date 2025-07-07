CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = student_database
OBJS = main.o student_database.o

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Build main.o
main.o: main.c student_database.h
	$(CC) $(CFLAGS) -c main.c

# Build student_database.o
student_database.o: student_database.c student_database.h
	$(CC) $(CFLAGS) -c student_database.c

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET) *.dat

# Clean only data files
clean-data:
	rm -f *.dat

# Install (copy to /usr/local/bin)
install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all         - Build the program (default)"
	@echo "  clean       - Remove all build files and data files"
	@echo "  clean-data  - Remove only data files (*.dat)"
	@echo "  run         - Build and run the program"
	@echo "  debug       - Build with debug information"
	@echo "  install     - Install to /usr/local/bin"
	@echo "  uninstall   - Remove from /usr/local/bin"
	@echo "  help        - Show this help message"

.PHONY: all clean clean-data run debug install uninstall help
