/* -------------------------------------------
Name:zhi zhao
Student number:109079178
Email:zzhao58@senecacollege.ca
Section:GG
Date:JUly 31,2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
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
	printf("\n");

	return option;
}

// ContactManagerSystem:
void ContactManagerSystem(void)
{
	int option, display_menu;
	struct Contact contacts[MAXCONTACTS] = 
	{ 
		{	{ "Rick",{ '\0' }, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" } 
		},
	
		{	{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" } 
		},
	
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } 
		},
	
		{
			{ "Sasha",{ '\0' }, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } 
		},
	};

	display_menu = 1;
	while (display_menu == 1)
	{
		option = menu();
		switch (option)
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			display_menu = 1;
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			display_menu = 1;
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			display_menu = 1;
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			display_menu = 1;
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			display_menu = 1;
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			display_menu = 1;
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
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
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10[0-9]", telNum);
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
	int i;
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
			return i;		
	}

	return -1;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int contacts_count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n",contacts_count);
}

// displayContact:
void displayContact(const struct Contact *contact)
{
	char fullname[80];
	if (strlen(contact->name.middleInitial) == 0)
	{
		strcpy(fullname,contact->name.firstName);
		strcat(fullname, " ");
		strcat(fullname, contact->name.lastName);	
	}
	else 
	{
		strcpy(fullname, contact->name.firstName);
		strcat(fullname, " ");
		strcat(fullname, contact->name.middleInitial);
		strcat(fullname, " ");
		strcat(fullname, contact->name.lastName);
	}
	printf(" %s\n", fullname);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
		printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size)
{
	int i, count=0;
	displayContactHeader();
	for (i = 0; i < size; i++) {
		if (contact[i].numbers.cell[0] != '\0') {
			displayContact(&(contact[i]));
			count++;
		}
	}
	displayContactFooter(count);
}


// searchContacts:
void searchContacts(const struct Contact contact[], int size)
{
	int i;
	char telNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);
	i = findContactIndex(contact, size, telNum);
	if (i != -1)
	{
		printf("\n");
		displayContact(&(contact[i]));
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");	
}

// addContact:
void addContact(struct Contact contact[], int size)
{
	int i=0, is_added=0;

	while( i<size && is_added==0 )
	{
		if (strlen(contact[i].numbers.cell) == 0)
		{
			getContact(&(contact[i]));
			printf("--- New contact added! ---\n");
			is_added = 1;
		}
		i++;
	}
	if(is_added==0)
		printf("*** ERROR: The contact list is full! ***\n");
}

// updateContact:
void updateContact(struct Contact contact[], int size)
{
	int index_found, yes_name, yes_address, yes_numbers ;
	char telNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);
	//printf("%s", telNum);
	index_found = findContactIndex(contact,size,telNum);
	if (index_found == -1)
	{
		printf("*** Contact NOT FOUND ***\n");		
	}
	else 
	{
		printf("\nContact found:\n");
		displayContact(&(contact[index_found]));
		printf("\n");

		//Name
		printf("Do you want to update the name? (y or n): ");
		yes_name = yes();
		if (yes_name == 1) {
			getName(&(contact[index_found].name));
		}
		
		//Address
		printf("Do you want to update the address? (y or n): ");
		yes_address = yes();
		if (yes_address == 1) {
			getAddress(&(contact[index_found].address));
		}
		
		//Numbers
		printf("Do you want to update the numbers? (y or n): ");
		yes_numbers = yes();
		if (yes_numbers == 1) {
			getNumbers(&(contact[index_found].numbers));
		}

		if(yes_name==1 || yes_address==1 || yes_numbers==1)
			printf("--- Contact Updated! ---\n");
	}
	
	
}

// deleteContact:
void deleteContact(struct Contact contact[], int size)
{

	int index_found;
	char telNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);
	index_found = findContactIndex(contact, size, telNum);
	if (index_found == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&(contact[index_found]));
		printf("\n");

		//Delete contact
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1)
		{
			contact[index_found].name.firstName[0] = '\0';
			contact[index_found].name.middleInitial[0] = '\0';
			contact[index_found].name.lastName[0] = '\0';

			contact[index_found].address.streetNumber = 0;
			contact[index_found].address.street[0] = '\0';
			contact[index_found].address.apartmentNumber = 0;
			contact[index_found].address.postalCode[0] = '\0';
			contact[index_found].address.city[0] = '\0';	

			contact[index_found].numbers.cell[0] = '\0';
			contact[index_found].numbers.home[0] = '\0';
			contact[index_found].numbers.business[0] = '\0';

			printf("--- Contact deleted! ---\n");
		}		
	}
} 

// sortContacts:
void sortContacts(struct Contact contact[], int size)
{
	int i, j;
	struct Contact temp = { { { '\0' },{ '\0' },{ '\0' } },
							{ 0,{ '\0' }, 0,{ '\0' },{ '\0' } },
							{ { '\0' },{ '\0' },{ '\0' } }
						  };

	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if(strcmp(contact[j].numbers.cell, contact[j+1].numbers.cell) > 0) {
				temp = contact[j];
				contact[j] = contact[j + 1];
				contact[j + 1] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}