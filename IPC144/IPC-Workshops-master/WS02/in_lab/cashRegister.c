
   /*  Name      ZHI ZHAO
       Student:  109079178
	   Email:    zzhao58@senecacollege.ca
	   Date:     May, 22 2018
       Section:  GG */


#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>


int main()
{

	double AmountDue, balance_1, balance_2;
	int   loonies, quarters;

	printf("---===IPC Temperature Analyzer===---");
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &AmountDue);
	loonies = (int)AmountDue;
	balance_1 = AmountDue - loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balance_1);


	quarters = (int)(balance_1 * 100 / 25);
	balance_2 = balance_1 - quarters * 0.25;

	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, balance_2);

	return 0;
}