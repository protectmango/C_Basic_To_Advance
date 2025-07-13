#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define FILENAME "students.dat"

// Structure to represent a student
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    float grades[MAX_SUBJECTS];  // Array within structure
    int num_subjects;
    float average;
} Student;

// Function prototypes
void display_menu(void);
int add_student(Student *students, int *count, char *subjects[]);
void display_students(Student *students, int count, char *subjects[]);
void search_student(Student *students, int count);
void calculate_averages(Student *students, int count);
void save_to_file(Student *students, int count);
int load_from_file(Student *students);
void display_statistics(Student *students, int count);
void demonstrate_pointers(Student *students, int count, char *subjects[]);
char* get_grade_letter(float grade);

int main(int argc, char *argv[]) {
    // Command line arguments demonstration
    printf("=== STUDENT DATABASE SYSTEM ===");
    printf("\nProgram name: %s\n", argv[0]);
    printf("Number of arguments: %d\n", argc);
    
    if (argc > 1) {
        printf("Command line arguments provided:\n");
        for (int i = 1; i < argc; i++) {
            printf("  Arg %d: %s\n", i, argv[i]);
        }
    }
    printf("\n");
    
    // Array of pointers to strings (subject names)
    char *subjects[MAX_SUBJECTS] = {
        "Mathematics",
        "Physics", 
        "Chemistry",
        "Computer Science",
        "English"
    };
    
    // Array of students
    Student students[MAX_STUDENTS];
    int student_count = 0;
    
    // Load existing data from file
    student_count = load_from_file(students);
    
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (add_student(students, &student_count, subjects)) {
                    printf("Student added successfully!\n");
                } else {
                    printf("Failed to add student or database full!\n");
                }
                break;
                
            case 2:
                display_students(students, student_count, subjects);
                break;
                
            case 3:
                search_student(students, student_count);
                break;
                
            case 4:
                calculate_averages(students, student_count);
                printf("Averages calculated for all students!\n");
                break;
                
            case 5:
                display_statistics(students, student_count);
                break;
                
            case 6:
                demonstrate_pointers(students, student_count, subjects);
                break;
                
            case 7:
                save_to_file(students, student_count);
                printf("Data saved to file successfully!\n");
                break;
                
            case 8:
                printf("Thank you for using Student Database System!\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        if (choice != 8) {
            printf("\nPress Enter to continue...");
            getchar(); // consume newline
            getchar(); // wait for Enter
        }
        
    } while (choice != 8);
    
    return 0;
}

void display_menu(void) {
    printf("\n=== STUDENT DATABASE MENU ===");
    printf("\n1. Add Student");
    printf("\n2. Display All Students");
    printf("\n3. Search Student");
    printf("\n4. Calculate Averages");
    printf("\n5. Display Statistics");
    printf("\n6. Demonstrate Pointer Concepts");
    printf("\n7. Save to File");
    printf("\n8. Exit");
    printf("\n==============================\n");
}

int add_student(Student *students, int *count, char *subjects[]) {
    // Pointer to array demonstration - students points to array of Student structures
    if (*count >= MAX_STUDENTS) {
        return 0; // Database full
    }
    
    // Structure pointer demonstration
    Student *current_student = &students[*count];
    
    printf("\n=== ADD NEW STUDENT ===");
    printf("Enter student ID: ");
    scanf("%d", &current_student->id);
    
    printf("Enter student name: ");
    scanf(" %[^\n]", current_student->name); // Read string with spaces
    
    printf("Enter student age: ");
    scanf("%d", &current_student->age);
    
    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &current_student->num_subjects);
    
    if (current_student->num_subjects > MAX_SUBJECTS) {
        current_student->num_subjects = MAX_SUBJECTS;
    }
    
    // Array of pointers demonstration - accessing subject names
    printf("\nEnter grades for the following subjects:\n");
    for (int i = 0; i < current_student->num_subjects; i++) {
        printf("%s: ", subjects[i]); // Pointer to string demonstration
        scanf("%f", &current_student->grades[i]);
    }
    
    current_student->average = 0; // Will be calculated later
    (*count)++;
    
    return 1; // Success
}

void display_students(Student *students, int count, char *subjects[]) {
    if (count == 0) {
        printf("\nNo students in database.\n");
        return;
    }
    
    printf("\n=== STUDENT LIST ===");
    printf("\n%-5s %-20s %-5s %-10s %s\n", "ID", "Name", "Age", "Average", "Grades");
    printf("----------------------------------------------------------------\n");
    
    // Pointer arithmetic demonstration
    for (int i = 0; i < count; i++) {
        Student *current = students + i; // Pointer arithmetic
        printf("%-5d %-20s %-5d %-10.2f ", 
               current->id, current->name, current->age, current->average);
        
        // Display grades
        for (int j = 0; j < current->num_subjects; j++) {
            printf("%.1f ", current->grades[j]);
        }
        printf("\n");
    }
}

void search_student(Student *students, int count) {
    if (count == 0) {
        printf("\nNo students in database.\n");
        return;
    }
    
    int search_id;
    printf("\nEnter student ID to search: ");
    scanf("%d", &search_id);
    
    // Linear search using structure pointer
    Student *found = NULL;
    for (int i = 0; i < count; i++) {
        if ((students + i)->id == search_id) {
            found = students + i;
            break;
        }
    }
    
    if (found != NULL) {
        printf("\n=== STUDENT FOUND ===");
        printf("\nID: %d", found->id);
        printf("\nName: %s", found->name);
        printf("\nAge: %d", found->age);
        printf("\nAverage: %.2f (%s)", found->average, get_grade_letter(found->average));
        printf("\nGrades: ");
        for (int i = 0; i < found->num_subjects; i++) {
            printf("%.1f ", found->grades[i]);
        }
        printf("\n");
    } else {
        printf("\nStudent with ID %d not found.\n", search_id);
    }
}

void calculate_averages(Student *students, int count) {
    // Pointer to array demonstration
    for (int i = 0; i < count; i++) {
        Student *current = &students[i];
        float sum = 0;
        
        // Pointer to array elements
        float *grades_ptr = current->grades;
        for (int j = 0; j < current->num_subjects; j++) {
            sum += *(grades_ptr + j); // Pointer arithmetic
        }
        
        current->average = (current->num_subjects > 0) ? sum / current->num_subjects : 0;
    }
}

void save_to_file(Student *students, int count) {
    // File operations demonstration
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    // Write count first
    fwrite(&count, sizeof(int), 1, file);
    
    // Write all students
    fwrite(students, sizeof(Student), count, file);
    
    fclose(file);
}

int load_from_file(Student *students) {
    // File operations demonstration
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No existing data file found. Starting with empty database.\n");
        return 0;
    }
    
    int count;
    // Read count
    if (fread(&count, sizeof(int), 1, file) != 1) {
        printf("Error reading file header.\n");
        fclose(file);
        return 0;
    }
    
    // Read all students
    int read_count = fread(students, sizeof(Student), count, file);
    fclose(file);
    
    printf("Loaded %d students from file.\n", read_count);
    return read_count;
}

void display_statistics(Student *students, int count) {
    if (count == 0) {
        printf("\nNo students in database.\n");
        return;
    }
    
    printf("\n=== DATABASE STATISTICS ===");
    printf("\nTotal students: %d", count);
    
    // Calculate overall statistics using pointers
    float total_average = 0;
    float highest_average = students[0].average;
    float lowest_average = students[0].average;
    Student *best_student = &students[0];
    Student *weakest_student = &students[0];
    
    for (int i = 0; i < count; i++) {
        Student *current = students + i;
        total_average += current->average;
        
        if (current->average > highest_average) {
            highest_average = current->average;
            best_student = current;
        }
        
        if (current->average < lowest_average) {
            lowest_average = current->average;
            weakest_student = current;
        }
    }
    
    printf("\nClass average: %.2f", total_average / count);
    printf("\nHighest average: %.2f (%s)", highest_average, best_student->name);
    printf("\nLowest average: %.2f (%s)", lowest_average, weakest_student->name);
    printf("\n");
}

void demonstrate_pointers(Student *students, int count, char *subjects[]) {
    printf("\n=== POINTER CONCEPTS DEMONSTRATION ===");
    
    if (count == 0) {
        printf("\nNo students available for demonstration.\n");
        return;
    }
    
    // 1. Pointer to array demonstration
    printf("\n1. Pointer to Array:");
    Student *ptr_to_array = students; // Points to first element of array
    printf("\n   First student via pointer: %s (ID: %d)", ptr_to_array->name, ptr_to_array->id);
    printf("\n   Second student via pointer arithmetic: %s (ID: %d)", 
           (ptr_to_array + 1)->name, (ptr_to_array + 1)->id);
    
    // 2. Array of pointers demonstration
    printf("\n\n2. Array of Pointers (Subject names):");
    printf("\n   Subject names stored as array of string pointers:");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("\n   subjects[%d] points to: \"%s\" at address: %p", 
               i, subjects[i], (void*)subjects[i]);
    }
    
    // 3. Structure pointer demonstration
    printf("\n\n3. Structure Pointer:");
    Student *struct_ptr = &students[0];
    printf("\n   Accessing via pointer: struct_ptr->name = %s", struct_ptr->name);
    printf("\n   Accessing via dereference: (*struct_ptr).id = %d", (*struct_ptr).id);
    
    // 4. Pointer to string demonstration
    printf("\n\n4. Pointer to String:");
    char *string_ptr = students[0].name;
    printf("\n   String pointer points to: \"%s\"", string_ptr);
    printf("\n   First character via pointer: '%c'", *string_ptr);
    printf("\n   Second character via pointer arithmetic: '%c'", *(string_ptr + 1));
    
    // 5. Pointer arithmetic with grades array
    printf("\n\n5. Pointer Arithmetic with Arrays:");
    float *grades_ptr = students[0].grades;
    printf("\n   Grades via pointer arithmetic:");
    for (int i = 0; i < students[0].num_subjects; i++) {
        printf("\n   Grade %d: %.1f (address: %p)", 
               i + 1, *(grades_ptr + i), (void*)(grades_ptr + i));
    }
    
    printf("\n\n=== End of Pointer Demonstration ===\n");
}

char* get_grade_letter(float grade) {
    // Pointer to string demonstration - returning string literals
    if (grade >= 90) return "A";
    else if (grade >= 80) return "B";
    else if (grade >= 70) return "C";
    else if (grade >= 60) return "D";
    else return "F";
}

