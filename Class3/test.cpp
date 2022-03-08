#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int key;
	struct NODE* next;
};



int main()
{
	struct NODE* link;
	link = (struct NODE*)malloc(10 * sizeof(struct NODE));
	link->key = 1;
	link[0].key = 2;
}