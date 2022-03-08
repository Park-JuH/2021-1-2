#include <stdio.h>

int main()
{
    int mask = 1024;
    int count = 0;
    for (int num = 1; num <= 1000; num++)
    {
        printf("DEC %-4d:  BIN ", num);
        for (int i = 0; i <= 10; i++)
        {
            int bn = num & mask >> i;
            if (bn != 0)
            {
                printf("1");
                for ( i = i + 1; i <= 10; i++)
                {
                    int bn = num & mask >> i;
                    if (bn == 0)
                        printf("0");
                    else
                        printf("1");
                }
            }
        }
        printf("%10s %-4X\n", "HEX", num);
    }
    return 0;
}