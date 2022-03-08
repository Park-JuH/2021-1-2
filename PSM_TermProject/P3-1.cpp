//Problem [3-1]
//Author: 202135745 Kim Yiyoung
//Step 1: Use overlapping for loop within the total count.
//Step 2: Use a conditional statement when the tag in the back array is larger than the tag in the front array.
//Step 3: Rearrange the tags in order using temp.
//Step 4 :Output the result from the main function.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DATA
{
	int tag;
	char date[20];
	char feePaid[4];
	char name[20];
	int age;
	char organization[35];
	char job[15];
}registration[100] = { 0, };

struct TEMP
{
	char tmp[100];
}tmpData[100] = { 0, };

bool readFile(const char* fname, int* count);

bool sorted_data(int count);

int main()
{
	int count = 0;
	char fname[64] = "registraion_data.txt";

	if (!readFile(fname, &count))
	{
		return -1;
	}
	sorted_data(count);
	for (int i = 0; i < count; i++)
	{
		printf("%d %s %s %s %d %s %s\n\n", registration[i].tag, registration[i].date, registration[i].feePaid, registration[i].name, registration[i].age, registration[i].organization, registration[i].job);
	}
}
bool readFile(const char* fname, int* count)
{
	FILE* pFile;
	pFile = fopen(fname, "r");

	if (pFile == NULL)
	{
		printf("error\n");
		*count = 0;
		return false;
	}
	TEMP rtmp;
	int num = 0;
	while (fgets(tmpData[num].tmp, 100, pFile))
	{
		num += 1;
	}
	for (int i = 0; i < num; i++)
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
	fclose(pFile);
	*count = num;
	return true;
}
bool sorted_data(int count)
{
	struct DATA temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (registration[i].tag < registration[j].tag)
			{
				strcpy(temp.name, registration[i].name);
				strcpy(temp.date, registration[i].date);
				strcpy(temp.feePaid, registration[i].feePaid);
				strcpy(temp.organization, registration[i].organization);
				strcpy(temp.job, registration[i].job);
				temp.tag = registration[i].tag;
				temp.age = registration[i].age;

				strcpy(registration[i].name, registration[j].name);
				strcpy(registration[i].date, registration[j].date);
				strcpy(registration[i].feePaid, registration[j].feePaid);
				strcpy(registration[i].organization, registration[j].organization);
				strcpy(registration[i].job, registration[j].job);
				registration[i].tag = registration[j].tag;
				registration[i].age = registration[j].age;

				strcpy(registration[j].name, temp.name);
				strcpy(registration[j].date, temp.date);
				strcpy(registration[j].feePaid, temp.feePaid);
				strcpy(registration[j].organization, temp.organization);
				strcpy(registration[j].job, temp.job);
				registration[j].tag = temp.tag;
				registration[j].age = temp.age;
			}
		}
	}
	return true;
}