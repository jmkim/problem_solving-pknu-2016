#include <stdio.h>
#include <stdbool.h>

bool is_two_intervals_overlap(const int a, const int b, const int c, const int d)
{
    if(a < c && b < c || a > c && a > d) return false;
    return true;
}

int main(void)
{
    int a, b, c, d;
    printf("Enter a= "); scanf("%d", &a);
    printf("Enter b= "); scanf("%d", &b);
    printf("Enter c= "); scanf("%d", &c);
    printf("Enter d= "); scanf("%d", &d);

    printf("Result is %s\n", is_two_intervals_overlap(a, b, c, d) ? "yes" : "no");
    return 0;
}
