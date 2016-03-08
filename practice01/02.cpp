#include <stdio.h>
#include <math.h>

int cube(const int base) { return base * base; }

int main(void)
{
    printf("distance between two points\n");
    printf("(a, b) and (c, d)\n");

    int a, b, c, d;
    printf("Enter a= "); scanf("%d", &a);
    printf("Enter b= "); scanf("%d", &b);
    printf("Enter c= "); scanf("%d", &c);
    printf("Enter d= "); scanf("%d", &d);

    printf("Result is %lf\n", sqrt(cube(c - a) + cube(d - b)));
    return 0;
}
