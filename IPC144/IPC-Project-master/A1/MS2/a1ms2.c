/* -------------------------------------------
Name:Zhi Zhao
Student number: 109079178
Email:ZZHAO58@senecacollege.ca
Section:GG
Date:July 8, 2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); 
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

int main (void)
{
    // Declare variables here:
		
	struct Name contact_full_name = {{'\0'}};
	//contact_full_name.firstName[0] = '\0';
	//contact_full_name.middleInitial[0] = '\0';
	//contact_full_name.lastName[0] = '\0';

	struct Address contact_address = { 0,{'\0'}, 0,{'\0'},{'\0'}};
	//contact_address.streetNumber = 0;
	//contact_address.street[0] = '\0';
	//contact_address.apartmentNumber = 0;
	//contact_address.postalCode[0] = '\0';
	//contact_address.city[0]='\0';

	struct Numbers contact_numbers = {{'\0'}};
	//contact_numbers.cell[0] = '\0';
	//contact_numbers.home[0] = '\0';
	//contact_numbers.business[0] = '\0';


    // Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	//FirstName
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", contact_full_name.firstName);
	clearKeyboard();

	//Middle Initial
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", contact_full_name.middleInitial);
		clearKeyboard();
	}
	
	//LastName
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", contact_full_name.lastName);
	clearKeyboard();

    //StreetNumber
	do {
		printf("Please enter the contact's street number: ");
		scanf("%d", &contact_address.streetNumber);
		clearKeyboard();

		if (contact_address.streetNumber <= 0)
			printf("Incorrect values, streetNumber should be greater than 0.\n");
	}while (contact_address.streetNumber <= 0);
	
	//Street
	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", contact_address.street);
	clearKeyboard();

	//apartmentNumber
	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes() == 1)
	{
		do {
			printf("Please enter the contact's apartment number: ");
			scanf("%d", &contact_address.apartmentNumber);
			clearKeyboard();

			if (contact_address.apartmentNumber <= 0) 
				printf("Incorrect values, apartmentNumber should be greater than 0.\n");			
		} while (contact_address.apartmentNumber < 0);
	}

	// postalCode
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", contact_address.postalCode);
	clearKeyboard();

	//city
	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", contact_address.city);
	clearKeyboard();

    // Contact Numbers Input:

	//cell phone number
	printf("Do you want to enter a cell phone number? (y or n): ");
	if (yes() == 1)
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%20[^\n]", contact_numbers.cell);
		clearKeyboard();
	}

	// home phone number
	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes() == 1)
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%20[^\n]", contact_numbers.home);
		clearKeyboard();
	}

	//business phone number
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1)
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%20[^\n]", contact_numbers.business);
		clearKeyboard();
		printf("\n");
	}
	
    // Display Contact Summary Details
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");

	printf("First name: %s\n", contact_full_name.firstName);
	if (contact_full_name.middleInitial[0]!='\0')
		printf("Middle initial(s): %s\n", contact_full_name.middleInitial);
	printf("Last name: %s\n\n", contact_full_name.lastName);
	
	printf("Address Details\n");
	printf("Street number: %d\n", contact_address.streetNumber);
	printf("Street name: %s\n", contact_address.street);
	if (contact_address.apartmentNumber != 0)
		printf("Apartment: %d\n", contact_address.apartmentNumber);
	printf("Postal code: %s\n", contact_address.postalCode);
	printf("City: %s\n\n", contact_address.city);

	printf("Phone Numbers:\n");
	if (contact_numbers.cell[0]!='\0')
		printf("Cell phone number: %s\n", contact_numbers.cell);
	if (contact_numbers.home[0] != '\0')
		printf("Home phone number: %s\n", contact_numbers.home);
	if (contact_numbers.business[0] != '\0')
		printf("Business phone number: %s\n\n", contact_numbers.business);

	printf("Structure test for Name, Address, and Numbers Done!\n");
    // Display Completion Message
    return 0;
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/