#include <stdbool.h>

bool is_triangle(const int side_a, const int side_b, const int side_c)
{
    /* Get the triangular inequality state from length of the sides */
    if(side_a + side_b > side_c && side_b + side_c > side_a && side_c + side_a > side_b) return true; /* This is a triangle */
    return false; /* Not a triangle */
}
