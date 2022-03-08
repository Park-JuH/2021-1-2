#include <stdio.h>

struct Date
{
	int month;
	int day;
	int year;
};

void Days(struct Date data[], int* totDays, int* j);

void main()
{
	int totDays = 0;
	struct Date data[5] = { {1, 2, 2000}, {3, 5, 2021}, {3, 0, 2021}, {12, 31, 2020}, {1, 1, 1999} };
	for (int i = 0; i < 5; i++)
	{

		Days(data, &totDays, &i);
		if (totDays == -1)
			printf("Dates before 1/1/2000 cannot be used.\n\n");
		else if (totDays == -2)
			printf("The number is Invalid value\n\n");
		else
			printf("Total days: %d\n\n", totDays);

	}
}


void Days(struct Date data[], int* totDays, int* j)
{
	int bfMonth = 1;
	int bfDay = 1;
	int bfYear = 2000;
	if ((data[*j]).year < bfYear)
	{
		*totDays = -1;
	}
	else if ((data[*j]).day > 30 || (data[*j]).day < bfDay || (data[*j]).month < bfMonth)
	{
		*totDays = -2;
	}
	else
	{
		*totDays = (30 * ((data[*j]).month - bfMonth)) + ((data[*j]).day - bfDay) + (360 * ((data[*j]).year - bfYear));
	}
}