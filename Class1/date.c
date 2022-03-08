#include <stdio.h>
#include <string.h>

struct {
	int month;
	int day;
	int year;
} date;

void main()
{
	int m, d, y;
	scanf("%d", &m);
	scanf("%d", &d);
	scanf("%d", &y);
	date.month = m;
	date.day = d;
	date.year = y;

	printf("%d-%d-%d", date.month, date.day, date.year);

}