//Problem [Selection sort]
//Author: 202135772 Park Juhyeok
//Step 1: Read file and store data in the DATA struct by using array.
//Step 2: Sort data by an age group number in the DATA struct by selection sort.
#include <stdio.h>
#include <string.h>

struct DATA
{
	int tag;
	char date[20];
	char feePaid[4];
	char name[25];
	int age;
	char organization[35];
	char job[15];
}registration[100];

struct NODE
{
	int tag;
	char date[20];
	char feePaid[4];
	char name[25];
	int age;
	char organization[35];
	char job[15];
	struct NODE* next;
};

struct TEMP
{
	char tmp[100];
}tmpData[100];

bool read_file(char fname[], int* count);

bool selection_sort(int* count);

int main()
{
	int count = 0;
	char fname[30] = "registraion_data.txt";

	if (!read_file(fname, &count))
		return -1;
	if (!selection_sort(&count))
		return -1;
	for (int i = 0; i < count; i++)
	{
		printf(" %d %s %s %s %d %s %s\n\n", registration[i].tag, registration[i].date, registration[i].feePaid, registration[i].name, registration[i].age, registration[i].organization, registration[i].job);
	}
	return 0;
}

//Read file and store data in the DATA struct
bool read_file(char fname[], int* count)
{
	char tmp[100];
	FILE* pfile;
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("file not open!\n");
		return false;
	}
	while (fgets(tmpData[*count].tmp, 100, pfile))
	{
		*count += 1;
	}
	for (int i = 0; i < *count; i++)
	{
		int inputCount = 0;
		int slashCount = 0;
		for (int j = 0; tmpData[i].tmp[j] != '\n'; j++)
		{
			if (j == 0)
				continue;
			else if (j == 1 && tmpData[i].tmp[j] == '/')
			{
				registration[i].tag = tmpData[i].tmp[0] - 48;
				continue;
			}
			else if (j + 1 == 2 && tmpData[i].tmp[j + 1] == '/')
			{
				registration[i].tag = (tmpData[i].tmp[0] - 48) * 10;
				registration[i].tag += tmpData[i].tmp[1] - 48;
				j++;
				continue;
			}

			if (tmpData[i].tmp[j] == '/')
			{
				inputCount = 0;
				slashCount++;
				continue;
			}
			else if (slashCount == 0)
			{
				registration[i].date[inputCount] = tmpData[i].tmp[j];
				inputCount++;
			}
			else if (slashCount == 1)
			{
				registration[i].feePaid[inputCount] = tmpData[i].tmp[j];
				inputCount++;
			}
			else if (slashCount == 2)
			{
				registration[i].name[inputCount] = tmpData[i].tmp[j];
				inputCount++;
			}
			else if (slashCount == 3)
			{
				registration[i].age = (tmpData[i].tmp[j] - 48) * 10;
				registration[i].age += tmpData[i].tmp[j + 1] - 48;
				j++;
			}
			else if (slashCount == 4)
			{
				registration[i].organization[inputCount] = tmpData[i].tmp[j];
				inputCount++;
			}
			else if (slashCount == 5)
			{
				registration[i].job[inputCount] = tmpData[i].tmp[j];
				inputCount++;
			}

		}
	}
	fclose(pfile);
	return true;
}

//Selction sort struct data by age
bool selection_sort(int* count)
{
	struct DATA temp;
	int min;
	for (int i = 0; i < *count - 1; i++)
	{
		min = i;
		for (int j = i; j < *count; j++)
		{
			if (registration[min].age > registration[j].age)
				min = j;
		}
		if (min != i)
		{
			strcpy(temp.name, registration[i].name);
			strcpy(temp.date, registration[i].date);
			strcpy(temp.feePaid, registration[i].feePaid);
			strcpy(temp.organization, registration[i].organization);
			strcpy(temp.job, registration[i].job);
			temp.tag = registration[i].tag;
			temp.age = registration[i].age;

			strcpy(registration[i].name, registration[min].name);
			strcpy(registration[i].date, registration[min].date);
			strcpy(registration[i].feePaid, registration[min].feePaid);
			strcpy(registration[i].organization, registration[min].organization);
			strcpy(registration[i].job, registration[min].job);
			registration[i].tag = registration[min].tag;
			registration[i].age = registration[min].age;

			strcpy(registration[min].name, temp.name);
			strcpy(registration[min].date, temp.date);
			strcpy(registration[min].feePaid, temp.feePaid);
			strcpy(registration[min].organization, temp.organization);
			strcpy(registration[min].job, temp.job);
			registration[min].tag = temp.tag;
			registration[min].age = temp.age;
		}
	}
	return true;
}