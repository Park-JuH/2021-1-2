#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct DATA
{
	char name[20];
	char name2[20];
	int time;
	float money;
	char date[20];
}list[5] = { {"Anthony", "A.J.", 10031, 7.82, "12/18/62"}, {"Burrows", "W.K.", 10067, 9.14, "6/9/63"}, {"Fain", "B.D", 10083, 8.79, "5/18/59"}, {"Janney", "P.", 10095, 10.57, "9/28/62"}, {"Smith", "G.J", 10105, 8.50, "12/20/61"} };

bool Write_file(char fname[], int size);
bool Write_file2(char fname[], char fname2[]);

int main()
{
	char src[50];
	char dest[50];
	char fname[20] = "employee.txt";
	char fname2[20] = "employee2.txt";

	if (!Write_file(fname, 5))
		return -1;

	if (!Write_file2(fname, fname2))
		return -1;
	printf("Type Source Destination File Names!!\n");
	scanf("%s %s", &src, &dest);

	if (!Write_file2(src, dest))
		return -1;
	return 0;
}
bool Write_file(char fname[], int size)
{
	FILE* pfile;
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	for (int i = 0; i < 5; i++)
	{
		fprintf(pfile, "%s %s %d %.2f %s\n", list[i].name, list[i].name2, list[i].time, list[i].money, list[i].date);
	}
	fclose(pfile);
	return true;
}

bool Write_file2(char fname[], char fname2[])
{
	FILE* pfile, * pfile2;
	char name[20];
	char name2[20];
	int time;
	float money;
	char date[20];
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	pfile2 = fopen(fname2, "w");
	if (pfile2 == NULL)
	{
		printf("Cannot open the file2!!\n");
		return false;
	}
	while (fscanf(pfile, "%s %s %d %f %s", &name, &name2, &time, &money, &date) == 5)
		fprintf(pfile2, "%s %s %d %.2f %s\n", name, name2, time, money, date);
	fclose(pfile);
	fclose(pfile2);
	return true;
}