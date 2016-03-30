#include <stdio.h>

#define MAX_LOOP    100

double cosine_formula(const double x, const double k)
{
    if(k == 0) return 1;
    return (x * x) / ((2 * k - 1) * (2 * k));
}

double sine_formula(const double x, const double k)
{
    if(k == 0) return x;
    return (x * x) / ((2 * k) * (2 * k + 1));
}

int main(void)
{
    double x;
    printf("Enter x= ");
    scanf("%lf", &x);

    double cosx = 0, sinx = 0;

    {
        double cosx_cache = 1, sinx_cache = 1;
        for(int k = 0; k < MAX_LOOP; ++k)
        {
            cosx_cache *= cosine_formula(x, k);
            (k % 2 == 0) ? cosx += cosx_cache : cosx -= cosx_cache;

            sinx_cache *= sine_formula(x, k);
            (k % 2 == 0) ? sinx += sinx_cache : sinx -= sinx_cache;
        }
    }

    printf("Result is: cosx=%f sinx=%f\n", cosx, sinx);

    return 0;
}
