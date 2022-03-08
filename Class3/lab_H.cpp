#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

bool file_Write(char fname[]);
bool file_Read(char fname[]);
void decompose_H();

struct PERSONAL
{
	char name[10];
	int age;
	char hobby[20];
}personal[21], age10[20], age20[20], age30[20], age40[20];

int main()
{
	char fname[20] = "personal.txt";
	if (!file_Read(fname))
	{
		return -1;
	}
	decompose_H();
	strcpy(fname, "output.txt");
	if (!file_Write(fname))
	{
		return -1;
	}
	return 0;
}

bool file_Read(char fname[])
{
	FILE* pfile;
	int i = 0;
	char name[10];
	int age;
	char hobby[20];
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	while (fscanf(pfile, "%s %d %s", &personal[i].name, &personal[i].age, &personal[i].hobby) == 3)
	{
		i++;
	}
	fclose(pfile);
	return true;
}

bool file_Write(char fname[])
{
	FILE* pfile;
	int i = 0;
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	fprintf(pfile, "Age from 10 to 19\n");
	fprintf(pfile, "------------------------\n");
	while (age10[i].age != '\0')
	{
		fprintf(pfile, "%-5s\t%d\t%s\n", age10[i].name, age10[i].age, age10[i].hobby);
		i++;
	}
	i = 0;
	fprintf(pfile, "\nAge from 20 to 29\n");
	fprintf(pfile, "------------------------\n");
	while (age20[i].age != '\0')
	{
		fprintf(pfile, "%-5s\t%d\t%s\n", age20[i].name, age20[i].age, age20[i].hobby);
		i++;
	}
	i = 0;
	fprintf(pfile, "\nAge from 30 to 39\n");
	fprintf(pfile, "------------------------\n");
	while (age30[i].age != '\0')
	{
		fprintf(pfile, "%-5s\t%d\t%s\n", age30[i].name, age30[i].age, age30[i].hobby);
		i++;
	}
	i = 0;
	fprintf(pfile, "\nAge from 40 to 49\n");
	fprintf(pfile, "------------------------\n");
	while (age40[i].age != '\0')
	{
		fprintf(pfile, "%-5s\t%d\t%s\n", age40[i].name, age40[i].age, age40[i].hobby);
		i++;
	}
	fclose(pfile);
}

void decompose_H()
{
	int count10 = 0, count20 = 0, count30 = 0, count40 = 0;
	for (int i = 0; personal[i].age != '\0'; i++)
	{
		if ((personal[i].age / 10) == 1)
		{
			strcpy(age10[count10].name, personal[i].name);
			age10[count10].age = personal[i].age;
			strcpy(age10[count10].hobby, personal[i].hobby);
			count10++;
		}
		else if ((personal[i].age / 10) == 2)
		{
			strcpy(age20[count20].name, personal[i].name);
			age20[count20].age = personal[i].age;
			strcpy(age20[count20].hobby, personal[i].hobby);
			count20++;
		}
		else if ((personal[i].age / 10) == 3)
		{
			strcpy(age30[count30].name, personal[i].name);
			age30[count30].age = personal[i].age;
			strcpy(age30[count30].hobby, personal[i].hobby);
			count30++;
		}
		else if ((personal[i].age / 10) == 4)
		{
			strcpy(age40[count40].name, personal[i].name);
			age40[count40].age = personal[i].age;
			strcpy(age40[count40].hobby, personal[i].hobby);
			count40++;
		}
		else
		{
			printf("%d is unvalid value.\n", personal[i].age);
		}
	}
}