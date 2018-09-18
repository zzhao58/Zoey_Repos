#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 2
struct Employees
{	int id;
	int age;
	double salary;
};

int main()
{
	struct employees emp[SIZE] = {0};
	int option, i, valid_count;
		
	printf("---=== EMPLOYEE DATA ===---");
	printf("\n");
	printf("1. Display Employee Information\n");
	printf("2. Add Employee");
	printf("0. Exit");
	printf("\n");
	printf("Please select from the above options: ");
	scanf("%d", &option);

	switch (option)
	{
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!");
			break;
		case 1:
			i = 0;
			while (emp[i].id > 0&& i<SIZE)
			{
				printf("%6d%9d%11.21f", emp[i].id, emp[i].age, emp[i].salary);
				printf("\n");
				i++;
			}
			break;
		case 2: 
			i = 0;

			while(emp[i].id > 0 && i<SIZE)
			{	
				i++;
			}
			// i represent the number of valid employees
			if (i == SIZE)
			{
				//print full
			}
			else 
			{	
				//add a new employee
			}

	}


	return 0;
}

