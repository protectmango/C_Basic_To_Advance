# Makefile for Student Management System

# Define the C compiler to use
CC = gcc

# Define compiler flags
# -Wall: Enables all common warnings
# -Wextra: Enables extra warnings
# -g: Includes debugging information (useful for gdb)
# -std=c11: Compiles according to the C11 standard
CFLAGS = -Wall -Wextra -g -std=c11

# Define the name of the executable
TARGET = sms

# Define the source files
SRCS = main.c student.c linked_list.c file_handler.c

# Define the object files (compiled .c files)
# $(patsubst %.c,%.o,$(SRCS)) takes all .c files and changes their extension to .o
OBJS = $(patsubst %.c,%.o,$(SRCS))

# Default target: builds the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to compile each .c file into a .o object file
# $<: The first prerequisite (the .c file)
# $@: The target (the .o file)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
