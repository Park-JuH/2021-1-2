#include <stdio.h>
#include <math.h>

void change(float usd, int* quarters, int* dimes, int* nikels, int* pennies);


int main()
{
	float usd = 10.46f;
	int quarters = 0, dimes = 0, nikels = 0, pennies = 0;
	printf("usd: %f\n\n", usd);
	change(usd, &quarters, &dimes, &nikels, &pennies);
	printf("quarters: %d\n", quarters);
	printf("dimes: %d\n", dimes);
	printf("nikels: %d\n", nikels);
	printf("pennies: %d\n\n", pennies);

	usd = 10.87f;
	printf("usd: %f\n\n", usd);
	change(usd, &quarters, &dimes, &nikels, &pennies);
	printf("quarters: %d\n", quarters);
	printf("dimes: %d\n", dimes);
	printf("nikels: %d\n", nikels);
	printf("pennies: %d\n\n", pennies);

	usd = 0.33f;
	printf("usd: %f\n\n", usd);
	change(usd, &quarters, &dimes, &nikels, &pennies);
	printf("quarters: %d\n", quarters);
	printf("dimes: %d\n", dimes);
	printf("nikels: %d\n", nikels);
	printf("pennies: %d\n\n", pennies);

	return 0;

}

void change(float usd, int* quarters, int* dimes, int* nikels, int* pennies)
{
	int cent = usd;
	usd = usd - cent;
	usd = (double)usd * 100;
	usd = usd + 0.5;
	usd = floor(usd);
	cent = (int)usd;
	*quarters = cent / 25;
	cent = cent - (25 * *quarters);
	*dimes = cent / 10;
	cent = cent - (10 * *dimes);
	*nikels = cent / 5;
	cent = cent - (5 * *nikels);
	*pennies = cent / 1;

}