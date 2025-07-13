/*
 Main File 
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "linked_list.h"
#include "file_handler.h"

int main()
{
	struct Node *head = NULL;
	struct Student *new_student = create_student(100, "Gulshan Rana", 82,"v24be8", "Electronic and Communication");

	add_node( &head , new_student );

	display_list(head , (void (*)(const void*))print_student);

	if(save_students_to_csv("student_db.csv", head) != 0)
	{
		fprintf(stderr, "Failed to save students to CSV.\n");
	}

	free_list(&head , free);
}
