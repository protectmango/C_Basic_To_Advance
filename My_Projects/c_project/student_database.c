#include "student_database.h"

struct student* allocate_students(int n){
	struct student *p = (struct student *)malloc(sizeof(struct student) * n);
	
	if(p == NULL){
		printf("Memory allocation failed !\n");
		exit(1);
	}
	return p;
}

void input_student_data(struct student *s, int n)
{
	int i;

	for(i = 0 ; i< n; i++)
	{
		printf("\nEnter details for student %d \n", i+1);

		printf("Batch ID (Eg : v24be8g5) : ");
		scanf("%s", s[i].batch_id);

		printf("Full Name : ");
		scanf("%[^\n]", s[i].name);

		printf("Average Inter Marks (0-100) : ");
		scanf("%f", &s[i].avg_internal_marks);

		printf("Assessment Status \n r : recommended \n nr : not recommended \n Enter : ");
		scanf("%s", s[i].assessment_status);

		do{
			printf("Date of Birth (DD MM YYYY ) : ");
			scanf("%d %d %d", &s[i].dob.day, &s[i].dob.month, &s[i].dob.year);
		}while(!valid_date(s[i].dob.day, s[i].dob.month, s[i].dob.year));

		do{
			printf("Date of Joining (DD MM YYYY ) : ");
			scanf("%d %d %d", &s[i].doj.day , &s[i].doj.month, &s[i].doj.year);
		}while(!valid_date(s[i].dob.day, s[i].dob.month, s[i].dob.year));

		printf("Student %d data entered Successfully \n", i + 1);
	}
}

// Check for valid date
int  valid_date(int day, int month, int year)
{
	if(year < 1900 || year > 2100)	return 0;
	if(month < 1 || month > 12) return 0;
	if(day < 1 || day > 31) return 0;

	int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	// leap year
	
	if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))){
		days_in_month[1] = 29;
	}

	if(day > days[month - 1]) return 0;

	return 1;
}


// To save batch wise records in seperate file
void save_batch_wise_records(struct student *s, int n)
{
	char batch_ids[50][10]; //assumming there are could be 50 students in  a single batch
	int batch_count = 0;
	int i,j;
	
}
