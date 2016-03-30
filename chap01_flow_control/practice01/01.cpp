#include <stdio.h>

int calc(const int base, const int exponent, const int value = 1, const int count = 0)
{
    if(count == exponent) return value;
    return calc(base, exponent, value * base, count + 1);
}

int main(void)
{
    printf("a^b calulator\n");

    int a, b;
    printf("Enter a= "); scanf("%d", &a);
    printf("Enter b= "); scanf("%d", &b);

    printf("Result is %d\n", calc(a, b));
    return 0;
}
