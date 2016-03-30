#include <stdio.h>

int calc(const int n, const int value = 1, const int count = 1)
{
    if(count == n) return value;
    return calc(n, 2 * value + count - 1, count + 1);
}

int main(void)
{
    printf("sequence calculator\n");
    printf("a(0) = 1\n");
    printf("a(n) = 2 * a(n-1) + n - 1, n > 0\n");

    int n;
    printf("Enter n= "); scanf("%d", &n);

    printf("Result is %d\n", calc(n));
    return 0;
}
