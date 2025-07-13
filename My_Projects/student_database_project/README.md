# Student Database Management System

A comprehensive C program for managing student records with dynamic memory allocation, file operations, and various search functionalities.

## 🎬 Demo Video

**Watch the complete demonstration of the Student Database Management System:**

[![Demo Video](https://img.shields.io/badge/🎥_Watch_Demo-Google_Drive-blue?style=for-the-badge&logo=googledrive)](https://drive.google.com/file/d/1jEDYunQDI8niG00F-GcaM6MtDZPDfCcr/view?usp=sharing)

> 📺 **[Watch Demo](https://drive.google.com/file/d/1jEDYunQDI8niG00F-GcaM6MtDZPDfCcr/view?usp=sharing)** - See all features in action!

---

## 🆕 Recent Changes & Improvements

### What's New in Latest Updates:

| 🔍 **Search Enhancement** | Search by Student ID now shows only the specific student (not entire batch) |
|:---:|:---|
| **✏️ Edit Improvements** | Edit function now asks for batch prefix first and displays "ID : Name" format |
| **📋 Display Enhancement** | Display records now allows batch selection (specific batch or all records) |
| **🗂️ Registry System** | Enhanced batch registry system for better performance |
| **🗑️ Delete Operations** | Added comprehensive delete operations (single student and entire batch) |
| **💎 UI Improvements** | Professional formatting with Unicode box characters throughout |
| **⚠️ Error Handling** | Improved error handling and data validation |
| **🛡️ Safety Features** | Enhanced safety features with confirmation dialogs |
| **📖 Documentation** | Updated documentation with detailed technical specifications |

### 📊 Recent Development Activity:
- ✅ **Latest**: Modified comments and code cleanup
- 🔧 **Fixed**: Search student by ID and edit student by ID functionality
- 📊 **Improved**: Database structure and dummy data handling
- 📚 **Enhanced**: Text formatting and documentation updates
- 🧹 **Cleaned**: Removal of temporary files and ID corrections
- 🗑️ **Optimized**: Deletion of junk files and project cleanup

---

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
4. **Record Management**: Edit and delete existing student information
5. **Display All Records**: View all stored student records
6. **Batch Registry System**: Centralized tracking of active batches
7. **Data Validation**: Comprehensive input validation for all fields
8. **Safety Features**: Confirmation dialogs for destructive operations

### Student Structure
```c
struct st {
    char batch_id[10];              // e.g., v24be8g5
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
5. **Search by student ID**: Find specific student by their unique ID
6. **Edit student record**: Modify existing student information
7. **Search by marks range**: Find students within a marks range
8. **Search by assessment status**: Find students by assessment status
9. **Display records**: Show student records (specific batch or all records)
10. **Delete student by ID**: Remove a specific student record
11. **Delete entire batch**: Remove all students from a batch
12. **Exit**: Quit the program

### Sample Usage

#### Adding Students
1. Select option 1 from the menu
2. Enter the number of students to add
3. For each student, provide:
   - Batch ID (e.g., v24be8g5)
   - Full name
   - Average internal marks (0-100)
   - Assessment status (r/nr)
   - Date of birth (DD MM YYYY)
   - Date of joining (DD MM YYYY)

#### Searching Records
- **By Date**: Enter date in DD MM YYYY format
- **By Name**: Enter the full name (case-insensitive)
- **By Student ID**: Enter exact student ID (e.g., v24be8g5) - Shows only that specific student
- **By Marks**: Enter minimum and maximum marks
- **By Status**: Enter "r" for regular or "nr" for non-regular

**Note**: Search by Student ID has been improved to show only the specific student with that exact ID, not all students in the batch.

#### Editing Records
1. Select option 6 from the menu
2. Enter the batch prefix (first 6 characters, e.g., v24be8)
3. Choose the student from the list (displayed as "ID : Name")
4. Select the field to edit
5. Enter the new value

**Improvements in Edit Function**:
- Now asks for batch prefix first for better organization
- Displays students in clear "ID : Name" format (e.g., "v24be8g5 : Gulshan Kumar Rana")
- Makes it easier to identify which student to edit
- More intuitive user interface

#### Deleting Records
**Delete Single Student:**
1. Select option 10 from the menu
2. Enter the exact batch ID of the student to delete
3. Review the student details displayed
4. Confirm deletion (y/n)

**Delete Entire Batch:**
1. Select option 11 from the menu
2. Enter the batch prefix (first 6 characters, e.g., v24be8)
3. Review the list of all students in the batch
4. Confirm deletion (y/n)

#### Displaying Records
**Enhanced Display Options:**
1. Select option 9 from the menu
2. Choose display type:
   - **Specific Batch**: Enter batch prefix (e.g., "v24be8")
   - **All Records**: Enter "all" to display all student records

**Display Features**:
- Professional formatted output with headers
- Student counter for each batch
- Total count summary
- Clear batch separation
- Numbered student listing

**Examples**:
- Enter "v24be8" to show only students from batch v24be8
- Enter "all" to display all students from all batches
- Case-insensitive input ("ALL", "all", "All" all work)

## File Storage

The program stores student records in binary files named after their batch IDs:
- `v24be8.txt` - Contains all students from batch v24be8
- `v24be9.txt` - Contains all students from batch v24be9
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

## Version Information

**Current Version**: v24be8g5
**Release Date**: 2025-01-08

### 🚀 Latest Updates (January 2025)

#### Recent Commits:
- **✅ Modified comments** (Latest - HEAD)
- **🔧 Fixed search student by ID and edit student by ID** 
- **📊 Database dummy changes and improvements**
- **📚 Text and documentation updates**
- **🧹 Removal of temporary files and corrections**
- **🗑️ Deletion of junk files and cleanup**

#### Key Features in v24be8g5:
- **🔍 FIXED**: Search by student ID now shows only the specific student (not entire batch)
- **✏️ IMPROVED**: Edit function now asks for batch prefix first and displays "ID : Name" format
- **📋 ENHANCED**: Display records now allows batch selection (specific batch or all records)
- **🗂️ Enhanced batch registry system** for better performance
- **🗑️ Added comprehensive delete operations** (single student and entire batch)
- **💎 Professional formatting** with Unicode box characters throughout the system
- **⚠️ Improved error handling** and data validation
- **🛡️ Enhanced safety features** with confirmation dialogs
- **🧠 Better memory management** and file operations
- **📖 Updated documentation** with detailed technical specifications
- **🎬 Added demo video** for better user understanding

## Future Enhancements

Possible improvements:
1. Add sorting functionality for better data organization
2. Implement binary search for faster lookups
3. Add data import/export features (CSV, JSON)
4. Implement user authentication and access control
5. Add statistical analysis and reporting features
6. Create a GUI version using GTK+ or Qt
7. Add backup and restore functionality
8. Implement database encryption for sensitive data

## License

This project is created for educational purposes. Feel free to use and modify as needed.

## Author
Hey👋, I am Gulshan Rana. 
This project is created as part of C Programming coursework - Basic to Advanced level.
I have taken help multiple platform to understand the basics and get this done.This will be a good revision for future me.

