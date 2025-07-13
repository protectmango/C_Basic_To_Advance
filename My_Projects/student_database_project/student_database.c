#include "student_database.h"

// Function to allocate dynamic memory for n students
struct st* allocate_students(int n) {
    struct st* students = (struct st*)malloc(n * sizeof(struct st));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return students;
}

// Function to free allocated memory
void free_students(struct st* students) {
    free(students);
}

// Function to validate date
int validate_date(int day, int month, int year) {
    if (year < 1900 || year > 2100) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;
    
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        days_in_month[1] = 29;
    }
    
    if (day > days_in_month[month - 1]) return 0;
    return 1;
}

// Function to trim whitespace from string
void trim_whitespace(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    
    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n') start++;
    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) end--;
    
    int i;
    for (i = start; i <= end; i++) {
        str[i - start] = str[i];
    }
    str[i - start] = '\0';
}

// Function to get batch filename from first 6 characters of batch_id
char* get_batch_filename(char* batch_id) {
    static char filename[20];
    char batch_prefix[7]; // 6 characters + null terminator
    
    // Extract first 6 characters
    strncpy(batch_prefix, batch_id, 6);
    batch_prefix[6] = '\0';
    
    snprintf(filename, sizeof(filename), "%s.txt", batch_prefix);
    return filename;
}

// Function to check if student batch ID exists
int check_student_exists(char* batch_id) {
    char* filename = get_batch_filename(batch_id);
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        fclose(file);
        return 1;  // File exists
    }
    return 0;  // File does not exist
}

// Function to check if specific student ID already exists in database
int check_student_id_exists(char* batch_id) {
    char* filename = get_batch_filename(batch_id);
    FILE* file = fopen(filename, "rb");
    
    if (file == NULL) {
        return 0;  // File doesn't exist, so student doesn't exist
    }
    
    struct st student;
    while (fread(&student, sizeof(struct st), 1, file) == 1) {
        if (strcmp(student.batch_id, batch_id) == 0) {
            fclose(file);
            return 1;  // Student ID already exists
        }
    }
    
    fclose(file);
    return 0;  // Student ID doesn't exist
}

// Function to add batch to registry
void add_batch_to_registry(char* batch_prefix) {
    // Check if batch is already registered
    if (is_batch_registered(batch_prefix)) {
        return; // Already exists
    }
    
    FILE* file = fopen("student_batch.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s\n", batch_prefix);
        fclose(file);
    }
}

// Function to remove batch from registry
void remove_batch_from_registry(char* batch_prefix) {
    FILE* file = fopen("student_batch.txt", "r");
    if (file == NULL) {
        return; // No registry file exists
    }
    
    char batches[50][7]; // Store batch prefixes (6 chars + null terminator)
    int count = 0;
    char line[20];
    
    // Read all batches except the one to remove
    while (fgets(line, sizeof(line), file) != NULL && count < 50) {
        line[strcspn(line, "\n")] = 0; // Remove newline
        if (strcmp(line, batch_prefix) != 0) {
            strcpy(batches[count], line);
            count++;
        }
    }
    fclose(file);
    
    // Rewrite the file without the removed batch
    file = fopen("student_batch.txt", "w");
    if (file != NULL) {
        int i;
        for (i = 0; i < count; i++) {
            fprintf(file, "%s\n", batches[i]);
        }
        fclose(file);
    }
}

// Function to get all registered batches
void get_registered_batches(char batch_files[][50], int* count) {
    *count = 0;
    FILE* file = fopen("student_batch.txt", "r");
    if (file == NULL) {
        return; // No registry file exists
    }
    
    char line[20];
    while (fgets(line, sizeof(line), file) != NULL && *count < 50) {
        line[strcspn(line, "\n")] = 0; // Remove newline
        snprintf(batch_files[*count], 50, "%s.txt", line);
        (*count)++;
    }
    fclose(file);
}

// Function to check if batch is registered
int is_batch_registered(char* batch_prefix) {
    FILE* file = fopen("student_batch.txt", "r");
    if (file == NULL) {
        return 0; // No registry file exists
    }
    
    char line[20];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0; // Remove newline
        if (strcmp(line, batch_prefix) == 0) {
            fclose(file);
            return 1; // Found
        }
    }
    fclose(file);
    return 0; // Not found
}

// Function to initialize batch registry from existing .txt files (for backward compatibility)
void initialize_batch_registry() {
    FILE* registry_file = fopen("student_batch.txt", "r");
    if (registry_file != NULL) {
        fclose(registry_file);
        return; // Registry already exists
    }
    
    // For backward compatibility, create empty registry file
    // In a real implementation, you would scan directory for .txt files
    // But since we're avoiding popen, we'll create an empty registry
    // that will be populated as students are added
    registry_file = fopen("student_batch.txt", "w");
    if (registry_file != NULL) {
        fclose(registry_file);
    }
}

// Function to get all .txt files from batch registry
void get_all_dat_files(char filenames[][50], int* count) {
    get_registered_batches(filenames, count);
}

// Function to input student data
void input_student_data(struct st* students, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);
        
        printf("Batch ID (e.g., v24be8g5): ");
        if (scanf("%s", students[i].batch_id) != 1) {
            printf("Error reading batch ID\n");
        }
        
        printf("Full Name: ");
        if (scanf(" %[^\n]", students[i].name) != 1) {
            printf("Error reading name\n");
        }
        
        printf("Average Internal Marks (0-100): ");
        if (scanf("%f", &students[i].avg_internal_marks) != 1) {
            printf("Error reading marks\n");
        }
        
        printf("Assessment Status (r/nr): ");
        if (scanf("%s", students[i].assessment_status) != 1) {
            printf("Error reading assessment status\n");
        }
        
        do {
            printf("Date of Birth (DD MM YYYY): ");
            if (scanf("%d %d %d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year) != 3) {
                printf("Error reading date of birth\n");
            }
        } while (!validate_date(students[i].dob.day, students[i].dob.month, students[i].dob.year));
        
        do {
            printf("Date of Joining (DD MM YYYY): ");
            if (scanf("%d %d %d", &students[i].doj.day, &students[i].doj.month, &students[i].doj.year) != 3) {
                printf("Error reading date of joining\n");
            }
        } while (!validate_date(students[i].doj.day, students[i].doj.month, students[i].doj.year));
        
        printf("Student %d data entered successfully!\n", i + 1);
    }
}

// Function to save batch wise records in separate files
void save_batch_wise_records(struct st* students, int n) {
    char batch_ids[50][10];
    int batch_count = 0;
    int i, j;
    
    // Get unique batch IDs
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < batch_count; j++) {
            if (strcmp(students[i].batch_id, batch_ids[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(batch_ids[batch_count], students[i].batch_id);
            batch_count++;
        }
    }
    
    // Save records for each batch
    for (i = 0; i < batch_count; i++) {
        char* filename = get_batch_filename(batch_ids[i]);
        FILE* file = fopen(filename, "ab");  // Use append mode to add to existing files
        
        if (file == NULL) {
            printf("Error creating/opening file %s\n", filename);
            continue;
        }
        
        // Write all students of this batch
        int records_written = 0;
        for (j = 0; j < n; j++) {
            if (strcmp(students[j].batch_id, batch_ids[i]) == 0) {
                // Check if student ID already exists
                if (!check_student_id_exists(students[j].batch_id)) {
                    if (fwrite(&students[j], sizeof(struct st), 1, file) == 1) {
                        records_written++;
                    } else {
                        printf("Error writing student record to file %s\n", filename);
                    }
                } else {
                    printf("Student ID %s already exists in file %s; skipping.\n", students[j].batch_id, filename);
                }
            }
        }
        
        fclose(file);
        
        // Register the batch if records were written
        if (records_written > 0) {
            char batch_prefix[7];
            strncpy(batch_prefix, batch_ids[i], 6);
            batch_prefix[6] = '\0';
            add_batch_to_registry(batch_prefix);
        }
        
        printf("Successfully saved %d record(s) for batch %s in file %s\n", 
               records_written, batch_ids[i], filename);
    }
}

// Function to display a student record
void display_student(struct st student) {
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║                    Student Details                       ║\n");
    printf("╠══════════════════════════════════════════════════════════╣\n");
    printf("║ %-20s : %-33s ║\n", "Batch ID", student.batch_id);
    printf("║ %-20s : %-33s ║\n", "Name", student.name);
    printf("║ %-20s : %-33.2f ║\n", "Average Marks", student.avg_internal_marks);
    printf("║ %-20s : %-33s ║\n", "Assessment Status", student.assessment_status);
    printf("║ %-20s : %02d/%02d/%-27d ║\n", "Date of Birth", student.dob.day, student.dob.month, student.dob.year);
    printf("║ %-20s : %02d/%02d/%-27d ║\n", "Date of Joining", student.doj.day, student.doj.month, student.doj.year);
    printf("╚══════════════════════════════════════════════════════════╝\n");
}

// Function to search by join date
void search_by_join_date(int day, int month, int year) {
    printf("\n--- Searching by Join Date: %02d/%02d/%d ---\n", day, month, year);
    
    FILE* file;
    struct st student;
    int found = 0;
    
    // Get all .txt files dynamically
    char batch_files[50][50];
    int file_count;
    get_all_dat_files(batch_files, &file_count);
    
    int i;
    for (i = 0; i < file_count; i++) {
        file = fopen(batch_files[i], "rb");
        if (file != NULL) {
            while (fread(&student, sizeof(struct st), 1, file) == 1) {
                if (student.doj.day == day && student.doj.month == month && student.doj.year == year) {
                    display_student(student);
                    found = 1;
                }
            }
            fclose(file);
        }
    }
    
    if (!found) {
        printf("No students found with join date %02d/%02d/%d\n", day, month, year);
    }
}

// Function to search by birth date
void search_by_birth_date(int day, int month, int year) {
    printf("\n--- Searching by Birth Date: %02d/%02d/%d ---\n", day, month, year);
    
    FILE* file;
    struct st student;
    int found = 0;
    
    // Get all .txt files dynamically
    char batch_files[50][50];
    int file_count;
    get_all_dat_files(batch_files, &file_count);
    
    int i;
    for (i = 0; i < file_count; i++) {
        file = fopen(batch_files[i], "rb");
        if (file != NULL) {
            while (fread(&student, sizeof(struct st), 1, file) == 1) {
                if (student.dob.day == day && student.dob.month == month && student.dob.year == year) {
                    display_student(student);
                    found = 1;
                }
            }
            fclose(file);
        }
    }
    
    if (!found) {
        printf("No students found with birth date %02d/%02d/%d\n", day, month, year);
    }
}

// Function to search by name
void search_by_name(char* name) {
    printf("\n--- Searching by Name: %s ---\n", name);
    
    FILE* file;
    struct st student;
    int found = 0;
    
    // Convert search name to lowercase for comparison
    char lower_name[50];
    int i;
    for (i = 0; name[i] && i < 49; i++) {
        lower_name[i] = tolower(name[i]);
    }
    lower_name[i] = '\0';
    
    // Get all .dat files dynamically
    char batch_files[50][50];
    int file_count;
    get_all_dat_files(batch_files, &file_count);
    
    for (i = 0; i < file_count; i++) {
        file = fopen(batch_files[i], "rb");
        if (file != NULL) {
            while (fread(&student, sizeof(struct st), 1, file) == 1) {
                // Convert student name to lowercase for comparison
                char lower_student_name[50];
                int j;
                for (j = 0; student.name[j] && j < 49; j++) {
                    lower_student_name[j] = tolower(student.name[j]);
                }
                lower_student_name[j] = '\0';
                
                if (strcmp(lower_student_name, lower_name) == 0) {
                    display_student(student);
                    found = 1;
                }
            }
            fclose(file);
        }
    }
    
    if (!found) {
        printf("No student found with name: %s\n", name);
    }
}

// Function to search by batch ID
void search_by_batch_id(char* batch_id) {
    printf("\n--- Searching by Student ID: %s ---\n", batch_id);
    
    char* filename = get_batch_filename(batch_id);
    FILE* file = fopen(filename, "rb");
    
    if (file == NULL) {
        printf("No records found for batch containing ID %s\n", batch_id);
        return;
    }
    
    struct st student;
    int found = 0;
    
    while (fread(&student, sizeof(struct st), 1, file) == 1) {
        if (strcmp(student.batch_id, batch_id) == 0) {
            display_student(student);
            found = 1;
            break;
        }
    }
    
    fclose(file);
    
    if (!found) {
        printf("No student found with ID %s\n", batch_id);
    }
}

// Function to edit student record
void edit_student_record(char* batch_prefix) {
    
    FILE* file = fopen("student_batch.txt", "r");
    if (file == NULL) {
        printf("No registered batches found!\n");
        return;
    }
    
    char batch_id[10];
    int found = 0;
    while (fscanf(file, "%s", batch_id) != EOF) {
        if (strncmp(batch_id, batch_prefix, strlen(batch_prefix)) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);
    
    if (!found) {
        printf("No batch found with prefix %s\n", batch_prefix);
        return;
    }
    
    char* filename = get_batch_filename(batch_id);
    file = fopen(filename, "rb");
    
    if (file == NULL) {
        printf("No records found for batch %s\n", batch_id);
        return;
    }
    
    struct st students[100];
    int count = 0;
    
    // Read all students from the file
    while (fread(&students[count], sizeof(struct st), 1, file) == 1) {
        count++;
    }
    fclose(file);
    
    if (count == 0) {
        printf("No students found in batch %s\n", batch_id);
        return;
    }
    
    // Display all students in the batch with IDs
    printf("\n--- Students in batch %s ---\n", batch_id);
    printf("%-4s %-12s : %-30s\n", "No.", "Student ID", "Name");
    printf("%-4s %-12s   %-30s\n", "---", "----------", "----");
    int i;
    for (i = 0; i < count; i++) {
        printf("%-4d %-12s : %-30s\n", i + 1, students[i].batch_id, students[i].name);
    }
    
    int choice;
    printf("Enter student number to edit (1-%d): ", count);
    if (scanf("%d", &choice) != 1) {
        printf("Error reading choice\n");
        return;
    }
    
    if (choice < 1 || choice > count) {
        printf("Invalid choice!\n");
        return;
    }
    
    choice--; // Convert to 0-based index
    
    printf("\nCurrent details:\n");
    display_student(students[choice]);
    
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║           What would you like to edit?                   ║\n");
    printf("╠══════════════════════════════════════════════════════════╣\n");
    printf("║  1. Name                                                 ║\n");
    printf("║  2. Average Internal Marks                               ║\n");
    printf("║  3. Assessment Status                                    ║\n");
    printf("║  4. Date of Birth                                        ║\n");
    printf("║  5. Date of Joining                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n");
    printf("Enter your choice: ");
    
    int edit_choice;
    if (scanf("%d", &edit_choice) != 1) {
        printf("Error reading edit choice\n");
        return;
    }
    
    switch (edit_choice) {
        case 1:
            printf("Enter new name: ");
            if (scanf(" %[^\n]", students[choice].name) != 1) {
                printf("Error reading name\n");
            }
            break;
        case 2:
            printf("Enter new average internal marks: ");
            if (scanf("%f", &students[choice].avg_internal_marks) != 1) {
                printf("Error reading marks\n");
            }
            break;
        case 3:
            printf("Enter new assessment status: ");
            if (scanf("%s", students[choice].assessment_status) != 1) {
                printf("Error reading assessment status\n");
            }
            break;
        case 4:
            do {
                printf("Enter new date of birth (DD MM YYYY): ");
                if (scanf("%d %d %d", &students[choice].dob.day, &students[choice].dob.month, &students[choice].dob.year) != 3) {
                    printf("Error reading date of birth\n");
                }
            } while (!validate_date(students[choice].dob.day, students[choice].dob.month, students[choice].dob.year));
            break;
        case 5:
            do {
                printf("Enter new date of joining (DD MM YYYY): ");
                if (scanf("%d %d %d", &students[choice].doj.day, &students[choice].doj.month, &students[choice].doj.year) != 3) {
                    printf("Error reading date of joining\n");
                }
            } while (!validate_date(students[choice].doj.day, students[choice].doj.month, students[choice].doj.year));
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    // Write back to file
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error updating file!\n");
        return;
    }
    
    fwrite(students, sizeof(struct st), count, file);
    fclose(file);
    
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║         Record updated successfully!                     ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n");
}

// Function to search by marks range
void search_by_marks_range(float min_marks, float max_marks) {
    printf("\n--- Searching by Marks Range: %.2f - %.2f ---\n", min_marks, max_marks);
    
    FILE* file;
    struct st student;
    int found = 0;
    
    // Get all .txt files dynamically
    char batch_files[50][50];
    int file_count;
    get_all_dat_files(batch_files, &file_count);
    
    int i;
    for (i = 0; i < file_count; i++) {
        file = fopen(batch_files[i], "rb");
        if (file != NULL) {
            while (fread(&student, sizeof(struct st), 1, file) == 1) {
                if (student.avg_internal_marks >= min_marks && student.avg_internal_marks <= max_marks) {
                    display_student(student);
                    found = 1;
                }
            }
            fclose(file);
        }
    }
    
    if (!found) {
        printf("No students found with marks in range %.2f - %.2f\n", min_marks, max_marks);
    }
}

// Function to search by assessment status
void search_by_assessment_status(char* status) {
    printf("\n--- Searching by Assessment Status: %s ---\n", status);
    
    FILE* file;
    struct st student;
    int found = 0;
    
    // Convert search status to lowercase for comparison
    char lower_status[5];
    int i;
    for (i = 0; status[i] && i < 4; i++) {
        lower_status[i] = tolower(status[i]);
    }
    lower_status[i] = '\0';
    
    // Get all .txt files dynamically
    char batch_files[50][50];
    int file_count;
    get_all_dat_files(batch_files, &file_count);
    
    for (i = 0; i < file_count; i++) {
        file = fopen(batch_files[i], "rb");
        if (file != NULL) {
            while (fread(&student, sizeof(struct st), 1, file) == 1) {
                // Convert student assessment status to lowercase for comparison
                char lower_student_status[5];
                int j;
                for (j = 0; student.assessment_status[j] && j < 4; j++) {
                    lower_student_status[j] = tolower(student.assessment_status[j]);
                }
                lower_student_status[j] = '\0';
                
                if (strcmp(lower_student_status, lower_status) == 0) {
                    display_student(student);
                    found = 1;
                }
            }
            fclose(file);
        }
    }
    
    if (!found) {
        printf("No students found with assessment status: %s\n", status);
    }
}

// Function to display records from a specific batch
void display_batch_records(char* batch_prefix) {
    printf("\n--- Records for Batch: %s ---\n", batch_prefix);
    
    char filename[20];
    snprintf(filename, sizeof(filename), "%s.txt", batch_prefix);
    
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No records found for batch %s\n", batch_prefix);
        return;
    }
    
    struct st student;
    int found = 0;
    int count = 0;
    
    // First, display header
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║                    Batch: %-27s    ║\n", batch_prefix);
    printf("╚══════════════════════════════════════════════════════════╝\n");
    
    while (fread(&student, sizeof(struct st), 1, file) == 1) {
        printf("\n[Student %d]\n", ++count);
        display_student(student);
        found = 1;
    }
    
    fclose(file);
    
    if (!found) {
        printf("No students found in batch %s\n", batch_prefix);
    } else {
        printf("\n╔══════════════════════════════════════════════════════════╗\n");
        printf("║              Total Students: %-24d    ║\n", count);
        printf("╚══════════════════════════════════════════════════════════╝\n");
    }
}

// Function to display all records with batch selection option
void display_all_records() {
    char input[20];
    
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║                    Display Records                       ║\n");
    printf("╠══════════════════════════════════════════════════════════╣\n");
    printf("║  Enter batch prefix (e.g., v24be8) or 'all' for all:     ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n");
    printf("Choice: ");
    
    if (scanf("%s", input) != 1) {
        printf("Error reading input!\n");
        return;
    }
    
    // Convert to lowercase for comparison
    int i;
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }
    
    if (strcmp(input, "all") == 0) {
        // Display all records
        printf("\n╔══════════════════════════════════════════════════════════╗\n");
        printf("║                    All Student Records                   ║\n");
        printf("╚══════════════════════════════════════════════════════════╝\n");
        
        FILE* file;
        struct st student;
        int found = 0;
        int total_students = 0;
        
        // Get all registered batch files
        char batch_files[50][50];
        int file_count;
        get_registered_batches(batch_files, &file_count);
        
        if (file_count == 0) {
            printf("No records found in the database.\n");
            return;
        }
        
        for (i = 0; i < file_count; i++) {
            file = fopen(batch_files[i], "rb");
            if (file != NULL) {
                // Extract batch name from filename
                char batch_name[20];
                strcpy(batch_name, batch_files[i]);
                char* dot = strrchr(batch_name, '.');
                if (dot != NULL) {
                    *dot = '\0';
                }
                
                printf("\n╔══════════════════════════════════════════════════════════╗\n");
                printf("║                    Batch: %-27s    ║\n", batch_name);
                printf("╚══════════════════════════════════════════════════════════╝\n");
                
                int batch_found = 0;
                int batch_count = 0;
                while (fread(&student, sizeof(struct st), 1, file) == 1) {
                    printf("\n[Student %d]\n", ++batch_count);
                    display_student(student);
                    found = 1;
                    batch_found = 1;
                    total_students++;
                }
                
                if (!batch_found) {
                    printf("No records in this batch file.\n");
                } else {
                    printf("\n╔══════════════════════════════════════════════════════════╗\n");
                    printf("║              Batch Total: %-23d        ║\n", batch_count);
                    printf("╚══════════════════════════════════════════════════════════╝\n");
                }
                fclose(file);
            }
        }
        
        if (!found) {
            printf("No records found in the database.\n");
        } else {
            printf("\n╔══════════════════════════════════════════════════════════╗\n");
            printf("║              Total Students: %-24d    ║\n", total_students);
            printf("╚══════════════════════════════════════════════════════════╝\n");
        }
    } else {
        // Display specific batch records
        display_batch_records(input);
    }
}

// Function to delete a specific student by batch ID
void delete_student_by_batch_id(char* batch_id) {
    printf("\n--- Delete Student by Batch ID: %s ---\n", batch_id);
    
    char* filename = get_batch_filename(batch_id);
    FILE* file = fopen(filename, "rb");
    
    if (file == NULL) {
        printf("No records found for batch %s\n", batch_id);
        return;
    }
    
    struct st students[100];
    int count = 0;
    int found = 0;
    int student_index = -1;
    
    // Read all students from the file
    while (fread(&students[count], sizeof(struct st), 1, file) == 1) {
        if (strcmp(students[count].batch_id, batch_id) == 0) {
            found = 1;
            student_index = count;
        }
        count++;
    }
    fclose(file);
    
    if (!found) {
        printf("No student found with batch ID: %s\n", batch_id);
        return;
    }
    
    // Display the student to be deleted
    printf("\nStudent to be deleted:\n");
    display_student(students[student_index]);
    
    // Confirm deletion
    char confirm;
    printf("\nAre you sure you want to delete this student? (y/n): ");
    if (scanf(" %c", &confirm) != 1) {
        printf("Error reading confirmation!\n");
        return;
    }
    
    if (confirm != 'y' && confirm != 'Y') {
        printf("Deletion cancelled.\n");
        return;
    }
    
    // Remove the student from the array by shifting elements
    int i;
    for (i = student_index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    
    // Write the updated array back to the file
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error updating file!\n");
        return;
    }
    
    if (count > 0) {
        fwrite(students, sizeof(struct st), count, file);
        printf("Student with batch ID %s deleted successfully!\n", batch_id);
    } else {
        printf("Student with batch ID %s deleted successfully!\n", batch_id);
        printf("Batch file %s is now empty.\n", filename);
    }
    
    fclose(file);
    
    // If the file is empty, optionally remove it
    if (count == 0) {
        char choice;
        printf("Do you want to remove the empty batch file %s? (y/n): ", filename);
        if (scanf(" %c", &choice) != 1) {
            printf("Error reading choice!\n");
            return;
        }
        if (choice == 'y' || choice == 'Y') {
            if (remove(filename) == 0) {
                printf("Empty batch file %s removed successfully.\n", filename);
                // Remove from batch registry
                char batch_prefix[7];
                strncpy(batch_prefix, batch_id, 6);
                batch_prefix[6] = '\0';
                remove_batch_from_registry(batch_prefix);
            } else {
                printf("Error removing empty batch file %s.\n", filename);
            }
        }
    }
}

// Function to delete all students from a specific batch
void delete_all_students_by_batch(char* batch_prefix) {
    printf("\n--- Delete All Students by Batch: %s ---\n", batch_prefix);
    
    char filename[20];
    snprintf(filename, sizeof(filename), "%s.txt", batch_prefix);
    
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No records found for batch %s\n", batch_prefix);
        return;
    }
    
    // Count and display all students in the batch
    struct st student;
    int count = 0;
    printf("\nStudents in batch %s:\n", batch_prefix);
    printf("%-4s %-12s : %-30s\n", "No.", "Student ID", "Name");
    printf("%-4s %-12s   %-30s\n", "---", "----------", "----");
    
    while (fread(&student, sizeof(struct st), 1, file) == 1) {
        printf("%-4d %-12s : %-30s\n", count + 1, student.batch_id, student.name);
        count++;
    }
    fclose(file);
    
    if (count == 0) {
        printf("No students found in batch %s\n", batch_prefix);
        return;
    }
    
    printf("\nTotal students to be deleted: %d\n", count);
    
    // Confirm deletion
    char confirm;
    printf("\nAre you sure you want to delete ALL students from batch %s? (y/n): ", batch_prefix);
    if (scanf(" %c", &confirm) != 1) {
        printf("Error reading confirmation!\n");
        return;
    }
    
    if (confirm != 'y' && confirm != 'Y') {
        printf("Deletion cancelled.\n");
        return;
    }
    
    // Delete the entire batch file
    if (remove(filename) == 0) {
        printf("All %d students from batch %s deleted successfully!\n", count, batch_prefix);
        printf("Batch file %s removed.\n", filename);
        // Remove from batch registry
        remove_batch_from_registry(batch_prefix);
    } else {
        printf("Error deleting batch file %s.\n", filename);
    }
}

// Function to display menu
void display_menu() {
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║           Student Database Management System             ║\n");
    printf("╠══════════════════════════════════════════════════════════╣\n");
    printf("║  1.  Add new students                                    ║\n");
    printf("║  2.  Search by join date                                 ║\n");
    printf("║  3.  Search by birth date                                ║\n");
    printf("║  4.  Search by name                                      ║\n");
    printf("║  5.  Search by student ID                                ║\n");
    printf("║  6.  Edit student record                                 ║\n");
    printf("║  7.  Search by marks range                               ║\n");
    printf("║  8.  Search by assessment status                         ║\n");
    printf("║  9.  Display all records                                 ║\n");
    printf("║  10. Delete student by batch ID                          ║\n");
    printf("║  11. Delete all students by batch                        ║\n");
    printf("║  12. Exit                                                ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n");
    printf("Enter your choice: ");
}
