#include <stdio.h>

void secs(int hours, int minutes, int seconds, int* totSec);

int main()
{
	int hours = 1, minutes = 20, seconds = 30, totSec = 0;
	if (hours < 0 || minutes < 0 || seconds < 0)
	{
		printf("Negative number is an invalid value.\n\n");
	}
	else
	{
		secs(hours, minutes, seconds, &totSec);
		printf("hours: %d minutes: %d seconds: %d\n", hours, minutes, seconds);
		printf("total seconds = %d\n\n", totSec);
	}

	hours = 0, minutes = 35, seconds = 23;
	if (hours < 0 || minutes < 0 || seconds < 0)
	{
		printf("Negative number is an invalid value.\n\n");
	}
	else
	{
		secs(hours, minutes, seconds, &totSec);
		printf("hours: %d minutes: %d seconds: %d\n", hours, minutes, seconds);
		printf("total seconds = %d\n\n", totSec);
	}

	hours = -1, minutes = 22, seconds = 33;
	if (hours < 0 || minutes < 0 || seconds < 0)
	{
		printf("Negative number is an invalid value.\n\n");
	}
	else
	{
		secs(hours, minutes, seconds, &totSec);
		printf("hours: %d minutes: %d seconds: %d\n", hours, minutes, seconds);
		printf("total seconds = %d\n\n", totSec);
	}

	return 0;
}

void secs(int hours, int minutes, int seconds, int* totSec)
{
	*totSec = seconds + minutes * 60 + hours * 3600;
}