#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct CAR
{
	char name[20];
	int year;
}car[2] = { "Avante", 2007, "Sonata", 2008 };

int main()
{
	int i = 0;
	char name[20];
	int year;
	FILE* carsFile;
	carsFile = fopen("cars.txt", "w");
	if (carsFile == NULL)
		printf("\nFile Could Not Be Opened");
	for(int i = 0; i < 2; i++)
		fprintf(carsFile, "%s %d\n", car[i].name, car[i].year);
	fclose(carsFile);
	carsFile = fopen("cars.txt", "r");
	while(fscanf(carsFile, "%s %d", &name, &year) == 2)
		printf("%s %d\n", name, year);
	fclose(carsFile);
}