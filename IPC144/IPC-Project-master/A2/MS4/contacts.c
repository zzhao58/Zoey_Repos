/* -------------------------------------------
Name:zhi zhao
Student number:109079178
Email:zzhao58@senecacollege.ca
Section:GG
Date:July 31,2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name)
{
	printf("Please enter the contact's first name: ");
	//scanf("%30[^\n]", (*name).firstName);
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();

	//Middle Initial
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", (*name).middleInitial);
		clearKeyboard();
	}

	//LastName
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", (*name).lastName);
	clearKeyboard();
};

// getAddress:
void getAddress(struct Address *address)
{
	//StreetNumber
	do
	{
		printf("Please enter the contact's street number: ");
		(*address).streetNumber = getInt();

		if ((*address).streetNumber <= 0)
			printf("Incorrect values, streetNumber should be greater than 0.\n");
	} while ((*address).streetNumber <= 0);

	//Street
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", (*address).street);
	clearKeyboard();

	//apartmentNumber
	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes() == 1)
	{
		do
		{
			printf("Please enter the contact's apartment number: ");
			(*address).apartmentNumber = getInt();

			if ((*address).apartmentNumber <= 0)
				printf("Incorrect values, apartmentNumber should be greater than 0.\n");
		} while ((*address).apartmentNumber < 0);
	}

	// postalCode
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", (*address).postalCode);
	clearKeyboard();

	//city
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", (*address).city);
	clearKeyboard();
};

// getNumbers:
void getNumbers(struct Numbers *numbers)
{
	int is_yes;

	//cell phone number
	//printf("Do you want to enter a cell phone number? (y or n): ");
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	// home phone number
	printf("Do you want to enter a home phone number? (y or n): ");
	is_yes = yes();
	if (is_yes == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else
	{
		numbers->home[0] = '\0';
	}

	//business phone number
	printf("Do you want to enter a business phone number? (y or n): ");
	is_yes = yes();
	if (is_yes == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);		
	}
	else
	{
		numbers->business[0] = '\0';
	}

}

// getContact:
void getContact(struct Contact *contacts)
{
	//getName(&((*contacts).name));
	getName(&(contacts->name));

	getAddress(&(contacts->address));

	getNumbers(&(contacts->numbers));

}