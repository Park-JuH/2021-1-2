#include <stdio.h>
#define MAXNUM 50
void word_count(char arr[]);

void main()
{
	char arr[MAXNUM];
	gets(arr);

	/* store into the miles array */
	word_count(arr);
}
void word_count(char arr[])
{
	int i, count = 0;
	for (i = 0; arr[i] != '\0'; i = i + 1)
	{
		int j = i;
		if (arr[i] == ' ' && arr[i + 1] != ' ' && i != 0 && arr[i + 1] != '\0')
		{
			while (j != 0)
			{
				if (arr[j] != ' ')
				{
					count++;
					break;
				}
				else
					j--;
			}
		}
	}
	count++;
	printf("word count is %d", count);
}
