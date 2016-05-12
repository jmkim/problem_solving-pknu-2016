#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(const int num)
{
    int i;
    for(i = 2; i < num; ++i)
    {
        if(num % i == 0) return false;
    }
    return true;
}

int prac3(const int n, const int arr[])
{
    int num = 0;
    int i, j;

    for(i = 0; i < n; ++i)
    {
        int t = 0;
        for(j = i; j < n; ++j)
        {
            t *= 10;
            t += arr[j];
            if(t > num && is_prime(t)) num = t;
        }
    }

    return num;
}

int main(void)
{
    int a[] = {4, 1, 0, 1, 1, 3};
    printf("%d\n", prac3(6, a));

    return 0;
}
