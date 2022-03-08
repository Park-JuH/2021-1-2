#include <stdio.h>

struct Date
{
	int month;
	int day;
	int year;
};

int Days(int, int, int);

void main()
{
	int totDays;
	struct Date data[5] = { {1, 2, 2000}, {3, 5, 2021}, {3, 0, 2021}, {12, 31, 2020}, {1, 1, 1999} };
	for (int i = 0; i < 5; i++)
	{

		totDays = Days(data[i].month, data[i].day, data[i].year);
		if (totDays == -1)
			printf("Dates before 1/1/2000 cannot be used.\n\n");
		else if (totDays == -2)
			printf("The number is Invalid value\n\n");
		else
			printf("Totla days: %d\n\n", totDays);

	}
}


int Days(int month, int day, int year)
{
	int totDays;
	int bfMonth = 1;
	int bfDay = 1;
	int bfYear = 2000;
	if (year < bfYear)
	{
		totDays = -1;
	}
	else if (day > 30 || day < bfDay || month < bfMonth)
	{
		totDays = -2;

	}
	else
	{
		totDays = (30 * (month - bfMonth)) + (day - bfDay) + (360 * (year - bfYear));
	}
	return totDays;
}