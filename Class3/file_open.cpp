#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i;
	FILE *myFile;
	double price[2] = { 139.25, 19.03 };
	char description[2][20] = { "glove", "CD" };

	myFile = fopen("C:\\Users\\atef9\\class3\\price.txt", "w");
	if (myFile == NULL)
		printf("\nFile Could Not Be Opened");
	else
	{
		for (i = 0; i < 2; i++)
			fprintf(myFile, "%-9s %6.2f\n", description[i], price[i]);
	}
	fclose(myFile);
	myFile = NULL;
}