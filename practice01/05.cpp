#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("solution finder\n");
    printf("f(x) = a(x^2) + b(x) + c\n");

    double coef[3];
    printf("Enter a= "); scanf("%lf", &coef[2]);
    printf("Enter b= "); scanf("%lf", &coef[1]);
    printf("Enter c= "); scanf("%lf", &coef[0]);

    double solution[2] =
    {
        (-coef[1] - sqrt(coef[1] * coef[1] - 4 * coef[2] * coef[0])) / (2 * coef[2]),
        (-coef[1] + sqrt(coef[1] * coef[1] - 4 * coef[2] * coef[0])) / (2 * coef[2])
    };

    printf("Result is %lf", solution[0]);
    if(solution[0] != solution[1]) printf(", %lf", solution[1]);
    printf("\n");
    return 0;
}
