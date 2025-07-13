# LEVEL 4: Advanced Makefile with Pattern Rules and Automatic Variables
# This demonstrates advanced features like wildcards, automatic dependency generation

# ============================================================================
# VARIABLES
# ============================================================================

# Compiler settings
CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -std=c99 -g -O2
CXXFLAGS := -Wall -Wextra -std=c++17 -g -O2
LDFLAGS := 
LIBS := 

# Directories
SRCDIR := .
OBJDIR := obj
BINDIR := bin
DEPDIR := deps

# Files
TARGET := advanced_demo
SOURCES := $(wildcard $(SRCDIR)/*.c)          # Find all .c files automatically
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)  # Convert .c to .o in obj dir
DEPENDS := $(SOURCES:$(SRCDIR)/%.c=$(DEPDIR)/%.d)  # Dependency files

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(BINDIR) $(DEPDIR))

# ============================================================================
# TARGETS
# ============================================================================

# Default target
all: $(BINDIR)/$(TARGET)
	@echo "\n=== Build Complete ==="
	@echo "Executable: $(BINDIR)/$(TARGET)"
	@echo "Object files: $(words $(OBJECTS)) files in $(OBJDIR)/"

# Link target - creates executable from object files
$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	@echo "Linking $(TARGET)..."
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)
	@echo "✓ Linking complete"

# Pattern rule: compile .c files to .o files with automatic dependency generation
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@
	@echo "✓ Compiled $<"

# Include dependency files (if they exist)
-include $(DEPENDS)

# ============================================================================
# UTILITY TARGETS
# ============================================================================

# Run the program
run: $(BINDIR)/$(TARGET)
	@echo "Running $(TARGET)..."
	@./$(BINDIR)/$(TARGET)

# Debug build (with debug symbols and no optimization)
debug: CFLAGS := -Wall -Wextra -std=c99 -g3 -O0 -DDEBUG
debug: clean $(BINDIR)/$(TARGET)
	@echo "Debug build complete"

# Release build (optimized, no debug symbols)
release: CFLAGS := -Wall -Wextra -std=c99 -O3 -DNDEBUG -s
release: clean $(BINDIR)/$(TARGET)
	@echo "Release build complete"

# Profile build (for profiling)
profile: CFLAGS += -pg
profile: LDFLAGS += -pg
profile: clean $(BINDIR)/$(TARGET)
	@echo "Profile build complete"

# ============================================================================
# ANALYSIS TARGETS
# ============================================================================

# Static analysis with different tools
analyze: analyze-syntax analyze-style

# Check syntax without compilation
analyze-syntax:
	@echo "Checking syntax..."
	@for file in $(SOURCES); do \
		echo "Checking $$file..."; \
		$(CC) $(CFLAGS) -fsyntax-only $$file; \
	done

# Code style check (if clang-format is available)
analyze-style:
	@echo "Checking code style..."
	@which clang-format > /dev/null 2>&1 && \
		for file in $(SOURCES); do \
			echo "Style check: $$file"; \
			clang-format --dry-run --Werror $$file; \
		done || echo "clang-format not available"

# Memory check (if valgrind is available)
memcheck: $(BINDIR)/$(TARGET)
	@which valgrind > /dev/null 2>&1 && \
		valgrind --leak-check=full --show-leak-kinds=all ./$(BINDIR)/$(TARGET) || \
		echo "valgrind not available"

# ============================================================================
# INFORMATION TARGETS
# ============================================================================

# Show makefile variables
info:
	@echo "=== Makefile Information ==="
	@echo "CC:       $(CC)"
	@echo "CFLAGS:   $(CFLAGS)"
	@echo "LDFLAGS:  $(LDFLAGS)"
	@echo "LIBS:     $(LIBS)"
	@echo "TARGET:   $(TARGET)"
	@echo "SOURCES:  $(SOURCES)"
	@echo "OBJECTS:  $(OBJECTS)"
	@echo "DEPENDS:  $(DEPENDS)"

# Show file sizes
sizes: $(BINDIR)/$(TARGET)
	@echo "=== File Sizes ==="
	@ls -lh $(BINDIR)/$(TARGET)
	@echo "Object files:"
	@ls -lh $(OBJDIR)/*.o 2>/dev/null || echo "No object files"

# Show dependencies
deps:
	@echo "=== Dependencies ==="
	@for dep in $(DEPENDS); do \
		if [ -f $$dep ]; then \
			echo "$$dep:"; \
			cat $$dep; \
			echo; \
		fi; \
	done

# ============================================================================
# PACKAGING AND DISTRIBUTION
# ============================================================================

# Create distribution package
dist: clean
	@echo "Creating distribution package..."
	@tar -czf $(TARGET)-$(shell date +%Y%m%d).tar.gz \
		--exclude='*.o' --exclude='*.d' --exclude='$(TARGET)' \
		--exclude='obj' --exclude='bin' --exclude='deps' \
		--exclude='*.tar.gz' .
	@echo "Package created: $(TARGET)-$(shell date +%Y%m%d).tar.gz"

# Install to system (requires sudo)
install: $(BINDIR)/$(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin..."
	sudo cp $(BINDIR)/$(TARGET) /usr/local/bin/
	sudo chmod 755 /usr/local/bin/$(TARGET)
	@echo "Installation complete"

# Uninstall from system
uninstall:
	@echo "Removing $(TARGET) from /usr/local/bin..."
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "Uninstallation complete"

# ============================================================================
# CLEANING TARGETS
# ============================================================================

# Clean all generated files
clean:
	@echo "Cleaning all generated files..."
	rm -rf $(OBJDIR) $(BINDIR) $(DEPDIR) sample.txt
	@echo "Clean complete"

# Clean only object files
clean-obj:
	@echo "Cleaning object files..."
	rm -rf $(OBJDIR)

# Clean only dependencies
clean-deps:
	@echo "Cleaning dependency files..."
	rm -rf $(DEPDIR)

# Clean only executable
clean-bin:
	@echo "Cleaning executable..."
	rm -rf $(BINDIR)

# Deep clean - everything including backup files
clean-all: clean
	@echo "Deep cleaning..."
	rm -f *~ *.bak *.tmp core.*
	@echo "Deep clean complete"

# ============================================================================
# HELP TARGET
# ============================================================================

help:
	@echo "=== Makefile Help ==="
	@echo "Build targets:"
	@echo "  all          - Build the program (default)"
	@echo "  debug        - Build with debug symbols"
	@echo "  release      - Build optimized version"
	@echo "  profile      - Build with profiling support"
	@echo ""
	@echo "Run targets:"
	@echo "  run          - Build and run the program"
	@echo "  memcheck     - Run with memory checking (valgrind)"
	@echo ""
	@echo "Analysis targets:"
	@echo "  analyze      - Run all code analysis"
	@echo "  analyze-syntax - Check syntax only"
	@echo "  analyze-style - Check code style"
	@echo ""
	@echo "Information targets:"
	@echo "  info         - Show makefile variables"
	@echo "  sizes        - Show file sizes"
	@echo "  deps         - Show dependencies"
	@echo ""
	@echo "Distribution targets:"
	@echo "  dist         - Create distribution package"
	@echo "  install      - Install to system"
	@echo "  uninstall    - Remove from system"
	@echo ""
	@echo "Cleaning targets:"
	@echo "  clean        - Remove all generated files"
	@echo "  clean-obj    - Remove only object files"
	@echo "  clean-deps   - Remove only dependency files"
	@echo "  clean-bin    - Remove only executable"
	@echo "  clean-all    - Deep clean everything"
	@echo ""
	@echo "Advanced features demonstrated:"
	@echo "  - Automatic dependency generation"
	@echo "  - Pattern rules with automatic variables"
	@echo "  - Wildcard source file detection"
	@echo "  - Separate directories for objects/deps"
	@echo "  - Multiple build configurations"
	@echo "  - Code analysis integration"
	@echo "  - Distribution packaging"

# ============================================================================
# SPECIAL TARGETS
# ============================================================================

# Phony targets (don't correspond to files)
.PHONY: all run debug release profile analyze analyze-syntax analyze-style \
        memcheck info sizes deps dist install uninstall clean clean-obj \
        clean-deps clean-bin clean-all help

# Don't delete intermediate files
.PRECIOUS: $(OBJDIR)/%.o

# Default goal
.DEFAULT_GOAL := all

# ============================================================================
# AUTOMATIC VARIABLES REFERENCE (for learning)
# ============================================================================
# $@  - Target name
# $<  - First prerequisite
# $^  - All prerequisites
# $?  - Prerequisites newer than target
# $*  - Stem of pattern rule
# $+  - Like $^, but includes duplicates
# $|  - Order-only prerequisites
#
# Pattern rules use % as wildcard
# $(var:pattern=replacement) - substitution reference
# $(wildcard pattern) - finds files matching pattern
# $(shell command) - execute shell command

