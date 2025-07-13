#include "student_database.h"

int main()
{
	int choice;

	int n;
	struct st* students = NULL;
	
	printf("\tStudent Database\n");

	while(1)
	{
		diplay_menu();
		scanf("%d", &choice);

		switch (choice)
		{
			case 1 : {
					 printf("Enter number of students to add :");
					 scanf("%d", &n);

					 if(n<=0)
					 {
						 printf("Invalid number of students\n");
						 break;
					 }
					// allocated dynamic memory to students
					 students  = allocated_students(n);

					 // input student data
					 input_student_data(students , n);

					// save batch wise records in separate files 
					save_batch_wise_records(students, n);

					// Free allocated memory
					free_students(students);
					students = NULL;

					printf("ALl students added successfully\n");
					break;
				 }
		}	
	}
	
}

