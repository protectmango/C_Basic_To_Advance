# Student Database Management System

A comprehensive C program for managing student records with dynamic memory allocation, file operations, and various search functionalities.

## Features

### Core Functionality
1. **Dynamic Memory Allocation**: Allocates memory for n student records
2. **Batch-wise File Storage**: Stores records in separate files based on batch ID
3. **Multiple Search Options**:
   - Search by join date (day, month, year)
   - Search by birth date (day, month, year)
   - Search by student name
   - Search by batch ID
   - Search by marks range
   - Search by assessment status
4. **Record Editing**: Edit existing student information
5. **Display All Records**: View all stored student records

### Student Structure
```c
struct st {
    char batch_id[10];              // e.g., v22be8a1
    char name[50];                  // Full name
    float avg_internal_marks;       // Average marks (0-100)
    char assessment_status[5];      // "r" (regular) or "nr" (non-regular)
    struct date dob;                // Date of birth
    struct date doj;                // Date of joining
};

struct date {
    int day;
    int month;
    int year;
};
```

## File Structure

```
project/
├── student_database.h     # Header file with declarations
├── student_database.c     # Implementation file
├── main.c                 # Main program with menu interface
├── Makefile              # Build configuration
└── README.md             # This file
```

## Compilation and Execution

### Using Make (Recommended)
```bash
# Build the program
make

# Build and run
make run

# Clean build files
make clean

# Clean only data files
make clean-data

# Build with debug information
make debug

# View all make targets
make help
```

### Manual Compilation
```bash
gcc -Wall -Wextra -std=c99 -c main.c
gcc -Wall -Wextra -std=c99 -c student_database.c
gcc -Wall -Wextra -std=c99 -o student_database main.o student_database.o
```

### Running the Program
```bash
./student_database
```

## Usage

### Menu Options
1. **Add new students**: Input student data and save to batch files
2. **Search by join date**: Find students by their joining date
3. **Search by birth date**: Find students by their birth date
4. **Search by name**: Find students by their full name
5. **Search by batch ID**: Display all students in a specific batch
6. **Edit student record**: Modify existing student information
7. **Search by marks range**: Find students within a marks range
8. **Search by assessment status**: Find students by assessment status
9. **Display all records**: Show all stored student records
10. **Exit**: Quit the program

### Sample Usage

#### Adding Students
1. Select option 1 from the menu
2. Enter the number of students to add
3. For each student, provide:
   - Batch ID (e.g., v22be8a1)
   - Full name
   - Average internal marks (0-100)
   - Assessment status (r/nr)
   - Date of birth (DD MM YYYY)
   - Date of joining (DD MM YYYY)

#### Searching Records
- **By Date**: Enter date in DD MM YYYY format
- **By Name**: Enter the full name (case-insensitive)
- **By Batch ID**: Enter batch ID (e.g., v22be8a1)
- **By Marks**: Enter minimum and maximum marks
- **By Status**: Enter "r" for regular or "nr" for non-regular

#### Editing Records
1. Select option 6 from the menu
2. Enter the batch ID of the student to edit
3. Choose the student from the list
4. Select the field to edit
5. Enter the new value

## File Storage

The program stores student records in binary files named after their batch IDs:
- `v22be8a1.dat` - Contains all students from batch v22be8a1
- `v22be8a2.dat` - Contains all students from batch v22be8a2
- etc.

## Data Validation

The program includes validation for:
- **Date validation**: Checks for valid days, months, years, and leap years
- **Marks range**: Ensures marks are between 0-100
- **Assessment status**: Accepts only "r" or "nr"
- **Memory allocation**: Handles allocation failures gracefully

## Error Handling

- File operation errors are handled with appropriate error messages
- Invalid input is rejected with user-friendly messages
- Memory allocation failures are handled safely
- Date validation prevents invalid dates

## Technical Details

### Memory Management
- Dynamic memory allocation using `malloc()`
- Proper memory deallocation using `free()`
- Memory leak prevention

### File Operations
- Binary file I/O for efficient storage
- Separate files for each batch
- Read/write operations with error checking

### Search Algorithms
- Linear search through all batch files
- Case-insensitive name matching
- Range-based searches for marks

## Development Notes

### Compiler Requirements
- GCC with C99 standard support
- Standard C library functions

### Dependencies
- No external dependencies required
- Uses only standard C libraries

### Platform Compatibility
- Cross-platform compatible
- Tested on macOS, Linux, and Windows

## Future Enhancements

Possible improvements:
1. Add sorting functionality
2. Implement binary search for faster lookups
3. Add data import/export features
4. Implement user authentication
5. Add statistical analysis features
6. Create a GUI version

## License

This project is created for educational purposes. Feel free to use and modify as needed.

## Author

Created as part of C Programming coursework - Basic to Advanced level.
