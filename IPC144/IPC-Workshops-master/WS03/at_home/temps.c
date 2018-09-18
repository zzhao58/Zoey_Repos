// Name: Zhi Zhao
// Student Number:109079178
// Email: zzhao58@mysenaca.ca
// Section: GG
// Date:  May 30, 2018

#define _CRT_SECURE_NO_WARNINGS


// Put your code below:
#include <stdio.h>
#define NUMS 4
int main()
{
	int i, temp_h, temp_l, temp_max_day, temp_min_day, temp_max, temp_min;
	int Sum_h=0, Sum_l=0;

	temp_max = 0;
	temp_min = 0;
	printf("---=== IPC Temperature Analyzer ===---");
	for (i = 0; i < NUMS; i++)
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

		Sum_h = Sum_h + temp_h;
		Sum_l = Sum_l + temp_l;



		if (i == 0)
		{   
			temp_max = temp_h;
			temp_max_day = i+1;
			temp_min = temp_l;
			temp_min_day = i+1;


		}
		else
		{
			if (temp_h > temp_max)
			{
				temp_max = temp_h;
				temp_max_day = i+1;
			}

			if (temp_l < temp_min)
			{
				temp_min = temp_l;
				temp_min_day = i+1;
			}
		}
	}
	printf("\n");
	printf("The average (mean) temperature was: %1.2f\n", (Sum_h + Sum_l) / (NUMS * 2.0));
	printf("The highest temperature was %d, on day %d\n",temp_max,temp_max_day);
	printf("The lowest temperature was %d, on day %d\n", temp_min, temp_min_day);

	return 0;
}