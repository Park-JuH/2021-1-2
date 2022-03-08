#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QUEUE
{
	int *buf;
	int max;
	int front;
	int back;
}Queue;

void create_queue(const int size);

void release_queue();

void enqueue(const int val);

int dequeue();

bool queue_full();

bool queue_empty();


int main()
{
	create_queue(10);

	for (int i = 0; i < 11; i++)
	{
		enqueue(i + 10);
	}
	for (int i = 0; i < 11; i++)
	{
		dequeue();
	}
	release_queue();
	printf("\n");
	create_queue(50);
	for (int i = 0; i < 12; i++)
	{
		enqueue(i + 10);
	}
	for (int i = 0; i < 12; i++)
	{
		dequeue();
	}
	dequeue();
	release_queue();
	return 0;
}

void create_queue(const int size)
{
	Queue.buf = (int*)malloc(size * sizeof(int));
	if (Queue.buf == (int*)NULL)
	{
		printf("malloc is failed");
		exit(1);
	}
	memset(Queue.buf, 0, size * sizeof(int));
	Queue.max = size;
	Queue.front = -1;
	Queue.back = -1;
}

void release_queue()
{
	free(Queue.buf);
	Queue.max = 0;
	Queue.front = -1;
	Queue.back = -1;
}
void enqueue(const int val)
{
	if (queue_full())
	{
		printf("enqueue(): Queue is Full\n");
		return;
	}
	Queue.back++;
	Queue.buf[Queue.back] = val;
	printf("enqueue[%d]: %d\n", Queue.back, val);
}

int dequeue()
{
	if (queue_empty())
	{
		printf("dequeue(): Queue is Empty\n");
		return 0;
	}
	Queue.front++;
	int val = Queue.buf[Queue.front];
	printf("dequeue[%d]: %d\n", Queue.front, val);
	return val;

}

bool queue_full()
{
	return Queue.back >= Queue.max - 1;
}

bool queue_empty()
{
	return Queue.front > Queue.back - 1;
}