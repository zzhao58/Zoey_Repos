/*
	 Name:      ZHI ZHAO
	 Student#:  109 079 178
	 email:		zzhao58@senecacollege.ca
	 Date:      May, 22, 2018
	 Section:   GG
*/

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include<stdio.h>



int main()
{
	float amount;
	int	amount_cent, amount_GST, amount_total, balance;
	int loonies, quarters, dimes, nickels, pennies;
	const float GST = 0.13;

	printf("---===IPC Temperature Analyzer===---");
	printf("Please enter the amount to be paid: $");
	scanf("%f", &amount);
	amount_cent = (int)(amount * 100);
	amount_GST = (int)(amount_cent * GST + .5);

	amount_total = amount_cent + amount_GST;

	printf("GST: %0.2f\n", (float)amount_GST / 100);
	printf("Balance owing: $%0.2f\n", (float)amount_total / 100);

	loonies = amount_total / 100;
	balance = amount_total % (loonies * 100);

	printf("Loonies required: %d, balance owing $%0.2f\n", loonies, (float)balance / 100);

	quarters = balance / 25;
	balance = balance % 25;
	printf("Quarters required: %d, balance owing $%0.2f\n", quarters, (float)balance / 100);


	dimes = balance / 10;
	balance = balance % 10;
	printf("Dimes required: %d, balance owing $%0.2f\n", dimes, (float)balance / 100);

	nickels = balance / 5;
	balance = balance % 5;
	printf("Nickels required: %d, balance owing $%0.2f\n", nickels, (float)balance / 100);

	pennies = balance / 1;
	balance = balance % 1;
	printf("Pennies required: %d, balance owing $%0.2f\n", pennies, (float)balance / 100);

	return 0;
}

