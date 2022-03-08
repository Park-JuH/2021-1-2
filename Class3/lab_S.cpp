#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

bool file_Read(char fname[], int* count);
void percentage(int* count);
void third_percentage(int* count);
void tenth_percentage(int* count);

struct VOTE
{
	char region[20];
	int age;
	char candidateVoted[20];
}vote[2000];

int main()
{
	int count = 0;
	char fname[20] = "vote.txt";
	if (!file_Read(fname, &count))
	{
		return -1;
	}
	percentage(&count);
	third_percentage(&count);
	tenth_percentage(&count);
	return 0;
}

bool file_Read(char fname[], int* count)
{
	FILE* pfile;
	int i = 0;
	char region[20];
	int age;
	char candidateVoted[20];
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	while (fscanf(pfile, "%s %d %s", &vote[i].region, &vote[i].age, &vote[i].candidateVoted) == 3)
	{
		i++;
		*count += 1;
	}
	fclose(pfile);
	return true;
}

void percentage(int* count)
{
	int countW = 0, countL = 0, countR = 0;
	char washington[20] = "Washington";
	char lincoln[20] = "Lincoln";
	char roosevelt[20] = "Roosevelt";

	for (int i = 0; i < *count; i++)
	{
		if (vote[i].candidateVoted[0] == washington[0])
		{
			for (int j = 0; j < strlen(washington); j++)
			{
				if (vote[i].candidateVoted[j] != washington[j])
					break;
				if (j == strlen(washington) - 1)
					countW++;
			}
		}
		else if (vote[i].candidateVoted[0] == lincoln[0])
		{
			for (int j = 0; j < strlen(lincoln); j++)
			{
				if (vote[i].candidateVoted[j] != lincoln[j])
					break;
				if (j == strlen(lincoln) - 1)
					countL++;
			}
		}
		else if (vote[i].candidateVoted[0] == roosevelt[0])
		{
			for (int j = 0; j < strlen(roosevelt); j++)
			{
				if (vote[i].candidateVoted[j] != roosevelt[j])
					break;
				if (j == strlen(roosevelt) - 1)
					countR++;
			}
		}
		else
			printf("%s is invalid value.", vote[i].candidateVoted);
	}
	printf("Total vote: %d\n\n", *count);
	printf("Percentage\n\n");
	printf("Washington: %.1f\nLincoln: %.1f\nRoosevelt: %.1f\n\n", ((float)countW / (double)*count) * 100.0, ((float)countL / (double)*count) * 100, ((float)countR / (double)*count) * 100);
}

void third_percentage(int* count)
{
	int countW = 0, countL = 0, countR = 0, thirdCount = 0;
	char washington[20] = "Washington";
	char lincoln[20] = "Lincoln";
	char roosevelt[20] = "Roosevelt";

	for (int i = 0; i < *count; i += 3)
	{
		if (vote[i].candidateVoted[0] == washington[0])
		{
			for (int j = 0; j < strlen(washington); j++)
			{
				if (vote[i].candidateVoted[j] != washington[j])
					break;
				if (j == strlen(washington) - 1)
					countW++;
			}
		}
		else if (vote[i].candidateVoted[0] == lincoln[0])
		{
			for (int j = 0; j < strlen(lincoln); j++)
			{
				if (vote[i].candidateVoted[j] != lincoln[j])
					break;
				if (j == strlen(lincoln) - 1)
					countL++;
			}
		}
		else if (vote[i].candidateVoted[0] == roosevelt[0])
		{
			for (int j = 0; j < strlen(roosevelt); j++)
			{
				if (vote[i].candidateVoted[j] != roosevelt[j])
					break;
				if (j == strlen(roosevelt) - 1)
					countR++;
			}
		}
		else
			printf("%s is invalid value.", vote[i].candidateVoted);
		thirdCount++;
	}
	printf("Total vote: %d\n\n", thirdCount);
	printf("Percentage\n\n");
	printf("Washington: %.1f\nLincoln: %.1f\nRoosevelt: %.1f\n\n", ((float)countW / (double)thirdCount) * 100.0, ((float)countL / (double)thirdCount) * 100, ((float)countR / (double)thirdCount) * 100);
}

void tenth_percentage(int* count)
{
	int countW = 0, countL = 0, countR = 0, tenthCount = 0;
	char washington[20] = "Washington";
	char lincoln[20] = "Lincoln";
	char roosevelt[20] = "Roosevelt";

	for (int i = 0; i < *count; i += 10)
	{
		if (vote[i].candidateVoted[0] == washington[0])
		{
			for (int j = 0; j < strlen(washington); j++)
			{
				if (vote[i].candidateVoted[j] != washington[j])
					break;
				if (j == strlen(washington) - 1)
					countW++;
			}
		}
		else if (vote[i].candidateVoted[0] == lincoln[0])
		{
			for (int j = 0; j < strlen(lincoln); j++)
			{
				if (vote[i].candidateVoted[j] != lincoln[j])
					break;
				if (j == strlen(lincoln) - 1)
					countL++;
			}
		}
		else if (vote[i].candidateVoted[0] == roosevelt[0])
		{
			for (int j = 0; j < strlen(roosevelt); j++)
			{
				if (vote[i].candidateVoted[j] != roosevelt[j])
					break;
				if (j == strlen(roosevelt) - 1)
					countR++;
			}
		}
		else
			printf("%s is invalid value.\n", vote[i].candidateVoted);
		tenthCount++;
	}
	printf("Total vote: %d\n\n", tenthCount);
	printf("Percentage\n\n");
	printf("Washington: %.1f\nLincoln: %.1f\nRoosevelt: %.1f\n\n", ((float)countW / (double)tenthCount) * 100, ((float)countL / (double)tenthCount) * 100, ((float)countR / (double)tenthCount) * 100);
}