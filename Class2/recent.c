#include <stdio.h>

struct Date
{
	int month;
	int day;
	int year;
};

struct Member
{
	int m;
	int d;
	int y;
};

struct Date recent(struct Date, struct Date);

void main()
{
	struct Date ans;
	struct Date data1[5] = { {10, 9, 2001}, {0, 3, 2021}, {7, 1, 2017}, {12, 23, 2002}, {10, 10, 2010} };
	struct Date data2[5] = { {11, 3, 2001}, {2, 2, 2011}, {8, 2, 2017}, {12, 22, 2002}, {10, 10, 2010} };
	struct Member member[5];
	for (int i = 0; i < 5; i++)
	{
		ans = recent(data1[i], data2[i]);
		if (ans.year == -1)
		{
			member[i].m = ans.month;
			member[i].d = ans.day;
			member[i].y = ans.year;
			continue;
		}
		else
		{
			printf("Recent date: %d/%d/%d\n\n", ans.month, ans.day, ans.year);
			member[i].m = ans.month;
			member[i].d = ans.day;
			member[i].y = ans.year;
		}
	}
	printf("Member values\n");
	for (int j = 0; j < 5; j++)
	{
		if (member[j].m == -1)
			continue;
		else
			printf("%d/%d/%d\n", member[j].m, member[j].d, member[j].y);
	}
}

struct Date recent(struct Date data1, struct Date data2)
{
	if (data1.year <= 0 || data1.month <= 0 || data1.day <= 0 || data2.year <= 0 || data2.month <= 0 || data2.day <= 0) //invalid value
	{
		printf("Invalid value\n\n");
		data1.year = -1;
		data1.month = -1;
		data1.day = -1;
		return data1;
	}
	else if (data1.year > data2.year)
	{
		return data1;
	}
	else if (data1.year < data2.year)
	{
		return data2;
	}
	else
	{
		if (data1.month > data2.month)
		{
			return data1;
		}
		else if (data1.month < data2.month)
		{
			return data2;
		}
		else
		{

			if (data1.day > data2.day)
			{
				return data1;
			}
			else if (data1.day < data2.day)
			{
				return data2;
			}
			else
				return data1;
		}
	}

}