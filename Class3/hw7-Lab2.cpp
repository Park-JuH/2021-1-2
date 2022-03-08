/********************************************************************************
*
*	Problem Solving Methods, Fall, 2021
*	Bitwise Lab-2
*
*	Written by YoungWoon Cha (youngcha@gachon.ac.kr)
*	November, 2021
*********************************************************************************/

// Add "_CRT_SECURE_NO_WARNINGS" to Preprocessor Definitions

#include <stdio.h>
#include <string.h>

void remove_leading_zeros(
	const char * str,
	char * dest_wo_leading_zeros)
{
	int len = strlen(str);
	
	int leading_zero_len = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != '0')
		{
			leading_zero_len = i;
			break;
		}
	}

	strcpy(dest_wo_leading_zeros, str + leading_zero_len);
}

void bin_to_binstr(const int binary, char * bin_str_wo_leading_zeros)
{	
	static const char digits[] = "01";
	char bin_str[33]; // 32 bits integer
	bin_str[32] = '\0';
	for (int i = 0; i < 32; i++)
	{
		bin_str[31 - i] = digits[(binary >> i) & 0b1];
	}

	remove_leading_zeros(bin_str, bin_str_wo_leading_zeros);
}

void bin_to_hexstr(int binary, char * hex_str_wo_leading_zeros)
{	
	static const char digits[] = "0123456789ABCDEF";
	char hex_str[9]; // 32 digits to 8 digits. e.g. 0000000F
	hex_str[8] = '\0';
	for(int i=0; i < 8; i++) // 4 bits * 8 times = 32 bits integer
	{ 
		int four_bits = (binary >> (i*4));		
		hex_str[7-i] = digits[four_bits & 0x0F];
	}

	remove_leading_zeros(hex_str, hex_str_wo_leading_zeros);
}


int main() 
{	
	char bin_str[32];
	char hex_str[32];
	for (int i = 1; i <= 1000; i++)
	{
		bin_to_binstr(i, bin_str);
		bin_to_hexstr(i, hex_str);

		printf("DEC %-4d: \t", i);
		printf(" BIN %-12s \t", bin_str);
		printf(" HEX %s \n", hex_str);
	}

	return 0;
}