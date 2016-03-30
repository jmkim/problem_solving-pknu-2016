#include <stdio.h>

int calc(const int base, const int exponent, const int value = 1, const int count = 0)
{
    if(count == exponent) return value;
    return calc(base, exponent, value * base, count + 1);
}

double sum(const int n) { return (double)(calc(2, n) * 2 - 1) / calc(2, n); }

int main(void)
{
    printf("sum calulator\n");
    printf("1 + 1/2 + 1/(2^2) + 1/(2^3) + ... + 1/(2^n)\n");

    int n;
    printf("Enter n= "); scanf("%d", &n);

    printf("Result is %lf\n", sum(n));
    return 0;
}
