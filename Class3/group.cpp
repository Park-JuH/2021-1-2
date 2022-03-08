#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool Write_file(char fname[], char data[]);
bool Read_file(char fname[]);

int main()
{
	char fname[20] = "groupFile.txt";
	char data[60] = "5 96 87 78 93 21 4 92 82 85 87 6 72 69 85 75 81 73";
	if (!Write_file(fname, data))
		return -1;
	if (!Read_file(fname))
		return -1;
	return 0;
}

bool Write_file(char fname[], char data[])
{
	FILE* pfile;
	int i = 0;
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	while (data[i] != '\0')
	{
		fprintf(pfile, "%c", data[i]);
		i++;
	}
	fclose(pfile);
	return true;
}

bool Read_file(char fname[])
{
	FILE* pfile;
	int groupNum;
	int total;
	float avg;
	int i;
	int num;
	int size = 1;
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	while (fscanf(pfile, "%d", &groupNum) == 1)
	{
		i = 0;
		total = 0;
		while (i < groupNum)
		{
			fscanf(pfile, "%d", &num);
			total += num;
			i++;
		}
		avg = (float)total / (float)groupNum;
		if(size == 1)
			printf("The average of the first group of consisting %d members is %.2f\n", groupNum, avg);
		else if(size == 2)
			printf("The average of the second group of consisting %d members is %.2f\n", groupNum, avg);
		else
			printf("The average of the third group of consisting %d members is %.2f\n", groupNum, avg);
		size++;
	}
	fclose(pfile);
	return true;
}