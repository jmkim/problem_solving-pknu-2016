/**
    Othello
*/

#include <stdio.h> /** printf, scanf, fscanf */


/** Macros */
#define O_SIZE_MAX  100
#define O_PNONE     0
#define O_PBLACK    1
#define O_PWHITE    2
//#define O_PRINT_BOARD_AFTER_LOAD


/** Global variables */
int bsize; /**< size of the board */
int bgame[O_SIZE_MAX][O_SIZE_MAX]; /**< game board */


/** Function prototypes */
void
read_file(const char path[]);

int
best_position(int *out_x, int *out_y);

int
count_of_captured_stone(const int x, const int y, const int my_colour);

int
count(const int x, const int y, const int dir);

int
colour_distance(const int x, const int y, const int dir, const int dist);


/** Function definitions */
int
main(void)
{
    read_file("input.txt");
    
    int x, y;
    int bestcount = best_position(&x, &y);
    
    printf("x: %d\n"
           "y: %d\n"
           "count:%d\n", x, y, bestcount);
    
    return 0;
}

/**
 *  \brief  Read a file and make a board
 *
 *  \param  path    Path to file
 */
void
read_file(const char path[])
{
    FILE *fp = fopen(path, "r");
    int i, j;
    
    fscanf(fp, "%d", &bsize);
    for(i = 0; i < bsize; ++i)
    {
        for(j = 0; j < bsize; ++j)
        {
            fscanf(fp, "%d", &bgame[i][j]);
#ifdef O_PRINT_BOARD_AFTER_LOAD
            printf("%d ", bgame[i][j]);
#endif
        }
#ifdef O_PRINT_BOARD_AFTER_LOAD
        printf("\n");
#endif
    }
}

/**
 *  \brief  Search the best position in the board
 *
 *  \return count of the captured stones
 *  \param  out_x   pointer to store the location x
 *  \param  out_y   pointer to store the location y
 */
int
best_position(int *out_x, int *out_y)
{
    int bestcount = 0;
    int i, j;
    
    for(i = 0; i < bsize; ++i)
    {
        for(j = 0; j < bsize; ++j)
        {
            int bc = count_of_captured_stone(i, j, O_PWHITE);
            if(bc > bestcount)
            {
                bestcount = bc;
                *out_x = i;
                *out_y = j;
            }
        }
    }
    
    return bestcount;
}

/**
 *  \brief  Get a count of the enemy stone than can be conquered
 *
 *  \return count of the enemy stone
 *  \param  x   location x
 *  \param  y   location y
 *  \param  my_colour   my colour
 */
int
count_of_captured_stone(const int x, const int y, const int my_colour)
{
    if(bgame[x][y] != O_PNONE) return 0; /** Cannot place stone here */
    
    int captured_stone = 0; /**< count of captured stone */
    int dir;
    
    bgame[x][y] = my_colour; /** Set colour temporarily */
    for(dir = 0; dir < 7; ++dir)
        captured_stone += count(x, y, dir);
    bgame[x][y] = O_PNONE; /** Reset colour */

    return captured_stone;
}

/**
 *  \brief  Get a count of the enemy stone that can be conquered, with specific direction
 *
 *  Put my stone to location beforehand.
 *  \return count of the enemy stone
 *  \param  x       location x
 *  \param  y       location y
 *  \param  dir     direction
 */
int
count(const int x, const int y, const int dir)
{
    int dist = 0; /**< distance */
    int my_colour = colour_distance(x, y, dir, 0);
    int last_colour; /**< colour that is the first change of specific direction */

    do { ++dist; } while((last_colour = colour_distance(x, y, dir, dist)) != 0 && last_colour != my_colour);

    if(last_colour == my_colour)
        return dist - 1;
    else
        return 0;
}

/**
 *  \brief  Get colour as far as distance from the location
 *
 *  Return zero(O_PNONE) when the passed location is invalid.
 *  \return colour
 *  \param  x       location x
 *  \param  y       location y
 *  \param  dir     direction
 *  \param  dist    distance
 */
int
colour_distance(const int x, const int y, const int dir, const int dist)
{
    /**
        Coordination of board
                         x  y   bgame[x][y]
        +---- y     a -> 0, 0   bgame[0][0]
        | a b       b -> 0, 1   bgame[0][1]
        | c d       c -> 1, 0   bgame[1][0]
        x           d -> 1, 1   bgame[1][1]

        Direction of board
        0:n, 1:ne, 2:e, 3:se, 4:s, 5:sw, 6:w, 7:nw
    */

    switch(dir)
    {
    case 0: return ( x - dist >= 0                        ) ? bgame[x - dist][y       ] : 0;
    case 1: return ( x - dist >= 0    && y + dist < bsize ) ? bgame[x - dist][y + dist] : 0;
    case 2: return (                     y + dist < bsize ) ? bgame[x       ][y + dist] : 0;
    case 3: return ( x + dist < bsize && y + dist < bsize ) ? bgame[x + dist][y + dist] : 0;
    case 4: return ( x + dist < bsize                     ) ? bgame[x + dist][y       ] : 0;
    case 5: return ( x + dist < bsize && y - dist >= 0    ) ? bgame[x + dist][y - dist] : 0;
    case 6: return (                     y - dist >= 0    ) ? bgame[x       ][y - dist] : 0;
    case 7: return ( x - dist >= 0    && y - dist >= 0    ) ? bgame[x - dist][y - dist] : 0;
    }
}
