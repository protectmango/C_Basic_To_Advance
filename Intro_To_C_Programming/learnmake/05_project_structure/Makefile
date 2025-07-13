# LEVEL 5: Professional Project Structure with Libraries
# This demonstrates a complete project structure with multiple libraries,
# subdirectories, static libraries, and professional build organization

# ============================================================================
# PROJECT CONFIGURATION
# ============================================================================

PROJECT_NAME := advanced_calculator
VERSION := 1.0.0
AUTHOR := Your Name
DESCRIPTION := Advanced calculator with modular architecture

# ============================================================================
# DIRECTORIES
# ============================================================================

# Source directories
SRCDIR := src
TEST_DIR := tests
DOC_DIR := docs

# Build directories
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
LIB_DIR := $(BUILD_DIR)/lib
BIN_DIR := $(BUILD_DIR)/bin
DEP_DIR := $(BUILD_DIR)/deps

# Library source directories
CALC_DIR := $(SRCDIR)/calculator
LOGGER_DIR := $(SRCDIR)/logger
CONFIG_DIR := $(SRCDIR)/config

# ============================================================================
# COMPILER SETTINGS
# ============================================================================

CC := gcc
AR := ar
CFLAGS := -Wall -Wextra -std=c99 -g -O2
CPPFLAGS := -I$(SRCDIR)  # Include directories
LDFLAGS := -L$(LIB_DIR)  # Library directories
LIBS := -lcalculator -llogger -lconfig  # Libraries to link

# Additional flags for different builds
DEBUG_FLAGS := -g3 -O0 -DDEBUG
RELEASE_FLAGS := -O3 -DNDEBUG -s
PROFILE_FLAGS := -pg

# ============================================================================
# FILE DISCOVERY
# ============================================================================

# Main program
MAIN_SRC := $(SRCDIR)/main.c
MAIN_OBJ := $(OBJ_DIR)/main.o

# Library sources
CALC_SRCS := $(wildcard $(CALC_DIR)/*.c)
LOGGER_SRCS := $(wildcard $(LOGGER_DIR)/*.c)
CONFIG_SRCS := $(wildcard $(CONFIG_DIR)/*.c)

# Library objects
CALC_OBJS := $(CALC_SRCS:$(CALC_DIR)/%.c=$(OBJ_DIR)/calculator/%.o)
LOGGER_OBJS := $(LOGGER_SRCS:$(LOGGER_DIR)/%.c=$(OBJ_DIR)/logger/%.o)
CONFIG_OBJS := $(CONFIG_SRCS:$(CONFIG_DIR)/%.c=$(OBJ_DIR)/config/%.o)

# All objects
ALL_OBJS := $(MAIN_OBJ) $(CALC_OBJS) $(LOGGER_OBJS) $(CONFIG_OBJS)

# Static libraries
CALC_LIB := $(LIB_DIR)/libcalculator.a
LOGGER_LIB := $(LIB_DIR)/liblogger.a
CONFIG_LIB := $(LIB_DIR)/libconfig.a
ALL_LIBS := $(CALC_LIB) $(LOGGER_LIB) $(CONFIG_LIB)

# Target executable
TARGET := $(BIN_DIR)/$(PROJECT_NAME)

# Dependency files
DEP_FILES := $(ALL_OBJS:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# ============================================================================
# CREATE DIRECTORIES
# ============================================================================

$(shell mkdir -p $(OBJ_DIR)/calculator $(OBJ_DIR)/logger $(OBJ_DIR)/config)
$(shell mkdir -p $(LIB_DIR) $(BIN_DIR) $(DEP_DIR)/calculator $(DEP_DIR)/logger $(DEP_DIR)/config)

# ============================================================================
# MAIN TARGETS
# ============================================================================

.PHONY: all clean clean-all debug release profile test install uninstall help

# Default target
all: $(TARGET)
	@echo "\n🎉 Build Complete!"
	@echo "   Executable: $(TARGET)"
	@echo "   Libraries: $(words $(ALL_LIBS)) static libraries"
	@echo "   Size: $$(ls -lh $(TARGET) | awk '{print $$5}')"

# Main executable - depends on main object and all libraries
$(TARGET): $(MAIN_OBJ) $(ALL_LIBS) | $(BIN_DIR)
	@echo "🔗 Linking $(PROJECT_NAME)..."
	$(CC) $(LDFLAGS) $(MAIN_OBJ) -o $@ $(LIBS)
	@echo "✓ Linking complete"

# ============================================================================
# STATIC LIBRARIES
# ============================================================================

# Calculator library
$(CALC_LIB): $(CALC_OBJS) | $(LIB_DIR)
	@echo "📚 Creating calculator library..."
	$(AR) rcs $@ $^
	@echo "✓ Calculator library created"

# Logger library
$(LOGGER_LIB): $(LOGGER_OBJS) | $(LIB_DIR)
	@echo "📚 Creating logger library..."
	$(AR) rcs $@ $^
	@echo "✓ Logger library created"

# Config library
$(CONFIG_LIB): $(CONFIG_OBJS) | $(LIB_DIR)
	@echo "📚 Creating config library..."
	$(AR) rcs $@ $^
	@echo "✓ Config library created"

# ============================================================================
# OBJECT FILE COMPILATION
# ============================================================================

# Main program object
$(MAIN_OBJ): $(MAIN_SRC) | $(OBJ_DIR)
	@echo "🔨 Compiling main.c..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -MF $(DEP_DIR)/main.d -c $< -o $@

# Calculator objects
$(OBJ_DIR)/calculator/%.o: $(CALC_DIR)/%.c | $(OBJ_DIR)/calculator
	@echo "🔨 Compiling $<..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -MF $(DEP_DIR)/calculator/$*.d -c $< -o $@

# Logger objects
$(OBJ_DIR)/logger/%.o: $(LOGGER_DIR)/%.c | $(OBJ_DIR)/logger
	@echo "🔨 Compiling $<..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -MF $(DEP_DIR)/logger/$*.d -c $< -o $@

# Config objects
$(OBJ_DIR)/config/%.o: $(CONFIG_DIR)/%.c | $(OBJ_DIR)/config
	@echo "🔨 Compiling $<..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -MF $(DEP_DIR)/config/$*.d -c $< -o $@

# Include dependency files
-include $(DEP_FILES)

# ============================================================================
# BUILD VARIANTS
# ============================================================================

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean $(TARGET)
	@echo "🐛 Debug build complete"

# Release build
release: CFLAGS += $(RELEASE_FLAGS)
release: clean $(TARGET)
	@echo "🚀 Release build complete"

# Profile build
profile: CFLAGS += $(PROFILE_FLAGS)
profile: LDFLAGS += $(PROFILE_FLAGS)
profile: clean $(TARGET)
	@echo "📊 Profile build complete"

# ============================================================================
# UTILITY TARGETS
# ============================================================================

# Run the program
run: $(TARGET)
	@echo "🏃 Running $(PROJECT_NAME)..."
	@./$(TARGET)

# Test the program (placeholder for now)
test:
	@echo "🧪 Running tests..."
	@echo "No tests implemented yet"

# Show project information
info:
	@echo "=== Project Information ==="
	@echo "Project:    $(PROJECT_NAME)"
	@echo "Version:    $(VERSION)"
	@echo "Author:     $(AUTHOR)"
	@echo "Description: $(DESCRIPTION)"
	@echo ""
	@echo "=== Build Configuration ==="
	@echo "CC:         $(CC)"
	@echo "CFLAGS:     $(CFLAGS)"
	@echo "CPPFLAGS:   $(CPPFLAGS)"
	@echo "LDFLAGS:    $(LDFLAGS)"
	@echo "LIBS:       $(LIBS)"
	@echo ""
	@echo "=== Directory Structure ==="
	@echo "Source:     $(SRCDIR)"
	@echo "Build:      $(BUILD_DIR)"
	@echo "Objects:    $(OBJ_DIR)"
	@echo "Libraries:  $(LIB_DIR)"
	@echo "Binaries:   $(BIN_DIR)"
	@echo ""
	@echo "=== Files ==="
	@echo "Sources:    $(words $(CALC_SRCS) $(LOGGER_SRCS) $(CONFIG_SRCS)) + main"
	@echo "Objects:    $(words $(ALL_OBJS))"
	@echo "Libraries:  $(words $(ALL_LIBS))"

# Show library contents
lib-info:
	@echo "=== Library Information ==="
	@for lib in $(ALL_LIBS); do \
		if [ -f $$lib ]; then \
			echo "$$lib:"; \
			ar -t $$lib | sed 's/^/  /'; \
			echo; \
		fi; \
	done

# Show file sizes
sizes: $(TARGET)
	@echo "=== File Sizes ==="
	@echo "Executable:"
	@ls -lh $(TARGET) | awk '{print "  " $$9 ": " $$5}'
	@echo "Libraries:"
	@ls -lh $(ALL_LIBS) 2>/dev/null | awk '{print "  " $$9 ": " $$5}' || true
	@echo "Total object files: $(words $(ALL_OBJS))"

# Create documentation
docs:
	@echo "📖 Generating documentation..."
	@mkdir -p $(DOC_DIR)
	@echo "# $(PROJECT_NAME) Documentation" > $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "Version: $(VERSION)" >> $(DOC_DIR)/README.md
	@echo "Author: $(AUTHOR)" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## Description" >> $(DOC_DIR)/README.md
	@echo "$(DESCRIPTION)" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## Build Instructions" >> $(DOC_DIR)/README.md
	@echo "\`\`\`" >> $(DOC_DIR)/README.md
	@echo "make         # Build the project" >> $(DOC_DIR)/README.md
	@echo "make run     # Run the program" >> $(DOC_DIR)/README.md
	@echo "make clean   # Clean build files" >> $(DOC_DIR)/README.md
	@echo "\`\`\`" >> $(DOC_DIR)/README.md
	@echo "✓ Documentation created in $(DOC_DIR)/"

# ============================================================================
# INSTALLATION
# ============================================================================

install: $(TARGET)
	@echo "📦 Installing $(PROJECT_NAME)..."
	sudo cp $(TARGET) /usr/local/bin/
	sudo chmod 755 /usr/local/bin/$(PROJECT_NAME)
	@echo "✓ Installation complete"

uninstall:
	@echo "🗑️  Uninstalling $(PROJECT_NAME)..."
	sudo rm -f /usr/local/bin/$(PROJECT_NAME)
	@echo "✓ Uninstallation complete"

# ============================================================================
# PACKAGING
# ============================================================================

# Create source distribution
dist: clean
	@echo "📦 Creating distribution package..."
	@tar -czf $(PROJECT_NAME)-$(VERSION)-src.tar.gz \
		--exclude='$(BUILD_DIR)' \
		--exclude='*.tar.gz' \
		--exclude='.git*' \
		.
	@echo "✓ Source package: $(PROJECT_NAME)-$(VERSION)-src.tar.gz"

# Create binary distribution
dist-bin: release
	@echo "📦 Creating binary package..."
	@mkdir -p dist/$(PROJECT_NAME)-$(VERSION)
	@cp $(TARGET) dist/$(PROJECT_NAME)-$(VERSION)/
	@cp README.md dist/$(PROJECT_NAME)-$(VERSION)/ 2>/dev/null || true
	@cd dist && tar -czf ../$(PROJECT_NAME)-$(VERSION)-bin.tar.gz $(PROJECT_NAME)-$(VERSION)
	@rm -rf dist
	@echo "✓ Binary package: $(PROJECT_NAME)-$(VERSION)-bin.tar.gz"

# ============================================================================
# CLEANING
# ============================================================================

clean:
	@echo "🧹 Cleaning build files..."
	rm -rf $(BUILD_DIR)
	@echo "✓ Clean complete"

clean-all: clean
	@echo "🧹 Deep cleaning..."
	rm -rf $(DOC_DIR) *.tar.gz config.cfg
	rm -f *~ *.bak *.tmp core.*
	@echo "✓ Deep clean complete"

# ============================================================================
# HELP
# ============================================================================

help:
	@echo "=== $(PROJECT_NAME) Makefile Help ==="
	@echo ""
	@echo "🏗️  Build Targets:"
	@echo "  all          Build the entire project (default)"
	@echo "  debug        Build with debug symbols"
	@echo "  release      Build optimized release version"
	@echo "  profile      Build with profiling support"
	@echo ""
	@echo "🏃 Run Targets:"
	@echo "  run          Build and run the program"
	@echo "  test         Run test suite"
	@echo ""
	@echo "ℹ️  Information:"
	@echo "  info         Show project and build information"
	@echo "  lib-info     Show library contents"
	@echo "  sizes        Show file sizes"
	@echo ""
	@echo "📖 Documentation:"
	@echo "  docs         Generate documentation"
	@echo ""
	@echo "📦 Distribution:"
	@echo "  install      Install to system"
	@echo "  uninstall    Remove from system"
	@echo "  dist         Create source package"
	@echo "  dist-bin     Create binary package"
	@echo ""
	@echo "🧹 Cleaning:"
	@echo "  clean        Remove build files"
	@echo "  clean-all    Remove all generated files"
	@echo ""
	@echo "🎯 Key Features Demonstrated:"
	@echo "  • Modular library architecture"
	@echo "  • Static library creation and linking"
	@echo "  • Organized directory structure"
	@echo "  • Automatic dependency tracking"
	@echo "  • Multiple build configurations"
	@echo "  • Professional packaging"
	@echo "  • Installation support"

# ============================================================================
# SPECIAL TARGETS AND SETTINGS
# ============================================================================

# Make sure intermediate files aren't deleted
.PRECIOUS: $(ALL_OBJS) $(ALL_LIBS)

# Default goal
.DEFAULT_GOAL := all

# Disable built-in rules for better performance
.SUFFIXES:

