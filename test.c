#include <stdio.h>

int main (void)
{
    int num = 254;

    int i = 0;
    while (i < 8)
    {
        if ((num & 1) == 1)
            printf("1 {%d}\n", num);
        if ((num & 1) == 0)
            printf("0 {%d}\n", num);
        num = num >> 1;
        i++;
    }
}