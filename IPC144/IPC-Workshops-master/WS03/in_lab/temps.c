
// Name: Zhi Zhao
// Student Number:109079178
// Email: zzhao58@mysenaca.ca
// Section: GG
// Date:  May 29, 2018

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3

// Put your code below:
#include <stdio.h>
int main() 
{
	int i, temp_h, temp_l, temp_t;
	
	temp_t = 0;
	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i <= NUMS-1; i++)
	{
		do 
		{
			printf("\n");
			printf("Enter the high value for day %d: ", i+1);
			scanf("%d", &temp_h);

			printf("\n");
			printf("Enter the low value for day %d: ", i+1);
			scanf("%d", &temp_l);

			if (temp_h > 40 || temp_l<-40 || temp_l>temp_h) 
			{
				printf("\n");
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			}
		} while (temp_h > 40 || temp_l<-40 || temp_l>temp_h);

		temp_t = temp_t + temp_h + temp_l;

	}
	printf("\n");
	printf("The average (mean) temperature was: %1.2f\n", temp_t / (NUMS * 2.0));

	return 0;
}