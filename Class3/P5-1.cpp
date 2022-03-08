// Problem [5-1]
// Author : 202135764 ·ù°Ç¿ì
// A code to sort and print data in age order using linked list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DATA
{
	int tag;
	char date[20];
	char feePaid[4];
	char name[25];
	int age;
	char organization[35];
	char job[15];
	struct DATA* next;
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

// Receive data from a file and copy it to the structure
bool read_file(char fname[], int* count);

// Sort the data values by age
bool data_sort(int* count);

// Data sorted in order of age are printed out as files
bool write_file(char fname[], const DATA registration[], int count);

int main(int argc, char* argv[])
{
	struct DATA* head = (struct DATA*)malloc(sizeof(struct DATA));
	if (head == (struct DATA*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}

	head->next = &registration[0];
	int count = 0;
	char fname[30] = "registraion_data.txt";
	char write_fname[10] = "P5-1.txt";

	if (!read_file(fname, &count))
		return -1;

	if (!write_file(write_fname, registration, count))
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

bool data_sort(int* count)
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

bool write_file(char fname[], const DATA registration[], int count)
{
	FILE* pFile;

	pFile = fopen(fname, "w");
	if (pFile == NULL)
	{
		printf("Error: Can't open the file: %s\n", fname);
		return false;
	};

	data_sort(&count);
	fprintf(pFile, "[Group by Age]\n");
	fprintf(pFile, "\n\nAge from 20 to 29\n");
	fprintf(pFile, "--------------------\n");
	for (int i = 0; i < count; i++)
	{
		if (registration[i].age > 19 && registration[i].age < 30)
		{
			fprintf(pFile, "%d/%s/%s/%s/%d/%s/%s\n",
				registration[i].tag,
				registration[i].date,
				registration[i].feePaid,
				registration[i].name,
				registration[i].age,
				registration[i].organization,
				registration[i].job);
		}
	}
	fprintf(pFile, "\n\nAge from 30 to 39\n");
	fprintf(pFile, "--------------------\n");
	for (int i = 0; i < count; i++)
	{
		if (registration[i].age > 29 && registration[i].age < 40)
		{
			fprintf(pFile, "%d/%s/%s/%s/%d/%s/%s\n",
				registration[i].tag,
				registration[i].date,
				registration[i].feePaid,
				registration[i].name,
				registration[i].age,
				registration[i].organization,
				registration[i].job);
		}
	}
	fprintf(pFile, "\n\nAge from 40 to 49\n");
	fprintf(pFile, "--------------------\n");
	for (int i = 0; i < count; i++)
	{
		if (registration[i].age > 39 && registration[i].age < 50)
		{
			fprintf(pFile, "%d/%s/%s/%s/%d/%s/%s\n",
				registration[i].tag,
				registration[i].date,
				registration[i].feePaid,
				registration[i].name,
				registration[i].age,
				registration[i].organization,
				registration[i].job);
		}
	}
	fprintf(pFile, "\n\nAge from 50 to 59\n");
	fprintf(pFile, "--------------------\n");
	for (int i = 0; i < count; i++)
	{
		if (registration[i].age > 49 && registration[i].age < 60)
		{
			fprintf(pFile, "%d/%s/%s/%s/%d/%s/%s\n",
				registration[i].tag,
				registration[i].date,
				registration[i].feePaid,
				registration[i].name,
				registration[i].age,
				registration[i].organization,
				registration[i].job);
		}
	}
	fprintf(pFile, "\n\nAge from 60 to 69\n");
	fprintf(pFile, "--------------------\n");
	for (int i = 0; i < count; i++)
	{
		if (registration[i].age > 59 && registration[i].age < 70)
		{
			fprintf(pFile, "%d/%s/%s/%s/%d/%s/%s\n",
				registration[i].tag,
				registration[i].date,
				registration[i].feePaid,
				registration[i].name,
				registration[i].age,
				registration[i].organization,
				registration[i].job);
		}
	}
	fprintf(pFile, "\n\nAge over 70 \n");
	fprintf(pFile, "--------------------\n");
	for (int i = 0; i < count; i++)
	{
		if (registration[i].age > 69)
		{
			fprintf(pFile, "%d/%s/%s/%s/%d/%s/%s\n",
				registration[i].tag,
				registration[i].date,
				registration[i].feePaid,
				registration[i].name,
				registration[i].age,
				registration[i].organization,
				registration[i].job);
		}
	}

	fprintf(pFile, "\n");

	fclose(pFile);
	return true;
}