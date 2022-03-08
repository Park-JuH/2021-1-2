#include <stdio.h>
#include <math.h>

void liquid(int number, int* gallons, int* quarts, int* pints, int* cups);

int main()
{
	int number = 5;
	int gallons = 0, quarts = 0, pints = 0, cups = 0;
	liquid(number, &gallons, &quarts, &pints, &cups);

	number = 14;
	liquid(number, &gallons, &quarts, &pints, &cups);

	number = 30;
	liquid(number, &gallons, &quarts, &pints, &cups);

	return 0;

}

void liquid(int number, int* gallons, int* quarts, int* pints, int* cups)
{
	*cups = number;
	*gallons = ceil(0.0625 * *cups);
	*quarts = ceil(0.25 * *cups);
	*pints = ceil(0.5 * *cups);

	printf("%d cups\n", *cups);
	printf("gallons: %d\n", *gallons);
	printf("quarts: %d\n", *quarts);
	printf("pints: %d\n\n", *pints);
}