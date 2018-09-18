//--------------------------------------------------
// Name: Zhi Zhao
// Student Number:109079178
// Email: zzhao58@mysenaca.ca
// Section: GG
// Date:  5 June, 2018
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include <stdio.h>
#define Mindays 3
#define Maxdays 10

int main()
{
	int day_h[] = {0};
	int day_l[] = {0};
	int days,i;
	
	printf("---=== IPC Temperature Calculator V2.0 ===---\n" );

	
	printf("Please enter the number of days, between %d and %d, inclusive: ", Mindays, Maxdays);
	scanf("%d", &days);
	do
	{ 
		printf("\n");
		if (days < Mindays || days>Maxdays)
		{
			printf("Invalid entry, please enter a number between %d and %d, inclusive: ", Mindays, Maxdays);
			scanf("%d", &days);
		}
	} while (days < Mindays || days>Maxdays);
		
	printf("\n");
	
	for (i = 0; i < days; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &day_h[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &day_l[i]);
	}

	printf("\n");
	printf("Day  Hi  Low\n");
	for(i = 0; i < days; i++)
	{
		printf("%d    %d    %d\n", i + 1,day_h[i],day_l[i]);
	}

	return 0;
}
