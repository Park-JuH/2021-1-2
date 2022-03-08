//Problem [7-1]
//Author: 202135745 Kim Yiyoung
//Step 1: Save the new Paik data in the registration array.
//Step 2: Read the tag of the original registration arrangement through the for loop and save the unique tag as Paik tag
//Step 3: Call the sorted function and arrange the inserted data to be sorted.
//Step 4 :Output the array of inserted data from the main function.
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
	char organization[20];
	char job[15];
}registration[100] = { 0, };

struct TEMP
{
	char tmp[100];
}tmpData[100] = { 0, };

bool readFile(const char* fname, int* count);

bool sorted_data(int count);

bool remove_choi(int* count, int* removeCount);

void insertPaik(int* count);

bool writeFile(const char* fname, int count);

int main()
{
	int count = 0;
	int removeCount = 0;
	char fname[64] = "registraion_data.txt";
	char fname2[64] = "P7-1.txt";

	if (!readFile(fname, &count))
		return -1;
	
	if (!sorted_data(count))
		return -1;

	if (!remove_choi(&count, &removeCount))
		return -1;

	count = count - removeCount;

	insertPaik(&count);
	
	if (!sorted_data(count))
		return -1;

	printf("---------------\n");
	for (int i = 0; i < count; i++)
	{
		printf(" %d %s %s %s %d %s %s\n\n", registration[i].tag, registration[i].date, registration[i].feePaid, registration[i].name, registration[i].age, registration[i].organization, registration[i].job);
	}

	
	return 0;
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
bool remove_choi(int* count, int* removeCount)
{
	struct DATA temp;
	char name[5] = "Choi";
	int found = 0;
	int choiNum;
	for (int i = 0; i < *count; i++)
	{
		for (int j = 0; registration[i].name[j] != '\0'; j++)
		{
			if (registration[i].name[j] == name[0])
			{
				j++;
				found = 0;
				for (int k = 1; k < 5; k++)
				{
					if (registration[i].name[j] != name[k])
						break;
					else
						j++;
					if (k == 4)
					{
						found = 1;
						choiNum = i;
					}
				}
			}
		}
		if (found == 1)
		{
			for (int x = choiNum; x < *count; x++)
			{
				strcpy(registration[x].name, registration[x + 1].name);
				strcpy(registration[x].date, registration[x + 1].date);
				strcpy(registration[x].feePaid, registration[x + 1].feePaid);
				strcpy(registration[x].organization, registration[x + 1].organization);
				strcpy(registration[x].job, registration[x + 1].job);
				registration[x].tag = registration[x + 1].tag;
				registration[x].age = registration[x + 1].age;
			}
			*removeCount += 1;
			found = 0;
			i--;
		}
	}
	return true;
}
void insertPaik(int* count)
{
	strcpy(registration[*count].name, "Gildong Paik");
	strcpy(registration[*count].date, "2020-11-30");
	strcpy(registration[*count].feePaid, "yes");
	strcpy(registration[*count].organization, "Gachon University");
	strcpy(registration[*count].job, "Student");
	registration[*count].age = 35;

	for (int i = 0; i < *count + 1; i++)
	{
		if (i + 1 == registration[*count].tag)
			continue;
		else 
		{
			registration[*count].tag = i + 1;
			break;
		}
			

	}
	*count += 1;
}
bool writeFile(const char* fname, int count)
{
	FILE* pFile;
	pFile = fopen(fname, "w");
	if (pFile == NULL)
	{
		printf("error");
		return false;
	}
	for (int i = 0; i < count; i++)
	{
		fprintf(pFile, "%d %s %s %s %d %s %s\n",
			registration[i].tag,
			registration[i].date,
			registration[i].feePaid,
			registration[i].name,
			registration[i].age,
			registration[i].organization,
			registration[i].job);
	}
	fclose(pFile);
	return true;


}
