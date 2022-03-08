#include <stdio.h>
#include <string.h>

#define SIZE 5
#define TEST_SIZE 3

struct DATASET
{
	char name[10];
	int age;
	char hobby[10];
}dataset[SIZE] = { {"Kim", 39, "Tennis"}, {"Ko", 15, "Soccer"},  {"Lee", 17, "Tennis"}, {"Choi", 21, "Tennis"}, {"Park", 10, "Tennis"} };

struct INDEX
{
	char key[10];
	int index;
}dataIndex[SIZE] = { {"Kim", 0}, {"Ko", 1}, {"Lee", 2}, {"Choi", 3}, {"Park", 4} };

int searchIndex(char testSearchKeys[TEST_SIZE][10], int size);

void main()
{
	char testSearchKeys[TEST_SIZE][10] = { "Cha", "Lee", "Park" };
	for (int i = 0; i < TEST_SIZE; i++)
	{
		int index = searchIndex(testSearchKeys, i);
		printf("\n--- Experiment (%d) ---\n", i + 1);
		printf("[Key:] %s\n", testSearchKeys[i]);
		if (index < 0)
		{
			printf("The Key does not exist !!\n");
		}
		else
		{
			printf("result: index(%d), name(%s), age(%d), hobby(%s)\n", index, dataset[index].name, dataset[index].age, dataset[index].hobby);
		}
	}
}

int searchIndex(char testSearchKeys[TEST_SIZE][10], int size)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (dataIndex[i].key[0] == testSearchKeys[size][0])
		{
			int count = 0;
			for (int j = 0; testSearchKeys[size][j] != '\0'; j++)
			{
				if (dataIndex[i].key[j] == testSearchKeys[size][j])
				{
					count++;
				}
				else
					break;
				if (count == strlen(testSearchKeys[size]))
					return dataIndex[i].index;
			}
		}
	}
	return -1;
}