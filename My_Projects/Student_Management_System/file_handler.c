/*
 * file_handler.c
 */

#include "file_handler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int save_students_to_csv( const char *filename, const struct Node *head)
{
	FILE *file  = fopen(filename , "w");

	if(file == NULL)
	{
		perror("Error opening file for writing.");
		return 1;
	}

	fprintf(file, "student_id,name,avg_marks,batch,stream\n");

	const struct Node *current = head;

	while(current != NULL)
	{
		const struct Student *student = (const struct Student *)current->data;
		fprintf(file, "%d,%s,%.2f,%s,%s\n",
				student->student_id, 
				student->name, 
				student->avg_marks, 
				student->batch, 
				student->stream);

		current = current->next; // move to next node
	}	
	
	fclose(file);
	printf("Student data successfully saved to '%s'\n", filename);
	return 0;
}
