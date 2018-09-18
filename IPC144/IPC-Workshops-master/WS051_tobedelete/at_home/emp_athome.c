// Name: Zhi Zhao
// Student Number:109079178
// Email: zzhao58@mysenaca.ca
// Section: GG
// Date:  June 12, 2018

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 4


// Declare Struct Employee 
struct Employee {
	int id;
	int age;
	double salary;
};


/* main program */
int main(void)
{

	int option = 0, i, empCount = 0, id_update = 0, is_input_valid = 0, id_remove;
	struct Employee emp[SIZE] = { { 0 } };


	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero


	printf("---=== EMPLOYEE DATA ===---\n");

	do
	{
		// Print the option list
		printf("\n");
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id > 0)
				{
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			};


			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

			break;
		case 2:
			printf("Adding Employee\n");
			printf("===============\n");
			if (empCount < SIZE)
			{

				// @IN-LAB
				// Adding Employee

				printf("Enter Employee ID: ");
				scanf("%d", &emp[empCount].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[empCount].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[empCount].salary);
				empCount++;

				// Check for limits on the array and add employee 
				// data accordingly. 
			}

			else
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			break;
		case 3:
			printf("Update Employee Information\n");
			printf("===========================\n");
			is_input_valid = 0;
			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &id_update);

				//valid emp_id: update the salary
				i = 0;
				while (i < SIZE && is_input_valid == 0)
				{
					if (emp[i].id == id_update)
					{
						is_input_valid = 1;

						printf("The Current Salary is %lf\n", emp[i].salary);
						printf("Enter Emloyee New Salary: ");
						scanf("%lf", &emp[i].salary);
						printf("\n");
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

						printf("Employee %d will be moved\n", id_remove);
						emp[i].id = 0;
						emp[i].age = 0;
						emp[i].salary = 0;
						empCount -= 1;
					}
					i++;
				}
			} while (is_input_valid == 0);
			break;
		}
	}while (option != 0);

	return 0;
}



