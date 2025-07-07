#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Date structure
struct date {
    int day;
    int month;
    int year;
};

// Student structure
struct st {
    char batch_id[10];              // v24be8g5
    char name[50];                  // full name
    float avg_internal_marks;       // 70%
    char assessment_status[5];      // r nr
    struct date dob;                // date of birth
    struct date doj;                // date of joining
};

// Function declarations
struct st* allocate_students(int n);
void free_students(struct st* students);
void input_student_data(struct st* students, int n);
void save_batch_wise_records(struct st* students, int n);
void search_by_join_date(int day, int month, int year);
void search_by_birth_date(int day, int month, int year);
void search_by_name(char* name);
void search_by_batch_id(char* batch_id);
void edit_student_record(char* batch_id);
void search_by_marks_range(float min_marks, float max_marks);
void search_by_assessment_status(char* status);
void display_all_records();
void display_student(struct st student);
void display_menu();
int validate_date(int day, int month, int year);
void trim_whitespace(char* str);
char* get_batch_filename(char* batch_id);
void get_all_dat_files(char filenames[][50], int* count);
int check_student_exists(char* batch_id);
int check_student_id_exists(char* batch_id);
void delete_student_by_batch_id(char* batch_id);
void delete_all_students_by_batch(char* batch_prefix);
void add_batch_to_registry(char* batch_prefix);
void remove_batch_from_registry(char* batch_prefix);
void get_registered_batches(char batch_files[][50], int* count);
int is_batch_registered(char* batch_prefix);
void initialize_batch_registry();

#endif
