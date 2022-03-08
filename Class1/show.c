#include <stdio.h>

void show(float rates[]);



int main()
{
	float rates[9] = { 6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0 };
	show(rates);
}

void show(float rates[])
{
	for (int i = 0; i < 9; i++)
	{
		printf("%f\n", rates[i]);
	}
}