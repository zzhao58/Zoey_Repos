/* -------------------------------------------
Name:zhi zhao
Student number:109079178
Email:zzhao58@senecacollege.ca
Section:GG
Date:July 11, 2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include"contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:



// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *name) {
	char user_option;
	printf("Please enter the contact's first name: ");
	scanf("%30s", (*name).firstName);

	//Middle Initial
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &user_option);
	while (user_option != 'Y'&&user_option != 'y'&&user_option != 'N'&&user_option != 'n')
	{
		printf("Please input y or n:");
		scanf(" %c", &user_option);
	}
	
	if (user_option == 'y'|| user_option == 'Y')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", (*name).middleInitial);
	}

	//LastName
	printf("Please enter the contact's last name: ");
	scanf("%35s", (*name).lastName);
};



// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *address) {
	//StreetNumber
	do {
		printf("Please enter the contact's street number: ");
		scanf("%d", &(*address).streetNumber);

		if ((*address).streetNumber <= 0)
			printf("Incorrect values, streetNumber should be greater than 0.\n");
	} while ((*address).streetNumber <= 0);

	//Street
	printf("Please enter the contact's street name: ");
	scanf("%40s", (*address).street);

	char user_option;
	//apartmentNumber
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &user_option);
	while (user_option != 'Y'&&user_option != 'y'&&user_option != 'N'&&user_option != 'n')
	{
		printf("Please input y or n:");
		scanf(" %c", &user_option);
	}
	if (user_option == 'y' || user_option == 'Y')
	{
		do {
			printf("Please enter the contact's apartment number: ");
			scanf("%d", &(*address).apartmentNumber);

			if ((*address).apartmentNumber <= 0)
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




// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers *numbers) {
	//cell phone number
	char user_option;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &user_option);
	while (user_option != 'Y'&&user_option != 'y'&&user_option != 'N'&&user_option != 'n')
	{
		printf("Please input y or n:");
		scanf(" %c", &user_option);
	}
	if (user_option == 'y' || user_option == 'Y')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%20s", (*numbers).cell);
	}

	// home phone number
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &user_option);
	while (user_option != 'Y'&&user_option != 'y'&&user_option != 'N'&&user_option != 'n')
	{
		printf("Please input y or n:");
		scanf(" %c", &user_option);
	}
	if (user_option == 'y' || user_option == 'Y')
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%20s", (*numbers).home);
	}

	//business phone number
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &user_option);
	while (user_option != 'Y'&&user_option != 'y'&&user_option != 'N'&&user_option != 'n')
	{
		printf("Please input y or n:");
		scanf(" %c", &user_option);
	}
	if (user_option == 'y' || user_option == 'Y')
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%20s", (*numbers).business);
		printf("\n");
	}
}


