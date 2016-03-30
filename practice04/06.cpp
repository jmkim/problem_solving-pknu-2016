#include <stdio.h>

#define MAX_LOOP    10000

double formula(const double x, const double k)
{
    return (x * x) / ((2 * k - 1) * (2 * k));
}

int main(void)
{
    double x;
    printf("Enter x= ");
    scanf("%lf", &x);

    double cosx = 1,
           sinx = x;

    int k = 2;
    while(k < MAX_LOOP)
    {
        cosx = cosx - cosx * formula(x, k++);
        sinx = sinx - sinx * formula(x, k++);
        cosx = cosx + cosx * formula(x, k++);
        sinx = sinx + sinx * formula(x, k++);
    }

    printf("Result is: cosx=%f sinx=%f\n", cosx, sinx);

    return 0;
}
