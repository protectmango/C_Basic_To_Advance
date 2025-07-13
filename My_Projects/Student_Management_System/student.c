//student.c

#include "student.h"
#include <stdlib.h> // For malloc
#include <string.h> // For strcpy and strncpy
#include <stdio.h>  // For printf

struct Student *create_student( int student_id, const char *name, float avg_marks, const char *batch, const char *stream)
{
	struct Student *s = (struct Student *)malloc(sizeof(struct Student));
	
	if(s == NULL)
	{
		perror("Memory Allocation failed for Student");  // this is a better approach for printing system error
		return NULL;
	}

	s->student_id = student_id;
	s->avg_marks = avg_marks;

	//To prevent buffer overflow we should prefer strncpy
	
	strncpy(s->name , name , sizeof(s->name) -1 );
	s->name[sizeof(s->name) - 1] = '\0'; // Ensure null-termination

	strncpy(s->batch , batch , sizeof(s->batch) -1 );
	s->batch[sizeof(s->batch) - 1] = '\0'; // Ensure null-termination
	
	strncpy(s->stream , stream, sizeof(s->stream) -1 );
	s->stream[sizeof(s->stream) - 1] = '\0'; // Ensure null-termination

	return s;

}

void print_student(const struct Student *student)
{
	if(student == NULL)
	{
		printf("Error : Cannot print NULL student data.\n");
		return ;
	}

	printf("------------------------------------------------\n");
	printf("Student ID  : %d\n", student->student_id);
	printf("Name        : %s\n", student->name);
	printf("Avg Marks   : %.2f\n", student->avg_marks); // .2f for 2 decimal places
	printf("Batch       : %s\n", student->batch);
	printf("Stream      : %s\n", student->stream);
	printf("------------------------------------------------\n");
}
