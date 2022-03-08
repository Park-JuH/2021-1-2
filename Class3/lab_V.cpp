#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

bool ageFile_Write(char fname[]);
bool hobbyFile_Write(char fname[]);
bool file_Read(char fname[]);
void decompose_V();

struct PERSONAL
{
	char name[10];
	int age;
	char hobby[20];
}personal[20], age10[20], age20[20], age30[20], age40[20];

struct AGE
{
	char name[10];
	int age;
}agePersonal[20];

struct HOBBY
{
	char name[10];
	char hobby[10];
}hobbyPersonal[20];

int main()
{
	char fname[20] = "personal.txt";
	if (!file_Read(fname))
	{
		return -1;
	}
	decompose_V();
	strcpy(fname, "age.txt");
	if (!ageFile_Write(fname))
	{
		return -1;
	}
	strcpy(fname, "hobby.txt");
	if (!hobbyFile_Write(fname))
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

bool ageFile_Write(char fname[])
{
	FILE* pfile;
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	fprintf(pfile, "Name\tAge\n");
	for (int i = 0; i < 20; i++)
	{
		fprintf(pfile, "%-5s\t%d\n", agePersonal[i].name, agePersonal[i].age);
	}
	fclose(pfile);
	return true;
}

bool hobbyFile_Write(char fname[])
{
	FILE* pfile;
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	fprintf(pfile, "Name\tHobby\n");
	for (int i = 0; i < 20; i++)
	{
		fprintf(pfile, "%-5s\t%s\n", hobbyPersonal[i].name, hobbyPersonal[i].hobby);
	}
	fclose(pfile);
	return true;
}

void decompose_V()
{
	for (int i = 0; i < 20; i++)
	{
		strcpy(agePersonal[i].name, personal[i].name);
		agePersonal[i].age = personal[i].age;
		strcpy(hobbyPersonal[i].name, personal[i].name);
		strcpy(hobbyPersonal[i].hobby, personal[i].hobby);
	}
}