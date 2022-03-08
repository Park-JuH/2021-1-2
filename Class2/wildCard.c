#include <stdio.h>
#include <string.h>

#define SIZE 7

int searchString(char string[SIZE][256], char firstPart[], char secondPart[], int sizeNum, int* tmp);

void divideSearchString(char search[SIZE][256], char firstPart[], char secondPart[], int sizeNum, int* tmp);

void main()
{
	char testStr[SIZE][256] = { "hello mister monkey", "hello mister monkey", "hello mister monkey", "my name is lee jongho", "my name is lee jongho", "My name is hong gil dong. My brother is hong je dong, and his friend is hong ha jin. My sister is hong gilja, and her friend is hongdong.", "A thief named hong gil dong lived with friends named hong gil don and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village." };
	char testSearchStr[SIZE][256] = { "money", "mon*ey", "m*y", "lee *ho", "lee *ha", "hong*dong", "hong gil dong" };

	for (int i = 0; i < SIZE; i++)
	{
		char first[128];
		char second[128];
		int tmp = 0;
		divideSearchString(testSearchStr, first, second, i, &tmp);
		printf("\n--- Experiment (%d) ---\n", i + 1);
		printf("[String:] %s\n", testStr[i]);
		printf("[Search:] %s\n", testSearchStr[i]);
		printf("[Search-First:] %s\n", first);
		printf("[Search-Second:] %s\n", second);
		int numMatches = searchString(testStr, first, second, i, &tmp);
		printf("[Num Matches:] %d\n", numMatches);
	}
}

void divideSearchString(char search[SIZE][256], char firstPart[], char secondPart[], int sizeNum, int* tmp)
{
	int arrSize = strlen(search[sizeNum]);
	int firstCt;
	int secondCt = 0;
	for (firstCt = 0; firstCt < arrSize; firstCt++)
	{
		if (search[sizeNum][firstCt] == '*')
		{
			firstPart[firstCt] = '\0';
			*tmp = firstCt;
			firstCt++;
			for (firstCt; firstCt < arrSize; firstCt++)
			{
				secondPart[secondCt] = search[sizeNum][firstCt];
				secondCt++;
			}
			break;
		}
		else
			firstPart[firstCt] = search[sizeNum][firstCt];
	}
	firstPart[firstCt - secondCt] = '\0';
	secondPart[secondCt] = '\0';
}

int searchString(char string[SIZE][256], char firstPart[], char secondPart[], int sizeNum, int* tmp)
{

	int count = 0;
	int cttmp = 0;
	int arrSize = strlen(string[sizeNum]);
	int firstSize = strlen(firstPart);
	if (*tmp != 0)
	{
		for (int i = 0; i < arrSize; i++)
		{
			if (string[sizeNum][i] == firstPart[0])
			{
				for (int j = 0; j < firstSize; j++)
				{
					if (string[sizeNum][i] == firstPart[j])
					{
						i++;
					}
					else
					{
						break;
					}
					cttmp = j;
				}
				if (cttmp == strlen(firstPart) - 1)
				{
					int h = 1;
					int k = 0;
					while(strlen(string[sizeNum]) != i)
					{
						if (string[sizeNum][i] == secondPart[k])
						{
							if (k == strlen(secondPart) - 1)
							{
								count++;
								break;
							}
							i++;
							k++;
						}
						else if (string[sizeNum][i] == firstPart[0])
						{
							for (h = 0; h < firstSize; h++)
							{
								if (string[sizeNum][i] == firstPart[h])
								{
									i++;
									continue;
								}
								else
									break;
							}
							if (h == strlen(firstPart))
							{
								i = i - h - 1;
								break;
							}
							else
								i++;
						}
						else
						{
							k = 0;
							i++;
						}
					}
				}
			}
		}
		return count;
	}
	else
	{
		int arrSize = strlen(firstPart);
		secondPart[0] = '\0';
		for (int i = 0; i < 256; i++)
		{
			if (string[sizeNum][i] == firstPart[0])
			{
				int anslen = 0;
				for (int j = 0; j < arrSize; j++)
				{
					if (string[sizeNum][i] == firstPart[j])
					{
						anslen++;
						i++;
					}
					else
						break;
					if (anslen == arrSize)
					{
						count++;
					}
				}
			}
		}
	}
	return count;
}