/* -------------------------------------------
Name:           
Student number: 
Email:          
Section:        
Date:           
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:



// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:



//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
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

// getIntInRange:
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

// yes:
int yes(void)
{
	char option, NL = 'x';

	do {
		scanf("%c%c", &option, &NL);
		if (!(option == 'Y' || option == 'y' || option == 'N' || option == 'n') || NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	} while (!(option == 'Y' || option == 'y' || option == 'N' || option == 'n') || NL != '\n');

	if (option == 'Y' || option == 'y')
		return 1;
	else
		return 0;
}

// menu:
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

// ContactManagerSystem:
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

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10s", telNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(telNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) 
{

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int contacts_count)
{

}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact)
{

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contact[], int size)
{

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contact[], int size)
{

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contact[], int size)
{

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contact[], int size)
{

}


// deleteContact:
// Put empty function definition below:
void deleteContact(const struct Contact contatc[], int size)
{

}


// sortContacts:
// Put empty function definition below:
void sortContacts(const struct Contact contact[], int size)
{

}