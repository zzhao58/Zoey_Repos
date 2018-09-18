
// Name: Zhi Zhao
// Student Number:109079178
// Email: zzhao58@mysenaca.ca
// Section: GG
// Date:  June 7, 2018
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MINDAYS 3
#define MAXDAYS 10
#define MINDAYS_2 1
#define MAXDAYS_2 4

// Place your code below
int main()
{
	int h_day[MAXDAYS] = {0};
	int l_day[MINDAYS] = {0};
	int max_h, min_l, max_day, min_day, day_2, days, i, sum_h, sum_l, Mindays_2, Maxdays_2;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
	scanf("%d", &days);
	printf("\n");

	for (i = 0; i < days; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &h_day[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &l_day[i]);
	}

	printf("\n");
	printf("Day  Hi  Low\n");
	for (i = 0; i < days; i++)
	{
		printf("%d    %d    %d\n", i + 1, h_day[i], l_day[i]);

		if (i == 0)
		{
			max_h = h_day[i];
			min_l = l_day[i];
			max_day = i + 1;
			min_day = i + 1;
		}
		else
		{
			if (h_day[i] > max_h)
			{
				max_h = h_day[i];
				max_day = i + 1;
			}
			else
			{
				//do nothing
			}

			if (l_day[i] < min_l)
			{
				min_l = l_day[i];
				min_day = i + 1;
			}
			else
			{
				//do nothing
			}
		}
	}
	printf("\n");
	printf("The highest temperature was %d, on day %d\n", max_h, max_day);
	printf("The lowest temperature was %d, on day %d\n", min_l, min_day);

	printf("\n");
	printf("Enter a number between %d and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", Mindays_2, Maxdays_2);
	scanf("%d", &day_2);

	while (day_2 >= 0)
	{
		if (day_2 < 1 || day_2>days)
		{
			printf("\n");
			printf("Invalid entry, please enter a number between %d and %d, inclusive: ", Mindays_2, Maxdays_2);
			scanf("%d", &day_2);
		}
		else
		{
			sum_h = 0;
			sum_l = 0;
			for (i = 0; i < day_2; i++)
			{
				sum_h = sum_h + h_day[i];

				sum_l = sum_l + l_day[i];
			}
			printf("\n");
			printf("The average temperature up to day %d is: %1.2f\n", day_2, (float)(sum_h + sum_l) / (day_2 * 2));
			printf("\n");
			printf("Enter a number between %d and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", Mindays_2, Maxdays_2);
			scanf("%d", &day_2);
		}
	}
	printf("\n");
	printf("Goodbye!\n");

	return 0;
}

