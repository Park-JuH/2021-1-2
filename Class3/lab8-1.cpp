#include <stdio.h>
#include <string.h>

struct ADDRESS
{
	char first[4];
	char hypen;
	char second[5];
}address[1000];

struct DECOM
{
	char firNum[4];
	char secNum[5];
}decomNum[1000];
bool readFile(char fname[], int* count);

bool compressedFile(char fname[], int* count);

bool decompressedFile(char fname[], int* count);

int main()
{
	int count = 0;
	char fname[20] = "address.txt";
	if (!readFile(fname, &count))
	{
		return -1;
	}
	strcpy(fname, "compressed.txt");
	if (!compressedFile(fname, &count))
	{
		return -1;
	}
	if (!decompressedFile(fname, &count))
	{
		return -1;
	}
	return 0;
}

bool readFile(char fname[], int* count)
{
	FILE* pfile;
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	while (fscanf(pfile, "%s %c %s", &address[*count].first, &address[*count].hypen, &address[*count].second) == 3)
	{
		*count += 1;
	}
	fclose(pfile);
	return true;
}

bool compressedFile(char fname[], int* count)
{
	FILE* pfile;
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	for (int i = 0; i < *count; i++)
		fprintf(pfile, "%s%s", address[i].first, address[i].second);
	fclose(pfile);
	return true;
}

bool decompressedFile(char fname[], int* count)
{
	FILE* pfile;
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	for (int i = 0; i < *count; i++)
	{
		fgets(decomNum[i].firNum, 4, pfile);
		fgets(decomNum[i].secNum, 5, pfile);
	}
	fclose(pfile);
	strcpy(fname, "decompressed.txt");
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	for (int i = 0; i < *count; i++)
	{
		fprintf(pfile, "%s", decomNum[i].firNum);
		fprintf(pfile, " - ");
		fprintf(pfile, "%s   ", decomNum[i].secNum);
	}
	fclose(pfile);
	return true;
}