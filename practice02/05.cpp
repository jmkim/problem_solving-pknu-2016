#include <stdio.h>
#include <stdbool.h>

bool is_two_intervals_overlap(const int a, const int b, const int c, const int d)
{
    if(a < c && b < c || a > c && a > d) return false;
    return true;
}

int main(void)
{
    printf("%s\n", is_two_intervals_overlap(1, 3, 5, 6) ? "yes" : "no");
    printf("%s\n", is_two_intervals_overlap(5, 6, 1, 3) ? "yes" : "no");
    printf("%s\n", is_two_intervals_overlap(1, 3, 2, 4) ? "yes" : "no");
    printf("%s\n", is_two_intervals_overlap(2, 4, 1, 3) ? "yes" : "no");
    printf("%s\n", is_two_intervals_overlap(3, 4, 1, 5) ? "yes" : "no");
    printf("%s\n", is_two_intervals_overlap(1, 5, 3, 4) ? "yes" : "no");
    return 0;
}
