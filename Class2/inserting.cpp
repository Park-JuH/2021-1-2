#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 6

struct DATA {
	char RRN[14];
	char name[20];
	float salary;
	float bonus;
}employee[1000];

void inserting(char tRRN[MAX_SIZE][14], char tName[MAX_SIZE][20], float tSalary[MAX_SIZE], float tBonus[MAX_SIZE]);


void main()
{
	char testRRN[MAX_SIZE][14] = { {"8803021352642"}, {"7706222334511"}, {"7208141245633"}, {"7007141886431"}, {"7706222334511"}, {"7803151176821"} };
	char testName[MAX_SIZE][20] = { {"hong gil dong"}, {"lee ji woo"}, {"yoo jae suk"}, {"park sang woo"}, {"jeong hyeong don"}, {"ha dong hoon"} };
	float testSalary[MAX_SIZE] = { 3000000.5f, 2000000.4f, 5213402.21f, 12244530.45f, 2212441.0f, 754462.2f };
	float testBonus[MAX_SIZE] = { 500000.1f, 600000.32f, 1215432.471f, 102421.0f, 54221.345f, 1245700.66f };

	inserting(testRRN, testName, testSalary, testBonus);
}

void inserting(char tRRN[MAX_SIZE][14], char tName[MAX_SIZE][20], float tSalary[MAX_SIZE], float tBonus[MAX_SIZE])
{
	int count = 0;
	int j = 0;
	int k = 0;
	int test = strlen(tName[0]);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (count == 0)
		{
			if (tSalary[i] > tBonus[i])
			{
				for (j = 0; j < 13; j++)
				{
					if (j >= strlen(tName[i]))
						employee[i].RRN[j] = tRRN[i][j];
					else
					{
						employee[i].RRN[j] = tRRN[i][j];
						employee[i].name[j] = tName[i][j];
					}
				}
				employee[i].RRN[j] = '\0';
				employee[i].name[strlen(tName[i])] = '\0';
				employee[i].salary = tSalary[i];
				employee[i].bonus = tBonus[i];
				employee[i].salary = employee[i].salary;
				employee[i].bonus = employee[i].bonus;
				count++;
				printf("%s's information inserted!\n\n", tName[i]);
			}
			else
			{
				printf("%s's Bonus is invalid value. The bonus is greater than or equal to the salary.\n\n", tName[i]);
			}
		}
		else
		{
			if (tSalary[i] > tBonus[i])
			{
				int arr = 0;
				for (j = 0; j < i; j++)
				{
					for (k = 0; k < strlen(tRRN[i]); k++)     //RRN test
					{
						if (employee[j].RRN[k] == tRRN[i][k])
							continue;
						else
							break;
					}
					if (k == strlen(tRRN[i]))
					{
						arr = 2;
					}
				}
				if (arr == 2)
					printf("%s's RRN is invalid value. The RRN is not unique.\n\n", tName[i]);
				else
				{
					for (j = 0; j < 20; j++)
					{
						if (j >= strlen(tName[i]))
						{
							if (j == 14)
								break;
							employee[i].RRN[j] = tRRN[i][j];
						}
						else if (strlen(tName[i]) > 14 && j >= 14)
						{
							if (j == strlen(tName[i]))
								break;
							employee[i].name[j] = tName[i][j];
						}
						else
						{
							employee[i].RRN[j] = tRRN[i][j];
							employee[i].name[j] = tName[i][j];
						}
					}
					employee[i].RRN[13] = '\0';
					employee[i].name[strlen(tName[i])] = '\0';
					employee[i].salary = tSalary[i];
					employee[i].bonus = tBonus[i];
					count++;
					printf("%s's information inserted!\n\n", tName[i]);
				}
			}
			else
			{
				printf("%s's Bonus is invalid value. The bonus is greater than or equal to the salary.\n\n", tName[i]);
			}
		}
	}
	printf("-----EMPLOYEE LIST-----\n\n");
	for (int i = 0; i < count; i++)   //print employee list
	{
		printf("RRN: %s\n", employee[i].RRN);
		printf("NAME: %s\n", employee[i].name);
		printf("SALARY: %.3f\n", employee[i].salary);
		printf("BONUS: %.3f\n\n", employee[i].bonus);
	}
}