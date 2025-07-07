# Student Database Management System

## Overview
This document provides a detailed description of the student database management system, including code explanations and functionalities.

## Key Features
- Add new students to the batch
- Search for students by various criteria
- Edit student records
- Delete student records by batch ID or by entire batch
- Track batches using a file-based registry system

## File: `student_database.h`

### Description
Header file containing structure definitions and function declarations for managing the student database.

### Code Snippet
```c
// Date structure
struct date {
    int day;
    int month;
    int year;
};

// Student structure
struct st {
    char batch_id[10];
    char name[50];
    float avg_internal_marks;
    char assessment_status[5];
    struct date dob;
    struct date doj;
};
```

### Explanation
- **Date Structure**: Represents day, month, and year for birth and joining dates.
- **Student Structure**: Holds student information including batch ID, name, marks, status, and dates.

### Function Declarations
```c
void add_batch_to_registry(char* batch_prefix);
void remove_batch_from_registry(char* batch_prefix);
void get_registered_batches(char batch_files[][50], int* count);
```

### Explanation
- **Batch Registry Functions**:
  - `add_batch_to_registry`: Adds a batch prefix to the registry file.
  - `remove_batch_from_registry`: Removes a batch prefix.
  - `get_registered_batches`: Retrieves all batches from the registry.

## File: `student_database.c`

### Description
Contains the main implementations for handling student data and batch registry operations.

### Code Snippets
#### Adding a Batch to Registry
```c
void add_batch_to_registry(char* batch_prefix) {
    if (is_batch_registered(batch_prefix)) return;
    FILE* file = fopen("student_batch.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s\n", batch_prefix);
        fclose(file);
    }
}
```

#### Explanation
- **Functionality**: Adds a batch ID to `student_batch.txt` if not already present.
- **Safety**: Ensures no duplicate entries.

### Display All Records
```c
void display_all_records() {
    char batch_files[50][50];
    int file_count;
    get_registered_batches(batch_files, &file_count);
    for (int i = 0; i < file_count; i++) {
        FILE* file = fopen(batch_files[i], "rb");
        // Process each student record
    }
}
```

#### Explanation
- **Functionality**: Reads batch IDs from the registry and displays all student records.
- **Efficiency**: Uses registry rather than system commands to locate files.

## File: `main.c`

### Description
Handles program start, menu display, and interactions based on user inputs.

### Code Snippet
#### Main Loop
```c
while (1) {
    display_menu();
    scanf("%d", &choice);
    switch (choice) {
        case 10: // Delete student by batch ID
            // Code to delete student
            break;
        case 11: // Delete all students by batch
            // Code to delete entire batch
            break;
        case 12:
            exit(0);
    }
}
```

### Explanation
- **Menu Handling**: Provides a loop for continuous menu interaction and handles various operations like adding, searching, editing, and deleting records.
- **Delete Operations**: Integrated with user confirmation for safety.

## Usage
1. **Adding Students**: Input data when prompted and save to batch files.
2. **Searching Records**: Use search functions by name, date, or marks.
3. **Editing Records**: Modify details of existing students.
4. **Deleting Records**: Remove student using batch ID or by entire batch.

## Conclusion
This system is designed to efficiently manage student records with robust error handling and maintains batch information using a file-based registry for portability and performance. Import this into a word processor for styling and further formatting.
