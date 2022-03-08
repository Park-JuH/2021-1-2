#include <stdio.h>

struct NODE
{
	int key;
	struct NODE* next;
};

void main()
{
	struct NODE node[5] = { {1, &node[1] }, { 2, &node[2] }, { 3, &node[3] }, { 4, &node[4] }, { 5, NULL } };
	struct NODE* ptr;
	ptr = &node[0];

	while (ptr->next != NULL)
	{
		printf("key: %d\n", ptr->key);
		ptr = ptr->next;
	}
	printf("key: %d", ptr->key);
}