// Problem [2-2]
// Author : 202135764 Ryu Gernwoo
//Step 1: Read file and store data in the DATA struct by using array.
//Step 2: Create a linked list in the data.
//Step 3: Search people's data whose organization is gachon university and print the data.
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

// Receive data from a file and copy it to the struct
bool read_file(char fname[], int* count);

// Make linked lists by using malloc
bool make_linked(int* count, struct NODE* head);

// Print people whose organization is gachon university
bool write_file(struct NODE* head);

struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
struct NODE* prev = (struct NODE*)malloc(sizeof(struct NODE));

int main()
{
	struct NODE* head = (struct NODE*)malloc(sizeof(struct NODE));
	if (head == (struct NODE*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}

	int count = 0;
	char fname[30] = "registraion_data.txt";

	if (!read_file(fname, &count))
		return -1;

	if (!make_linked(&count, head))
		return -1;

	struct NODE* ptr = head->next;

	printf("[Gachon University]\n\n");
	if (!write_file(head))
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

//Link the DATA with malloc
bool make_linked(int* count, struct NODE* head)
{
	for (int i = 0; i < *count; i++)
	{
		struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
		if (newNode == (struct NODE*)NULL)
		{
			printf("malloc failed");
			exit(1);
		}
		newNode->next = NULL;
		newNode->tag = registration[i].tag;
		newNode->age = registration[i].age;
		strcpy(newNode->date, registration[i].date);
		strcpy(newNode->feePaid, registration[i].feePaid);
		strcpy(newNode->name, registration[i].name);
		strcpy(newNode->organization, registration[i].organization);
		strcpy(newNode->job, registration[i].job);
		if (i == 0)
		{
			head->next = newNode;
			node = newNode;
			prev = newNode;
		}
		else
		{
			node->next = newNode;
			node = newNode;
		}
	}
	return true;
}

bool write_file(struct NODE* head)
{
	struct NODE* ptr = head->next;
	char organization[18] = "Gachon University";
	int found = 0;
	while (ptr)
	{
		for (int j = 0; ptr->organization[j] != '\0'; j++)
		{
			if (ptr->organization[j] == organization[0])
			{
				j++;
				found = 0;
				for (int k = 1; k < 17; k++)
				{
					if (ptr->organization[j] != organization[k])
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
			printf(" %d %s %s %s %d %s %s\n\n", ptr->tag, ptr->date, ptr->feePaid, ptr->name, ptr->age, ptr->organization, ptr->job);
			found = 0;
		}
		ptr = ptr->next;
	}
	return true;
}