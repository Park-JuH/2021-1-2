#include <stdio.h>

int main()
{
	int N1 = 1, N2 = 2;
	int* re1, re2, re3, re4;

	calculate(N1, N2, &re1, &re2, &re3, &re4);

	printf("N1 * N2 = %d\n", re1);
	printf("N1 / N2 = %d\n", re2);
	printf("N1 %% N2 = %d\n", re3);
	printf("N1 + N2 = %d\n", re4);
}

calculate(int N1, int N2, int* re1, int* re2, int* re3, int* re4)
{
	*re1 = N1 * N2;
	*re2 = N1 / N2;
	*re3 = N1 % N2;
	*re4 = N1 + N2;
}