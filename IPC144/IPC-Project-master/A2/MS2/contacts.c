/* -------------------------------------------
Name:zhi zhao
Student number:109079178
Email:zzhao58@senecacollege.ca
Section:GG
Date:July 24, 2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these functions to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name *name)
{
	printf("Please enter the contact's first name: ");
	scanf("%30s", (*name).firstName);

	//Middle Initial
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes()==1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", (*name).middleInitial);
	}

	//LastName
	printf("Please enter the contact's last name: ");
	scanf("%35s", (*name).lastName);
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

	//apartmentNumber
	printf("Do you want to enter an apartment number? (y or n): ");
	if(yes() == 1)
	{
		do
		{
			printf("Please enter the contact's apartment number: ");
			(*address).apartmentNumber = getInt();

			if((*address).apartmentNumber <= 0)
				printf("Incorrect values, apartmentNumber should be greater than 0.\n");
		} while ((*address).apartmentNumber < 0);
	}

	// postalCode
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", (*address).postalCode);

	//city
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", (*address).city);

};



// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers *numbers)
{
	int is_yes;

	//cell phone number
	//printf("Do you want to enter a cell phone number? (y or n): ");
	printf("Please enter the contact's cell phone number: ");
	scanf("%20s", (*numbers).cell);
	clearKeyboard();

	// home phone number
	printf("Do you want to enter a home phone number? (y or n): ");
	is_yes = yes();
	if (is_yes == 1)
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%20s", (*numbers).home);
	}

	//business phone number
	printf("Do you want to enter a business phone number? (y or n): ");
	is_yes = yes();
	if( is_yes == 1 )
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%20s", (*numbers).business);
		//printf("\n");
	}
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact *contacts)
{
	//getName(&((*contacts).name));
	getName(&(contacts->name));

	getAddress(&(contacts->address));

	getNumbers(&(contacts->numbers));

}
