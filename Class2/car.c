#include <stdio.h>

struct CAR
{
	int carNumber;
	int milesDriven;
	int gallonsUsed;
};

void main()
{
	struct CAR report1 = {25, 1450, 62};
	struct CAR report2 = { 36, 3240, 136 };
	struct CAR report3 = { 44, 1792, 76 };
	struct CAR report4 = { 52, 2360, 105 };
	struct CAR report5 = { 68, 2114, 67 };
	double avg = 0;
	printf("Car Report\n\n");
	printf("Number: %d\n", report1.carNumber);
	printf("Miles per gallon: %f\n\n", (double)report1.milesDriven / (double)report1.gallonsUsed);
	avg = avg + (double)report1.milesDriven / (double)report1.gallonsUsed;
	printf("Number: %d\n", report2.carNumber);
	printf("Miles per gallon: %f\n\n", (double)report2.milesDriven / (double)report2.gallonsUsed);
	avg = avg + (double)report2.milesDriven / (double)report2.gallonsUsed;
	printf("Number: %d\n", report3.carNumber);
	printf("Miles per gallon: %f\n\n", (double)report3.milesDriven / (double)report3.gallonsUsed);
	avg = avg + (double)report3.milesDriven / (double)report3.gallonsUsed;
	printf("Number: %d\n", report4.carNumber);
	printf("Miles per gallon: %f\n\n", (double)report4.milesDriven / (double)report4.gallonsUsed);
	avg = avg + (double)report4.milesDriven / (double)report4.gallonsUsed;
	printf("Number: %d\n", report5.carNumber);
	printf("Miles per gallon: %f\n\n", (double)report5.milesDriven / (double)report5.gallonsUsed);
	avg = avg + (double)report5.milesDriven / (double)report5.gallonsUsed;
	printf("Average miles per gallon: %f", avg / 5);
}