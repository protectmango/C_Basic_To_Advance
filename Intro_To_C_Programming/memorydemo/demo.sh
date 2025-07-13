#!/bin/bash

# Demo script for Student Database Program
# This script demonstrates the program with sample data

echo "=== Student Database Demo Script ==="
echo "This script will demonstrate the student database program"
echo "with sample data and pointer concepts."
echo ""

# Compile the program
echo "Compiling the program..."
make clean-exe > /dev/null 2>&1
make > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "Error: Failed to compile the program"
    exit 1
fi

echo "Program compiled successfully!"
echo ""

# Create input file with sample data
cat > sample_input.txt << 'EOF'
1
1001
John Smith
20
3
85.5
92.0
78.5
1
1002
Emily Johnson
19
4
94.0
88.5
91.0
87.5
1
1003
Michael Brown
21
2
76.0
82.5
4
2
5
6
7
8
EOF

echo "Running program with sample data..."
echo "(Adding 3 students and demonstrating all features)"
echo ""

# Run the program with sample input
./student_database demo_mode sample_data < sample_input.txt

echo ""
echo "=== Demo completed! ==="
echo "The program demonstrated:"
echo "1. Command line arguments processing"
echo "2. Adding students (pointer to array, structure pointers)"
echo "3. Calculating averages (pointer arithmetic)"
echo "4. Display statistics (array of pointers)"
echo "5. Pointer concepts demonstration"
echo "6. File operations (save/load)"
echo ""
echo "Data has been saved to 'students.dat' file."
echo "You can run './student_database' again to see persistent data."
echo ""
echo "To explore the code and concepts, check:"
echo "- student_database.c (main program)"
echo "- README.md (detailed explanation)"
echo "- Makefile (build instructions)"

# Clean up
rm -f sample_input.txt

