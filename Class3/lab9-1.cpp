#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int key;
	struct NODE *next;
};

int insertKey(struct NODE *head, int newKey, struct NODE* first);

void ScanList(struct NODE* head);

int main()
{
	int condition;
	struct NODE *node;
	struct NODE *head = (struct NODE*)malloc(sizeof(struct NODE));
	if (head == (struct NODE*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}
	node = (struct NODE*)malloc(sizeof(struct NODE) * 7);
	if (node == (struct NODE*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}
	struct NODE* first = (struct NODE*)malloc(sizeof(struct NODE));
	if (first == (struct NODE*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}
	node[0].key = 100;
	node[0].next = &node[1];
	node[1].key = 250;
	node[1].next = &node[2];
	node[2].key = 467;
	node[2].next = NULL;

	int newKey[4] = { 250, 300, 50, 500 };
	head->next = &node[0];

	for (int i = 0; i < 4; i++)
	{
		printf("//---Inserting Key : %d\n", newKey[i]);
		if (insertKey(head, newKey[i], first) == 0)
			printf("Key inserted..\n");
		else
			printf("Key already exists..\n");
	}
	ScanList(head);
	free(node);
	return 0;
}

int insertKey(struct NODE *head, int newKey, struct NODE *first)
{
	struct NODE* tmp = head->next;
	struct NODE *ptr = head->next, *prev = head;
	struct NODE *newNode;
	newNode = (struct NODE*)malloc(sizeof(struct NODE));
	if (newNode == (struct NODE*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}
	newNode->key = newKey;
	newNode->next = NULL;
	while (ptr)
	{
		if (ptr->key == newNode->key)
		{
			return -1;
		}
		else if (ptr->key < newNode->key)
		{
			if (ptr->next == NULL)
			{
				ptr->next = newNode;
				newNode->next = NULL;
				return 0;
			}
			prev = ptr;
			ptr = ptr->next;
		}
		else
		{
			newNode->next = ptr;
			prev->next = newNode;
			if (tmp != head->next)
				first = head->next;
			else
				first = NULL;
			return 0;
		}
	}
}

void ScanList(struct NODE* head)
{
	struct NODE* ptr = head->next;
	int i = 0;
	printf("\nTraversing the linked list..\n");
	while (ptr->next != NULL)
	{
		printf("node[%d] key: %d\n", i, ptr->key);
		ptr = ptr->next;
		i++;
	}
	printf("node[%d] key: %d\n", i, ptr->key);
}