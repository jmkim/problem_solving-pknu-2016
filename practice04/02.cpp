#include <stdio.h>

int main(void)
{
    int N;
    printf("Enter N= ");
    scanf("%d", &N);

    int count = 0;
    for(int num = 1; num <= N; ++num)
    {
        int sum = 0;
        int base = 1000000000; /* maximum place in range of 4 byte int */
        for(int i = num; i > 0; i %= base, base /= 10)
            sum += i / base;
        if(sum % 7 == 0) ++count;
    }

    printf("Result: %d\n", count);

    return 0;
}
