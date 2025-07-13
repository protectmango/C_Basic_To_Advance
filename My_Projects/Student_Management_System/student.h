// student.h
#ifndef STUDENT_H
#define STUDENT_H

// Define the structure for a Student
struct Student {
    int student_id;     
    char name[40]; 
    float avg_marks;
    char batch[10];   
    char stream[50]; 
};

struct Student *create_student(int student_id, const char *name, float avg_marks, const char *batch, const char *stream);

void print_student(const struct Student *student);

#endif // STUDENT_H
