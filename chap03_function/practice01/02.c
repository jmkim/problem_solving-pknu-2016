#include <stdio.h>


/** Function prototypes */
void
colour_distance(int *x, int *y, const int dir, const int dist);


/** Function definitions */
int
main(void)
{
    while(1)
    {
        int x = 0, y = 0, dir = 0, dist = 0;

        printf("Enter values (\"x y dir dist\")= ");
        scanf("%d %d %d %d", &x, &y, &dir, &dist);

        colour_distance(&x, &y, dir, dist);

        printf("Result: %d %d\n", x, y);
    }

    return 0;
}

/**
 *  \brief  Get location as far as distance
 *
 *  \param  x       pointer of location x
 *  \param  y       pointer of location y
 *  \param  dir     direction
 *  \param  dist    distance
 */
void
colour_distance(int *x, int *y, const int dir, const int dist)
{
    /**
        Coordination of board
                         x  y
        +---- y     a -> 0, 0
        | a b       b -> 0, 1
        | c d       c -> 1, 0
        x           d -> 1, 1

        Direction of board
        0:n, 1:ne, 2:e, 3:se, 4:s, 5:sw, 6:w, 7:nw
    */

    switch(dir)
    {
    case 0: *x -= dist;             break;
    case 1: *x -= dist; *y += dist; break;
    case 2:             *y += dist; break;
    case 3: *x += dist; *y += dist; break;
    case 4: *x += dist;             break;
    case 5: *x += dist; *y -= dist; break;
    case 6:             *y -= dist; break;
    case 7: *x -= dist; *y -= dist; break;
    }
}
