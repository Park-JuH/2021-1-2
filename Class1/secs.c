#include <stdio.h>

int secs(int hours, int minutes, int seconds);

int main()
{
	int hours = 1, minutes = 20, seconds = 30, total = 0;
	if (hours < 0 || minutes < 0 || seconds < 0)
	{
		printf("Negative number is an invalid value.\n\n");
	}
	else
	{
		total = secs(hours, minutes, seconds);
		printf("hours: %d minutes: %d seconds: %d\n", hours, minutes, seconds);
		printf("total seconds = %d\n\n", total);
	}
	hours = 0, minutes = 0, seconds = 52;
	if (hours < 0 || minutes < 0 || seconds < 0)
	{
		printf("Negative number is an invalid value.\n\n");
	}
	else
	{
		total = secs(hours, minutes, seconds);
		printf("hours: %d minutes: %d seconds: %d\n", hours, minutes, seconds);
		printf("total seconds = %d\n\n", total);
	}

	hours = -1, minutes = 13, seconds = 23;
	if (hours < 0 || minutes < 0 || seconds < 0)
	{
		printf("Negative number is an invalid value.\n\n");
	}
	else
	{
		total = secs(hours, minutes, seconds);
		printf("hours: %d minutes: %d seconds: %d\n", hours, minutes, seconds);
		printf("total seconds = %d\n\n", total);
	}

	return 0;
}

int secs(int hours, int minutes, int seconds)
{
	seconds = seconds + minutes * 60 + hours * 3600;
	return seconds;
}