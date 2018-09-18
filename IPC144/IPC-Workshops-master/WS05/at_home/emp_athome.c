
// Name: Zhi Zhao
// Student Number:109079178
// Email: zzhao58@mysenaca.ca
// Section: GG
// Date:  June 17, 2018

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 4

struct Employee {
	int id;
	int age;
	double salary;
};

int main(void)
{

	int option = 0, i, empCount = 0, id_update = 0, is_input_valid = 0, id_remove;
	struct Employee emp[SIZE] = { { 0 } };

	printf("---=== EMPLOYEE DATA ===---\n");

	do
	{
		
		printf("\n");
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
	
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	
			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;
		case 1: 
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id > 0)
				{
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			};

			break;
		case 2:
			printf("Adding Employee\n");
			printf("===============\n");
			if (empCount < SIZE)
			{
				printf("Enter Employee ID: ");
				scanf("%d", &emp[empCount].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[empCount].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[empCount].salary);
				empCount++;
			}
			else
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			break;
		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			is_input_valid = 0;
			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &id_update);

				i = 0;
				while (i < SIZE && is_input_valid == 0)
				{
					if (emp[i].id == id_update)
					{
						is_input_valid = 1;

						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
						
					}
					i++;
				}
			} while (is_input_valid == 0);
			break;
		case 4:
			printf("Remove Employee\n");
			printf("===============\n");
			is_input_valid = 0;
			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &id_remove);

				i = 0;
				while (i < SIZE && is_input_valid == 0)
				{
					if (emp[i].id == id_remove)
					{
						is_input_valid = 1;

						printf("Employee %d will be removed\n", id_remove);
						emp[i].id = 0;
						emp[i].age = 0;
						emp[i].salary = 0;
						empCount -= 1;
					}
					i++;
				}
			} while (is_input_valid == 0);
			break;
		default:printf("ERROR: Incorrect Option: Try Again\n");
		}
	}while (option != 0);

	return 0;
}



