//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

bool salary2_Write(char fname[]);
bool salary3_Write(char fname[]);
bool file_Read(char fname[]);
void compare(char fname1[], char fname3[]);

struct SALARY
{
	char name[10];
	int age;
	float salary;
}salary[20];

struct V1
{
	char name[10];
	int age;
	float salary;
}v1[20];

struct V3
{
	char name[10];
	int age;
	float salary;
}v3[20];

int main()
{
	char fname1[20] = "salary_v1.txt";
	char fname3[20] = "salary_v3.txt";
	char fname[20] = "salary_v1.txt";
	if (!file_Read(fname))
	{
		return -1;
	}
	strcpy(fname, "salary_v2.txt");
	if (!salary2_Write(fname))
	{
		return -1;
	}
	strcpy(fname, "salary_v3.txt");
	if (!salary3_Write(fname))
	{
		return -1;
	}
	compare(fname1, fname3);
	return 0;
}

bool file_Read(char fname[])
{
	FILE* pfile;
	int i = 0;
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	while (fscanf(pfile, "%s %d %f", &salary[i].name, &salary[i].age, &salary[i].salary) == 3)
	{
		i++;
	}
	fclose(pfile);
	return true;
}

bool salary2_Write(char fname[])
{
	FILE* pfile;
	for (int i = 0; i < 20; i++)
	{
		if (salary[i].age / 10 == 4)
			salary[i].salary *= 1.1f;
	}
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	fprintf(pfile, "Name\tAge\tSalary\n");
	for (int i = 0; i < 20; i++)
	{
		fprintf(pfile, "%-5s\t%d\t%.1f\n", salary[i].name, salary[i].age, salary[i].salary);
	}
	fclose(pfile);
	return true;
}

bool salary3_Write(char fname[])
{
	FILE* pfile;
	for (int i = 0; i < 20; i++)
	{
		if (salary[i].age / 10 == 3)
			salary[i].salary *= 1.2f;
	}
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	fprintf(pfile, "Name\tAge\tSalary\n");
	for (int i = 0; i < 20; i++)
	{
		fprintf(pfile, "%-5s\t%d\t%.1f\n", salary[i].name, salary[i].age, salary[i].salary);
	}
	fclose(pfile);
	return true;
}

void compare(char fname1[], char fname3[])
{
	char name[10], age[10], salary[10];
	FILE* pfile = NULL;
	int i = 0;
	pfile = fopen(fname1, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return;
	}
	while (fscanf(pfile, "%s %d %f", &v1[i].name, &v1[i].age, &v1[i].salary) == 3)
	{
		i++;
	}
	fclose(pfile);
	i = 0;
	pfile = fopen(fname3, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return;
	}
	fscanf(pfile, "%s %s %s", &name, &age, &salary);
	while (fscanf(pfile, "%s %d %f", &v3[i].name, &v3[i].age, &v3[i].salary) == 3)
	{
		i++;
	}
	for (i = 0; i < 20; i++)
	{
		if (v1[i].salary < v3[i].salary)
			printf("%-5s\t%d\t%.1f -> %.1f Different\n", v3[i].name, v3[i].age, v1[i].salary, v3[i].salary);
		else
			printf("%-5s\t%d\t%.1f -> %.1f\n", v3[i].name, v3[i].age, v1[i].salary, v3[i].salary);
	}
	fclose(pfile);
}