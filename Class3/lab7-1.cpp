#include <stdio.h>

struct TEST
{
    char character;
}data[7] = { 'a', 'b', 'c', 'X', 'Y', 'Z' };

int main()
{
    int mask = 0x80;
    for (int size = 0; size < 6; size++)
    {
        printf("%c: ", data[size].character);
        for (int i = 0; i <= 7; i++)
        {
            int bn = data[size].character & mask >> i;
            if (bn == 0)
                printf("0");
            else
                printf("1");
        }
        printf("\n");
    }
    return 0;
}