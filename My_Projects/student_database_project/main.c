#include "student_database.h"

int main() {
    int choice;
    int n;
    struct st* students = NULL;
    
    // Initialize batch registry from existing files (for backward compatibility)
    initialize_batch_registry();
    
    printf("Welcome to Student Database Management System!\n");
    
    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input or end of input reached. Exiting...\n");
            break;
        }
        
        switch (choice) {
            case 1: {
                printf("Enter number of students to add: ");
                if (scanf("%d", &n) != 1) {
                    printf("Error reading number of students!\n");
                }
                
                
                if (n <= 0) {
                    printf("Invalid number of students!\n");
                    break;
                }
                
                // Allocate dynamic memory for n students
                students = allocate_students(n);
                
                // Input student data
                input_student_data(students, n);
                
                // Save batch wise records in separate files
                save_batch_wise_records(students, n);
                
                // Free allocated memory
                free_students(students);
                students = NULL;
                
                printf("All students added successfully!\n");
                break;
            }
            
            case 2: {
                int day, month, year;
                printf("Enter join date (DD MM YYYY): ");
                if (scanf("%d %d %d", &day, &month, &year) != 3) {
                    printf("Error reading join date!\n");
                }
                
                if (!validate_date(day, month, year)) {
                    printf("Invalid date!\n");
                    break;
                }
                
                search_by_join_date(day, month, year);
                break;
            }
            
            case 3: {
                int day, month, year;
                printf("Enter birth date (DD MM YYYY): ");
                if (scanf("%d %d %d", &day, &month, &year) != 3) {
                    printf("Error reading birth date!\n");
                }
                
                if (!validate_date(day, month, year)) {
                    printf("Invalid date!\n");
                    break;
                }
                
                search_by_birth_date(day, month, year);
                break;
            }
            
            case 4: {
                char name[50];
                printf("Enter student name: ");
                if (scanf(" %[^\n]", name) != 1) {
                    printf("Error reading name!\n");
                }
                search_by_name(name);
                break;
            }
            
            case 5: {
                char batch_id[10];
                printf("Enter student ID: ");
                if (scanf("%s", batch_id) != 1) {
                    printf("Error reading student ID!\n");
                }
                search_by_batch_id(batch_id);
                break;
            }
            
            case 6: {
                char batch_prefix[7];
                printf("Enter batch prefix (first 6 characters, e.g., v24be8): ");
                if (scanf("%s", batch_prefix) != 1) {
                    printf("Error reading batch prefix!\n");
                }
                edit_student_record(batch_prefix);
                break;
            }
            
            case 7: {
                float min_marks, max_marks;
                printf("Enter minimum marks: ");
                if (scanf("%f", &min_marks) != 1) {
                    printf("Error reading minimum marks!\n");
                }
                printf("Enter maximum marks: ");
                if (scanf("%f", &max_marks) != 1) {
                    printf("Error reading maximum marks!\n");
                }
                
                if (min_marks < 0 || max_marks > 100 || min_marks > max_marks) {
                    printf("Invalid marks range!\n");
                    break;
                }
                
                search_by_marks_range(min_marks, max_marks);
                break;
            }
            
            case 8: {
                char status[5];
                printf("Enter assessment status (r/nr): ");
                if (scanf("%s", status) != 1) {
                    printf("Error reading assessment status!\n");
                }
                search_by_assessment_status(status);
                break;
            }
            
            case 9: {
                display_all_records();
                break;
            }
            
            case 10: {
                char batch_id[10];
                printf("Enter batch ID of student to delete: ");
                if (scanf("%s", batch_id) != 1) {
                    printf("Error reading batch ID!\n");
                }
                delete_student_by_batch_id(batch_id);
                break;
            }
            
            case 11: {
                char batch_prefix[7];
                printf("Enter batch prefix (first 6 characters, e.g., v24be8): ");
                if (scanf("%s", batch_prefix) != 1) {
                    printf("Error reading batch prefix!\n");
                }
                delete_all_students_by_batch(batch_prefix);
                break;
            }
            
            case 12: {
                printf("Thank you for using Student Database Management System!\n");
                printf("Goodbye!\n");
                exit(0);
            }
            
            default: {
                printf("Invalid choice! Please enter a number between 1-12.\n");
                break;
            }
        }
        
        printf("\nPress Enter to continue...");
        // Clear input buffer first
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        // Now wait for Enter (or EOF)
        if ((c = getchar()) == EOF) {
            printf("\nEnd of input reached. Exiting...\n");
            break;
        }
    }
    
    return 0;
}
