// Problem [2-1]
// Author : 202135764 ·ù°Ç¿ì
// After checking the data in the file, re-print people whose organization is gachon university by using the array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 40

struct DATA
{
	int tag;
	char date[MAX];
	char feePaid[MAX];
	char name[MAX];
	int age;
	char organization[MAX];
	char job[MAX];
	struct DATA* next;
}registration[100];

struct TEMP
{
	char tmp[100];
}tmpData[100];

// Receive data from a file and copy it to the struct
bool read_file(char fname[], int* count);

// Print people whose organization is gachon university
bool write_file(int* count);

int main()
{
	int count = 0;
	char fname[] = "registraion_data.txt";

	if (!read_file(fname, &count))
		return -1;

	printf("[Gachon University]\n\n");

	if (!write_file(&count))
		return -1;

	return 0;
}

bool read_file(char fname[], int* count)
{
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

bool write_file(int* count)
{
	char organization[18] = "Gachon University";
	int found = 0;
	for (int i = 0; i < *count; i++)
	{
		for (int j = 0; registration[i].organization[j] != '\0'; j++)
		{
			if (registration[i].organization[j] == organization[0])
			{
				j++;
				found = 0;
				for (int k = 1; k < 17; k++)
				{
					if (registration[i].organization[j] != organization[k])
						break;
					else
						j++;
					if (k == 16)
						found = 1;
				}
			}
		}
		if (found == 1)
		{
			printf(" %d %s %s %s %d %s %s\n\n", registration[i].tag, registration[i].date, registration[i].feePaid, 
				registration[i].name, registration[i].age, registration[i].organization, registration[i].job);
			found = 0;
		}
	}

	return true;
}