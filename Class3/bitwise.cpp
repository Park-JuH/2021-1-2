#include <stdio.h>
int main()
{
	int a = 100; // 100 represented by base 10
	int b = 0b01100100; // 100 represented by base 2
	int c = 0144; // 100 represented by base 8
	int d = 0x64; // 100 represented by base 16
	printf("100 base 2 to base 10: %d\n", a);
	printf("0b01100100 base 2 to base 10: %d\n", b);
	printf("0144 base 8 to base 10: %d\n", c);
	printf("0x64 base 16 to base 10: %d\n", d);
	printf("\n");
	int e = 1000;
	printf("1000 by base 10 : %d\n", e);
	printf("1000 by base 8 : %o\n", e);
	printf("1000 by base 16 : %X\n", e);
	return 0;
}