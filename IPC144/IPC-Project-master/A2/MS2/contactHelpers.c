/* -------------------------------------------
Name:  zhi zhao         
Student number: 109079178
Email:          zzhao58@senecacollege.ca
Section:        GG
Date:         July 24, 2018  
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	char NL = 'x';
	int Value;

	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");	
		}
	}
	return Value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min_number, int max_number)
{	
	int Value;
	
	Value = getInt();
	while (min_number>Value || Value>max_number) 
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min_number, max_number);
		Value = getInt();
	}
	return Value;
}

// yes function definition goes here:
int yes(void)
{	
	char option, NL='x';

	do{
		scanf("%c%c", &option, &NL);
		if(!(option == 'Y' || option == 'y' || option == 'N' || option == 'n') || NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	}while(!(option == 'Y' || option == 'y' || option == 'N' || option == 'n') || NL != '\n');

	if (option == 'Y' || option == 'y')
		return 1;
	else
		return 0;
}

// menu function definition goes here:
int menu(void)
{
	int option;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	option = getIntInRange(0, 6);
	return option;
}

// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void)
{ 
	int option, display_menu;
	
	display_menu = 1;
	while (display_menu == 1)
	{
		option = menu();
		switch (option)
		{
			case 1: 
				printf("\n<<< Feature 1 is unavailable >>>\n\n");
				pause();
				printf("\n");
				display_menu = 1;
				break;
			case 2: 
				printf("\n<<< Feature 2 is unavailable >>>\n\n");
				pause();
				printf("\n");
				display_menu = 1;
				break;
			case 3: 
				printf("\n<<< Feature 3 is unavailable >>>\n\n");
				pause();
				printf("\n");
				display_menu = 1;
				break;
			case 4: 
				printf("\n<<< Feature 4 is unavailable >>>\n\n");
				pause();
				printf("\n");
				display_menu = 1;
				break;
			case 5: 
				printf("\n<<< Feature 5 is unavailable >>>\n\n");
				pause();
				printf("\n");
				display_menu = 1;
				break;
			case 6: 
				printf("\n<<< Feature 6 is unavailable >>>\n\n");
				pause();
				printf("\n");
				display_menu = 1;
				break;
			case 0: 
				printf("\nExit the program? (Y)es/(N)o: ");
				if (yes() == 1)
				{
					printf("\nContact Management System: terminated\n");
					display_menu = 0;
				}
				else
				{
					printf("\n");
					display_menu = 1;
				}
				break;
			default:
				printf("Expect to get input between 0 and 6.");
				pause();
				display_menu = 1;
		}

	}
		
}