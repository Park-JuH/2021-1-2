//Problem [1-2]
//Author: 202135772 Park Juhyeok
//Step 1: Read file and store data in the DATA struct by using array.
//Step 2: Create a linked list in the data.
//Step 3: Search people's data whose name is choi and print the data.
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

bool choi_print(struct NODE* head);

bool make_linked(int* count, struct NODE* head);

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
	if (!choi_print(head))
		return -1;
	
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

//Search Choi and print Choi's data
bool choi_print(struct NODE* head)
{
	node = head->next;
	prev = head;
	char name[5] = "Choi";
	int found = 0;
	while (node)
	{
		for (int j = 0; node->name[j] != '\0'; j++)
		{
			if (node->name[j] == name[0])
			{
				j++;
				found = 0;
				for (int k = 1; k < 4; k++)
				{
					if (node->name[j] != name[k])
						break;
					else if (k == 3)
						found = 1;
					else
						j++;
				}
			}
		}
		if (found == 1)
		{
			printf(" %d %s %s %s %d %s %s\n\n", node->tag, node->date, node->feePaid, node->name, node->age, node->organization, node->job);
			found = 0;
		}
		node = node->next;
	}
	return true;
}