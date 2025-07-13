#!/bin/bash

# Demo script to showcase all Makefile learning levels
# This script runs through each level demonstrating progressive concepts

set -e  # Exit on any error

echo "======================================================"
echo "🎯 MAKEFILE LEARNING TUTORIAL - COMPLETE DEMO"
echo "======================================================"
echo "This demo will walk through all 5 levels of Makefile"
echo "concepts, from basic to advanced project structure."
echo ""

# Function to print section headers
print_section() {
    echo ""
    echo "" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
    echo "📚 $1"
    echo "" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
    echo ""
}

# Function to wait for user input
wait_for_user() {
    echo ""
    read -p "Press Enter to continue to the next level..."
    echo ""
}

# Function to run a demo in a directory
run_demo() {
    local dir=$1
    local description=$2
    
    if [ ! -d "$dir" ]; then
        echo "❌ Directory $dir not found!"
        return 1
    fi
    
    echo "📁 Entering directory: $dir"
    echo "💡 $description"
    echo ""
    
    cd "$dir"
    
    # Show the Makefile structure
    echo "📄 Makefile structure:"
    head -20 Makefile | grep -E '^#|^[A-Za-z].*:.*$|^[[:space:]]*[A-Za-z].*=' | head -10
    echo "   ... (see full Makefile for details)"
    echo ""
    
    # Clean any previous builds
    echo "🧹 Cleaning previous builds..."
    make clean > /dev/null 2>&1 || true
    echo ""
    
    # Build the project
    echo "🔨 Building the project..."
    make
    echo ""
    
    # Run the program
    echo "🏃 Running the program..."
    if [ -f "hello" ]; then
        ./hello
    elif [ -f "math" ]; then
        ./math
    elif [ -f "calculator" ]; then
        ./calculator
    elif [ -f "bin/advanced_demo" ]; then
        ./bin/advanced_demo
    elif [ -f "build/bin/advanced_calculator" ]; then
        ./build/bin/advanced_calculator
    else
        echo "Program not found or not executable"
    fi
    
    cd ..
}

# Check if we're in the right directory
if [ ! -f "README.md" ] || [ ! -d "01_basic" ]; then
    echo "❌ Please run this script from the learnmake directory"
    exit 1
fi

echo "Starting the demo journey through Makefile concepts..."
echo ""

# Level 1: Basic Makefile
print_section "LEVEL 1: BASIC MAKEFILE"
echo "Learning: Basic syntax, targets, prerequisites, recipes"
echo "Key Concept: The fundamental target-prerequisite-recipe structure"
run_demo "01_basic" "A simple Makefile with one target and basic compilation"
wait_for_user

# Level 2: Variables and Targets
print_section "LEVEL 2: VARIABLES AND TARGETS"
echo "Learning: Variables, PHONY targets, clean targets, help"
echo "Key Concept: Making Makefiles maintainable with variables"
run_demo "02_variables" "Introduction of variables and utility targets"
wait_for_user

# Level 3: Multiple Files
print_section "LEVEL 3: MULTIPLE FILES AND OBJECT COMPILATION"
echo "Learning: Object files, dependencies, incremental compilation"
echo "Key Concept: Separating compilation and linking for efficiency"
run_demo "03_multiple_files" "Handling multiple source files and headers"
wait_for_user

# Level 4: Advanced Features
print_section "LEVEL 4: ADVANCED MAKEFILE FEATURES"
echo "Learning: Pattern rules, automatic variables, wildcard functions"
echo "Key Concept: Automation and advanced Makefile techniques"
run_demo "04_advanced" "Pattern rules, automatic dependency generation, organized builds"
wait_for_user

# Level 5: Project Structure
print_section "LEVEL 5: PROFESSIONAL PROJECT STRUCTURE"
echo "Learning: Libraries, modular architecture, professional organization"
echo "Key Concept: Real-world project structure with static libraries"
run_demo "05_project_structure" "Complete project with libraries and professional build system"

echo ""
echo "" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
echo "🎉 CONGRATULATIONS! YOU'VE COMPLETED THE MAKEFILE TUTORIAL!"
echo "" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
echo ""
echo "📈 What you've learned:"
echo "   • Basic Makefile syntax and structure"
echo "   • Variables and target organization"
echo "   • Object file compilation and linking"
echo "   • Advanced pattern rules and automation"
echo "   • Professional project structure with libraries"
echo ""
echo "🎯 Next Steps:"
echo "   • Try the exercises in README.md"
echo "   • Adapt these patterns to your own projects"
echo "   • Explore the GNU Make manual for more advanced features"
echo "   • Create your own Makefiles for existing projects"
echo ""
echo "💡 Pro Tips:"
echo "   • Always use variables for compiler and flags"
echo "   • Use pattern rules to reduce code duplication"
echo "   • Organize large projects with subdirectories"
echo "   • Include help targets in your Makefiles"
echo "   • Use automatic dependency generation for headers"
echo ""
echo "Happy coding! 🚀"
echo ""

