#include <stdio.h>
#include <stdlib.h>

struct NUM
{
	int key;
	struct NUM* next;
};

int insertKey(struct NUM* head, int num);

int ClearList(struct NUM* head);

int main()
{
	struct NUM* head;
	head = (struct NUM*)malloc(sizeof(struct NUM));
	if (head == (struct NUM*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}
	head->key = 0;
	int nums[10] = { 17, 39, 11, 9, 42, 12, 15, 8, 13, 41 };
	for (int i = 0; i < 10; i++)
	{
		printf("//---Inserting Key : %d\n", nums[i]);
		if (insertKey(head, nums[i]))
			printf("Inserting error!\n");
		
	}
	struct NUM* ptr = head->next;
	int i = 0;
	printf("\nTraversing the linked list..\n");
	while (ptr->next != NULL)
	{
		printf("node[%d] key: %d\n", i, ptr->key);
		ptr = ptr->next;
		i++;
	}
	printf("node[%d] key: %d\n", i, ptr->key);
	printf("\nDeleting the linked list..\n");
	int delNode = 0;
	while (head->next != NULL)
	{
		if(ClearList(head))
			printf("Clear error!\n");
		printf("node[%d] deleted..\n", delNode);
		delNode++;
	}
	return 0;
}

int insertKey(struct NUM *head, int num)
{
	struct NUM* ptr = head->next, *prev = head;
	struct NUM* newNode;
	newNode = (struct NUM*)malloc(sizeof(struct NUM));
	if (newNode == (struct NUM*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}
	newNode->key = num;
	while (1)
	{
		if (head->key == 0)
		{
			head->next = newNode;
			newNode->key = num;
			newNode->next = NULL;
			head->key += 1;
			printf("[%d] elements. Key inserted..\n", head->key);
			return 0;
		}
		else if (ptr->key < num)
		{
			if (ptr->next == NULL)
			{
				ptr->next = newNode;
				newNode->next = NULL;
				head->key += 1;
				printf("[%d] elements. Key inserted..\n", head->key);
				return 0;
			}
			prev = ptr;
			ptr = ptr->next;
		}
		else
		{
			newNode->next = ptr;
			prev->next = newNode;
			head->key += 1;
			printf("[%d] elements. Key inserted..\n", head->key);
			return 0;
		}
	}
}
int ClearList(struct NUM* head)
{
	struct NUM* ptr = head->next;
	struct NUM* temp;
	temp = ptr->next;
	head->next = temp;
	free(ptr);

	return 0;
}