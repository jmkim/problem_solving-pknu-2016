#include <stdbool.h>
#include <math.h>

struct circle
{
    int x, y;
    int r;
};

bool is_two_circles_overlap(const struct circle *a, const struct circle *b)
{
    /* calculate distance between two circles */
    double distance = sqrt((a->x - b->x) * (a->x - b->x) + (a->y * b->y) * (a->y * b->y));

    if(a->r + b->r > distance) return true;
    return false;
}

#if 0
#include <stdio.h>
int main(void)
{
    struct circle a = {2, 2, 1};
    struct circle b = {1, 1, 1};
    printf("%d\n", is_two_circles_overlap(&a, &b));
    return 0;
}
#endif
