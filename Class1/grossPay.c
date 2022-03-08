#include <stdio.h>

struct EMPLOYEES
{
	char name[20];
	int id;
	float payRate;
	float hoursWorked;
}employee[6] = { { "Jones", 3462, 4.62f, 40.0f }, { "Robbins", 6793, 5.83f, 38.5f }, { "Smith", 6985, 5.22f, 45.5f }, { "Swain", 7834, 6.89f, 40.0f }, { "Timmins", 8867, 6.43f, 35.5f }, { "Williams", 9002, 4.75f, 42.0f } };


void main()
{
	float totpay = 0;
	for (int i = 0; i < 6; i++)
	{
		printf("name: %s\n", employee[i].name);
		printf("ID number: %d\n", employee[i].id);
		printf("%f\n\n", (double)employee[i].payRate * (double)employee[i].hoursWorked);
		totpay = totpay + employee[i].payRate * employee[i].hoursWorked;
	}
	printf("All pay: %f", totpay);
}