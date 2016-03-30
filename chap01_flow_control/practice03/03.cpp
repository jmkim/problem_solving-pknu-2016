#include <stdio.h>

int main(void)
{
    int N;

    printf("Enter N= ");
    scanf("%d", &N);

    /* Get the largest number in the power of two, which satisfies less than or equal to N */
    int v = 1;

    while(v <= N) v = v << 1;
    v = v >> 1;

    /* Calculate and print to screen */
    while(v > 0)
    {
        if(N >= v)
        {
            N -= v;
            putchar('1');
        }
        else
            putchar('0');

        v /= 2;
    }
    putchar('\n');

    return 0;
}
