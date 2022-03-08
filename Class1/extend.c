#include <stdio.h>
#define size 10

void extend(double price[], double quantity[], double amount[]);

int main()
{
	double price[size] = { 10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98 };
	double quantity[size] = { 4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8 };
	double amount[size] = { 0, };

	extend(price, quantity, amount);

	for (int i = 0; i < size; i++)
	{
		printf("%f * %f = %f\n",price[i], quantity[i],  amount[i]);
	}

}

void extend(double price[], double quantity[], double amount[])
{
	for (int i = 0; i < size; i++)
	{
		amount[i] = price[i] * quantity[i];
	}
}