#include <stdio.h>

void calculate(int N1, int N2, int* re1, int* re2, int* re3, int* re4);

void main()
{
	int N1 = 2, N2 = 8;
	int re1;
	int re2;
	int re3;
	int re4;
	if ((N1 > 0 && N2 <= 0) || (N1 < 0 && N2 >= 0))
	{
		printf("Both numbers must be non-zero or have the same sign.\n\n");
	}
	else
	{
		calculate(N1, N2, &re1, &re2, &re3, &re4);
		printf("N1 : %d N2: %d\n", N1, N2);
		printf("N1 *  N2 = %d\n", re1);
		printf("N1 /  N2 = %d\n", re2);
		printf("N1 %% N2 = %d\n", re3);
		printf("N1 +  N2 = %d\n\n", re4);
	}
	N1 = 100, N2 = -1;
	if ((N1 > 0 && N2 <= 0) || (N1 < 0 && N2 >= 0))
	{
		printf("Both numbers must be non-zero or have the same sign.\n\n");
	}
	else
	{
		calculate(N1, N2, &re1, &re2, &re3, &re4);
		printf("N1 : %d N2: %d\n", N1, N2);
		printf("N1 *  N2 = %d\n", re1);
		printf("N1 /  N2 = %d\n", re2);
		printf("N1 %% N2 = %d\n", re3);
		printf("N1 +  N2 = %d\n\n", re4);
	}
	N1 = 0, N2 = -1;
	if ((N1 > 0 && N2 <= 0) || (N1 < 0 && N2 >= 0))
	{
		printf("Both numbers must be non-zero or have the same sign.\n\n");
	}
	else
	{
		calculate(N1, N2, &re1, &re2, &re3, &re4);
		printf("N1 : %d N2: %d\n", N1, N2);
		printf("N1 *  N2 = %d\n", re1);
		printf("N1 /  N2 = %d\n", re2);
		printf("N1 %% N2 = %d\n", re3);
		printf("N1 +  N2 = %d\n\n", re4);
	}

}

void calculate(int N1, int N2, int* re1, int* re2, int* re3, int* re4)
{
	*re1 = N1 * N2;
	*re2 = N1 / N2;
	*re3 = N1 % N2;
	*re4 = N1 + N2;
}