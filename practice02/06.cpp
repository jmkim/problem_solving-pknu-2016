#include <stdbool.h>
#include <stdio.h>
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

int main(void)
{
    struct circle a, b;
    printf("Enter a.r= "); scanf("%d", &a.r);
    printf("Enter a.x= "); scanf("%d", &a.x);
    printf("Enter a.y= "); scanf("%d", &a.y);
    printf("Enter b.r= "); scanf("%d", &b.r);
    printf("Enter b.x= "); scanf("%d", &b.x);
    printf("Enter b.y= "); scanf("%d", &b.y);

    printf("Result is %s\n", is_two_circles_overlap(&a, &b) ? "yes" : "no");
    return 0;
}
