#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct CAR
{
	char name[20];
	int year;
	double price;
}car[4] = { {"Avante", 2007, 13000.00}, {"Sonata", 2008, 18000.00}, {"SM7", 2009, 22000.00}, {"Equus", 2010, 35000.00} };

int main()
{
	FILE* carsFile;
	char fname[20] = "cars.txt";
	char name[20];
	int year;
	double price;
	carsFile = fopen(fname, "w");
	for (int i = 0; i < 4; i++)
		fprintf(carsFile, "%s %d %f\n", car[i].name, car[i].year, car[i].price);
	fclose(carsFile);
	carsFile = fopen(fname, "r");
	printf("-------------------------------------\n");
	printf("|Name		|Year		|Price		|\n");
	printf("--------------------------------------\n");
	while (fscanf(carsFile, "%s %d %lf", &name, &year, &price) == 3)
	{
		printf("|%-10s | %d| \t %.2f |\n", name, year, price);
	}
	fclose(carsFile);
	return 0;
}