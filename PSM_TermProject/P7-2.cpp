//Problem [7-2]
//Author: 202135745 Kim Yiyoung
//Step 1: Temporary storage of Paik data in the new struct NODE.
//Step 2:  Find a unique tag as a conditional statement within a while loop.
//Step 3: Separate the case where the tag is 1 and the case where it is not, and store it in the linked list, respectively.
//Step 4 :Output the linked list of inserted data from the main function.
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

struct LOST_TAG
{
	int lostTag;
}choiTag[5];

bool read_file(char fname[], int* count);

bool sorted_data(int* count);

bool remove_choi(struct NODE* head);

bool make_linked(int* count, struct NODE* head);

bool insertPaik(struct NODE& head);


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

	sorted_data(&count);

	if (!make_linked(&count, head))
		return -1;

	if (!remove_choi(head))
		return -1;


	if (!insertPaik(*head))
		return -1;
	count += 1;


	struct NODE* ptr = (struct NODE*)malloc(sizeof(struct NODE));
	ptr = head;
	while (ptr->next != NULL)
	{
		printf(" %d %s %s %s %d %s %s\n\n", ptr->tag, ptr->date, ptr->feePaid, ptr->name, ptr->age, ptr->organization, ptr->job);
 		ptr = ptr->next;
	}
	printf(" %d %s %s %s %d %s %s\n\n", ptr->tag, ptr->date, ptr->feePaid, ptr->name, ptr->age, ptr->organization, ptr->job);
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
bool remove_choi(struct NODE* head)
{
	node = head->next;
	prev = head;
	char name[5] = "Choi";
	int found = 0;
	int tagCount = 0;
	while (node)
	{
		for (int i = 0; node->name[i] != '\0'; i++)
		{
			if (node->name[i] == name[0])
			{
				i++;
				for (int j = 1; j < 4; j++)
				{
					if (node->name[i] != name[j])
						break;
					else if (j == 3)
						found = 1;
					else
						i++;
				}
			}
		}
		if (found == 1)
		{
			struct NODE* temp = (struct NODE*)malloc(sizeof(struct NODE));
			if (temp == (struct NODE*)NULL)
			{
				printf("malloc failed");
				exit(1);
			}
			choiTag[tagCount].lostTag = node->tag;
			temp = node;
			node = node->next;
			prev->next = node;
			free(temp);
			tagCount++;
			found = 0;
		}
		else
		{
			prev = node;
			node = node->next;
		}
	}
	return true;
}
bool insertPaik(struct NODE& head)
{
	struct NODE paik = { NULL };

	strcpy(paik.name, "Gildong Paik");
	strcpy(paik.date, "2020-11-30");
	strcpy(paik.feePaid, "yes");
	strcpy(paik.organization, "Gachon University");
	strcpy(paik.job, "Student");
	paik.age = 35;

	node = head.next;
	prev = &head;
	

	int taglist = 1;

	while (node)
	{
		if (node->tag == taglist)
		{
			prev = node;
			node = node->next;
			taglist++;
		}
		else if (node->tag != taglist)
		{
		
			if (taglist == 1)
			{
				strcpy(prev->name, paik.name);
				strcpy(prev->date, paik.date);
				strcpy(prev->feePaid, paik.feePaid);
				strcpy(prev->organization, paik.organization);
				strcpy(prev->job, paik.job);
				prev->age = paik.age;
				prev->tag = taglist;

				break;
			}
			else
			{
				struct NODE* temp = (struct NODE*)malloc(sizeof(struct NODE));
				if (temp == (struct NODE*)NULL)
				{
					printf("malloc failed");
					exit(1);
				}
				strcpy(temp->name, paik.name);
				strcpy(temp->date, paik.date);
				strcpy(temp->feePaid, paik.feePaid);
				strcpy(temp->organization, paik.organization);
				strcpy(temp->job, paik.job);
				temp->age = paik.age;
				temp->tag = taglist;

				prev->next = temp;
				temp->next = node;
				break;
			}
		}
	}


	return true;
}