# Student Database Management System - Enhanced Makefile
# Version: v24be8g5
# Updated: 2025-01-08
# Recent Changes: Enhanced build system with comprehensive features

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
DEBUG_FLAGS = -g -DDEBUG -O0
TARGET = student_database
OBJS = main.o student_database.o
DATA_FILES = *.txt
BACKUP_DIR = backup
VERSION = v24be8g5

# Colors for output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m # No Color

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	@echo "$(BLUE)🔨 Building Student Database Management System $(VERSION)...$(NC)"
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "$(GREEN)✅ Build completed successfully!$(NC)"
	@echo "$(YELLOW)📋 Run 'make run' to start the program$(NC)"

# Build main.o
main.o: main.c student_database.h
	@echo "$(BLUE)🔧 Compiling main.c...$(NC)"
	$(CC) $(CFLAGS) -c main.c

# Build student_database.o
student_database.o: student_database.c student_database.h
	@echo "$(BLUE)🔧 Compiling student_database.c...$(NC)"
	$(CC) $(CFLAGS) -c student_database.c

# Clean build files
clean:
	@echo "$(RED)🧹 Cleaning build files...$(NC)"
	rm -f $(OBJS) $(TARGET)
	@echo "$(GREEN)✅ Build files cleaned!$(NC)"

# Clean only data files (*.txt batch files)
clean-data:
	@echo "$(RED)🗑️ Cleaning data files...$(NC)"
	@if ls $(DATA_FILES) > /dev/null 2>&1; then \
		rm -f $(DATA_FILES); \
		echo "$(GREEN)✅ Data files (.txt) cleaned!$(NC)"; \
	else \
		echo "$(YELLOW)⚠️ No .txt data files found to clean.$(NC)"; \
	fi

# Clean everything (build + data)
clean-all: clean clean-data
	@echo "$(GREEN)✅ All files cleaned!$(NC)"

# Install (copy to /usr/local/bin)
install: $(TARGET)
	@echo "$(BLUE)📦 Installing $(TARGET) to /usr/local/bin...$(NC)"
	sudo cp $(TARGET) /usr/local/bin/
	@echo "$(GREEN)✅ Installation completed!$(NC)"

# Uninstall
uninstall:
	@echo "$(RED)🗑️ Uninstalling $(TARGET)...$(NC)"
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "$(GREEN)✅ Uninstallation completed!$(NC)"

# Run the program
run: $(TARGET)
	@echo "$(GREEN)🚀 Starting Student Database Management System...$(NC)"
	@echo "$(YELLOW)📺 Demo available at: https://drive.google.com/file/d/1jEDYunQDI8niG00F-GcaM6MtDZPDfCcr/view?usp=sharing$(NC)"
	@echo "$(BLUE)===========================================$(NC)"
	./$(TARGET)

# Debug build
debug: CFLAGS = $(DEBUG_FLAGS)
debug: clean $(TARGET)
	@echo "$(YELLOW)🐛 Debug build completed with debug symbols!$(NC)"

# Backup
backup:
	@echo "$(BLUE)🔄 Backing up .txt data files...$(NC)"
	@if [ ! -d $(BACKUP_DIR) ]; then \
		mkdir $(BACKUP_DIR); \
	fi
	@if ls $(DATA_FILES) > /dev/null 2>&1; then \
		cp $(DATA_FILES) $(BACKUP_DIR)/ 2>/dev/null || true; \
		echo "$(GREEN)✅ Backup completed! .txt files stored in $(BACKUP_DIR) directory.$(NC)"; \
	else \
		echo "$(YELLOW)⚠️ No .txt data files found to backup.$(NC)"; \
	fi

# Version info
version:
	@echo "$(BLUE)📊 Student Database Management System$(NC)"
	@echo "$(GREEN)Version: $(VERSION)$(NC)"
	@echo "$(YELLOW)Updated: 2025-01-08$(NC)"
	@echo "$(BLUE)Demo: https://drive.google.com/file/d/1jEDYunQDI8niG00F-GcaM6MtDZPDfCcr/view?usp=sharing$(NC)"

# Check if program compiles without errors
check: $(TARGET)
	@echo "$(GREEN)✅ Compilation check passed!$(NC)"
	@echo "$(BLUE)🔍 Program is ready to run$(NC)"

# Quick test build (no optimization)
quick:
	@echo "$(BLUE)⚡ Quick build without optimization...$(NC)"
	$(CC) -Wall -Wextra -std=c99 -O0 -o $(TARGET) main.c student_database.c
	@echo "$(GREEN)✅ Quick build completed!$(NC)"

# Help
help:
	@echo "$(BLUE)===========================================$(NC)"
	@echo "$(GREEN)  Student Database Management System$(NC)"
	@echo "$(YELLOW)  Version: $(VERSION)$(NC)"
	@echo "$(BLUE)===========================================$(NC)"
	@echo "Available targets:"
	@echo "  $(GREEN)all$(NC)         - Build the program (default)"
	@echo "  $(GREEN)clean$(NC)       - Remove build files only"
	@echo "  $(GREEN)clean-data$(NC)  - Remove only data files (*.txt)"
	@echo "  $(GREEN)clean-all$(NC)   - Remove both build files and data files"
	@echo "  $(GREEN)run$(NC)         - Build and run the program"
	@echo "  $(GREEN)debug$(NC)       - Build with debug information"
	@echo "  $(GREEN)quick$(NC)       - Quick build without optimization"
	@echo "  $(GREEN)check$(NC)       - Verify compilation without errors"
	@echo "  $(GREEN)install$(NC)     - Install to /usr/local/bin"
	@echo "  $(GREEN)uninstall$(NC)   - Remove from /usr/local/bin"
	@echo "  $(GREEN)backup$(NC)      - Backup data files to $(BACKUP_DIR)"
	@echo "  $(GREEN)version$(NC)     - Show version information"
	@echo "  $(GREEN)help$(NC)        - Show this help message"
	@echo "$(BLUE)===========================================$(NC)"
	@echo "$(YELLOW)📺 Demo: https://drive.google.com/file/d/1jEDYunQDI8niG00F-GcaM6MtDZPDfCcr/view?usp=sharing$(NC)"
	@echo "$(BLUE)===========================================$(NC)"

.PHONY: all clean clean-data clean-all run debug install uninstall help backup version check quick
