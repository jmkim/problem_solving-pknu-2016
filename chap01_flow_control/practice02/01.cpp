#include <stdbool.h>
#include <stdio.h>

bool is_triangle(const int side_a, const int side_b, const int side_c)
{
    /* Get the triangular inequality state from length of the sides */
    if(side_a + side_b > side_c && side_b + side_c > side_a && side_c + side_a > side_b) return true; /* This is a triangle */
    return false; /* Not a triangle */
}

int main(void)
{
    int side_a, side_b, side_c;
    printf("Enter side_a= "); scanf("%d", &side_a);
    printf("Enter side_b= "); scanf("%d", &side_b);
    printf("Enter side_c= "); scanf("%d", &side_c);

    printf("Result is %d\n", is_triangle(side_a, side_b, side_c) ? "yes" : "no");
    return 0;
}
