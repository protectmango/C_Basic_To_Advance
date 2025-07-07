#include "student_database.h"

int main() {
    printf("=== Student Database System Demo ===\n\n");
    
    // Test 1: Demonstrate file naming with first 6 characters
    printf("Test 1: File naming demonstration\n");
    char batch_ids[][10] = {"v24be8g5", "v24be9x1", "v22be9y2", "v22be5z3"};
    int num_batches = 4;
    
    for (int i = 0; i < num_batches; i++) {
        char* filename = get_batch_filename(batch_ids[i]);
        printf("Batch ID: %s -> File: %s\n", batch_ids[i], filename);
    }
    
    printf("\n");
    
    // Test 2: Check if student exists functionality
    printf("Test 2: Student existence check\n");
    printf("Checking if student v24be8g5 exists: %s\n", 
           check_student_id_exists("v24be8g5") ? "YES" : "NO");
    printf("Checking if student v22be9y2 exists: %s\n", 
           check_student_id_exists("v22be9y2") ? "YES" : "NO");
    
    printf("\n");
    
    // Test 3: Create sample students to demonstrate the system
    printf("Test 3: Creating sample students\n");
    struct st* students = allocate_students(2);
    
    // Student 1
    strcpy(students[0].batch_id, "v24be8g5");
    strcpy(students[0].name, "John Doe");
    students[0].avg_internal_marks = 85.5;
    strcpy(students[0].assessment_status, "r");
    students[0].dob.day = 15;
    students[0].dob.month = 3;
    students[0].dob.year = 2000;
    students[0].doj.day = 10;
    students[0].doj.month = 8;
    students[0].doj.year = 2024;
    
    // Student 2
    strcpy(students[1].batch_id, "v24be9x1");
    strcpy(students[1].name, "Jane Smith");
    students[1].avg_internal_marks = 92.0;
    strcpy(students[1].assessment_status, "r");
    students[1].dob.day = 22;
    students[1].dob.month = 7;
    students[1].dob.year = 2001;
    students[1].doj.day = 10;
    students[1].doj.month = 8;
    students[1].doj.year = 2024;
    
    // Save records
    save_batch_wise_records(students, 2);
    
    printf("\n");
    
    // Test 4: Try to add duplicate student
    printf("Test 4: Attempting to add duplicate student\n");
    struct st* duplicate_student = allocate_students(1);
    strcpy(duplicate_student[0].batch_id, "v24be8g5");
    strcpy(duplicate_student[0].name, "John Doe Duplicate");
    duplicate_student[0].avg_internal_marks = 75.0;
    strcpy(duplicate_student[0].assessment_status, "nr");
    duplicate_student[0].dob.day = 15;
    duplicate_student[0].dob.month = 3;
    duplicate_student[0].dob.year = 2000;
    duplicate_student[0].doj.day = 10;
    duplicate_student[0].doj.month = 8;
    duplicate_student[0].doj.year = 2024;
    
    save_batch_wise_records(duplicate_student, 1);
    
    printf("\n");
    
    // Test 5: Display all records
    printf("Test 5: Displaying all records\n");
    display_all_records();
    
    // Clean up
    free_students(students);
    free_students(duplicate_student);
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}
