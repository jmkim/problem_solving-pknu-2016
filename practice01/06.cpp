#include <stdio.h>

int fibonacci(const int n, const int value = 1, const int value_prev = 0, const int count = 0)
{
    if(count == n) return value;
    return fibonacci(n, value + value_prev, value, count + 1);
}

int main(void)
{
    printf("Fibonacci calulator\n");

    int n;
    printf("Enter n= "); scanf("%d", &n);

    printf("Result is %d\n", fibonacci(n));
    return 0;
}
