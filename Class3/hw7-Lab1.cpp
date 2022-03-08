/********************************************************************************
*
*	Problem Solving Methods, Fall, 2021
*	Bitwise Lab-1
*
*	Written by YoungWoon Cha (youngcha@gachon.ac.kr)
*	November, 2021
*********************************************************************************/

// Add "_CRT_SECURE_NO_WARNINGS" to Preprocessor Definitions

#include <stdio.h>

void print_ch2bin(const char ch)
{
	int mask = 0x80;
	for (int i = 0; i < 8; i++)
	{
		if (ch & mask)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		mask = mask >> 1;
	}	
}


int main() 
{
	char test_inputs[] = {"chaCHA"};
	for (int i = 0; i < 6; i++)
	{
		printf("[%d test] : %c --> ", i+1, test_inputs[i]);
		print_ch2bin(test_inputs[i]);
		printf("\n");
	}

	return 0;
}