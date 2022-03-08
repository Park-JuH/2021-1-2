#include <stdio.h>
#include <string.h>

struct DATA
{
	char word[100];
}data[1000];

bool readFile(char fname[], int* count);

bool cypherFile(char fname[], int* key, int* count);

bool decryptedFile(char fname[], int* key, int* count);

int main()
{
	int key = 3;
	int count = 0;
	char fname[20] = "original.txt";
	if(!readFile(fname, &count))
		return -1;
	strcpy(fname, "cypher.txt");
	if (!cypherFile(fname, &key, &count))
		return -1;
	if (!decryptedFile(fname, &key, &count))
		return -1;
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
	while (fgets(data[*count].word, 100, pfile))
	{
		*count += 1;
	}
	fclose(pfile);
	return true;
}

bool cypherFile(char fname[], int* key, int* count)
{
	FILE* pfile;
	pfile = fopen(fname, "w");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}

	for (int i = 0; i < *count; i++)
	{
		int j = 0;
		while (data[i].word[j] != '\0')
		{
			data[i].word[j] += *key;
			fprintf(pfile, "%c", data[i].word[j]);
			j++;
		}
	}

	fclose(pfile);
	return true;
}

bool decryptedFile(char fname[], int* key, int* count)
{
	int cyCount = 0;
	char cyWord[1000];
	FILE* pfile;
	pfile = fopen(fname, "r");
	if (pfile == NULL)
	{
		printf("Cannot open the file!!\n");
		return false;
	}
	while (fscanf(pfile, "%c", &cyWord[cyCount]) == 1)
	{
		cyCount++;
	}
	fclose(pfile);
	strcpy(fname, "decrypted.txt");
	pfile = fopen(fname, "w");
	for (int i = 0; i < cyCount; i++)
	{
		cyWord[i] -= *key;
		fprintf(pfile, "%c", cyWord[i]);
	}

	fclose(pfile);
	return true;

}