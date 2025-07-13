#include<stdio.h>
#include<stdlib.h>

struct date {
	int day;
	int month;
	int year;
};

struct student {
	char batch_id[10]; 		// v24be8g5
	char name[50];
	float avg_internal_marks;
	char assessment_status[3];
	struct date dob;		// date of birth
	struct date doj; 		// date of joining
};


struct student* allocate_students(int n);
void input_student_data(struct student *s, int n);
int valid_date(int day, int month, int year);


