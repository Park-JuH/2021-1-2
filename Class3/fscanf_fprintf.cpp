#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, sum = 0;
	FILE* inFile, * outFile;
	inFile = fopen("C:\\Users\\atef9\\class3\\myinFile.txt", "w");
	fprintf(inFile, "1\n2\n3\n4\n5\n6");
	fclose(inFile);
	inFile = fopen("C:\\Users\\atef9\\class3\\myinFile.txt", "r");
	if (inFile == NULL) {
		printf("Input File Could Not Be Opened.");
		exit(1);
	};
	outFile = fopen("C:\\Users\\atef9\\class3\\myoutFile.txt", "w");
	if (outFile == NULL) {
		printf("Output File Could Not Be Opened.");
		exit(1);
	};
	/* Read and sum the integers from the input file and
	write the sum to the output file */
	while (fscanf(inFile, "%d", &a) == 1) /* loops until EOF */
		sum = sum + a;
	fprintf(outFile, "The sum is %d\n", sum);
	
	fclose(inFile);
	fclose(outFile);

	return 0;
}