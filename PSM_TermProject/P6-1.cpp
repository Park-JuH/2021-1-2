//Problem [6-1]
//Author: 202135772 Park Juhyeok
//Step 1: Read file and store data in the DATA struct by using array.
//Step 2: Sort data by tag number in the DATA struct.
//Step 3: Remove Choi's data in the sorted data and print data.
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

struct LOST_TAG
{
	int lostTag;
}choiTag[5];

bool read_file(char fname[], int* count);

bool sorted_data(int* count);

bool remove_choi(int* count, int* removeCount);

int main()
{
	int count = 0;
	int removeCount = 0;
	char fname[30] = "registraion_data.txt";

	if (!read_file(fname, &count))
		return -1;
	if (!sorted_data(&count))
		return -1;
	if (!remove_choi(&count, &removeCount))
		return -1;
	for (int i = 0; i < count - removeCount; i++)
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

//Sort struct data by tag number
bool sorted_data(int* count)
{
	struct DATA temp;
	for (int i = 0; i < *count; i++)
	{
		for (int j = 0; j < *count; j++)
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

//Search Choi and remove Choi's data
bool remove_choi(int* count, int* removeCount)
{
	struct DATA temp;
	char name[5] = "Choi";
	int found = 0;
	int choiNum;
	int tagCount = 0;
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
			choiTag[tagCount].lostTag = registration[i].tag;
			tagCount++;
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