#include <stdio.h>
#include <string.h>

#define SIZE 5

int searchString(char string[], char search[], int sizeNum);

void main()
{
	char testStr[SIZE][256] = { "Is your name Bob?", "No, my name is Rob.", "Hello, Rob.", "A thief named hong hong gil dong lived with friends named hong gil dong and hong gil ja in a village named hong gil dong village.", "A thief named hong gil dong lived with friends named hong gil don and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village." };
	char testSearchStr[SIZE][256] = { "name", "name", "name", "hong gil dong", "hong gil dong" };

	for (int i = 0; i < SIZE; i++)
	{
		int numMatches = searchString(testStr, testSearchStr, i);
		printf("\n--- Experiment (%d) ---\n", i + 1);
		printf("[String:] %s\n", testStr[i]);
		printf("[Search:] %s\n", testSearchStr[i]);
		printf("[Num Matches:] %d\n", numMatches);
	}
}

int searchString(char string[SIZE][256], char search[SIZE][256], int sizeNum)
{
	int count = 0;
	int arrSize = strlen(search[sizeNum]);
	for (int i = 0; i < 256; i++)
	{
		if (string[sizeNum][i] == search[sizeNum][0])
		{
			int anslen = 0;
			for (int j = 0; j < arrSize; j++)
			{
				if (string[sizeNum][i] == search[sizeNum][j])
				{
					anslen++;
					i++;
				}
				else if(string[sizeNum][i] == search[sizeNum][0])
				{
					anslen = 0;
					for (int k = 0; k < strlen(search[sizeNum]); k++)
					{
						if (string[sizeNum][i] == search[sizeNum][k])
						{
							anslen++;
							i++;
						}
					}
					if (anslen == arrSize)
					{
						count++;
						break;
					}
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
	return count;
}