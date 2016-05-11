#include <stdio.h>

#define O_SIZE_MAX  100
#define O_PNONE     0
#define O_PBLACK    1
#define O_PWHITE    2

int bsize;
int bgame[O_SIZE_MAX][O_SIZE_MAX];

void
read_file(const char path[]);

int
best_position(int *out_x, int *out_y);

int
count_of_captured_stone(const int x, const int y, const int enemy_colour);

int
count(const int x, const int y, const int dir);

int
main(void)
{
    read_file("input.txt");
    
    int x, y;
    int bestcount = best_position(&x, &y);
    
    printf("size: %d\nx: %d\ny: %d\ncount:%d\n", bsize, x, y, bestcount);
    
    return 0;
}

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
            printf("%d ", bgame[i][j]);
        }
        printf("\n");
    }
}

int
best_position(int *out_x, int *out_y)
{
    int bestcount = 0;
    int i, j;
    
    for(i = 0; i < bsize; ++i)
    {
        for(j = 0; j < bsize; ++j)
        {
            int bc = count_of_captured_stone(i, j, O_PBLACK);
            if(bc > bestcount)
            {
                printf("%d %d %d\n", bc, i, j);
                bestcount = bc;
                *out_x = i;
                *out_y = j;
            }
        }
    }
    
    return bestcount;
}

int
count_of_captured_stone(const int x, const int y, const int enemy_colour)
{
    if(bgame[x][y] != O_PNONE) return 0;
    
    int captured_stone = 0;
    int dir;
    
    bgame[x][y] = enemy_colour; /* temporarily set the colour */
    for(dir = 0; dir < 7; ++dir)
        captured_stone += count(x, y, dir);
    bgame[x][y] = O_PNONE; /* return colour */

    return captured_stone;
}

int
can_place_stone(const int x, const int y, const int my_colour)
{

}

int
colour_distance(const int x, const int y, const int dir, const int distance)
{
    switch(dir)
    {
    case 0: return bgame[x           ][y + distance];
    case 1: return bgame[x - distance][y + distance];
    case 2: return bgame[x - distance][y           ];
    case 3: return bgame[x - distance][y - distance];
    case 4: return bgame[x           ][y - distance];
    case 5: return bgame[x + distance][y - distance];
    case 6: return bgame[x + distance][y           ];
    case 7: return bgame[x + distance][y + distance];
    }
}

int
count(const int x, const int y, const int dir)
{
    if(x < 0 || y < 0 || x > bsize || y > bsize) return 0;

    int x_t = 0,
        y_t = 0;

    int enemy_colour;

    switch(colour_distance(x, y, dir, 0))
    {
    case O_PBLACK:  enemy_colour = O_PWHITE; break;
    case O_PWHITE:  enemy_colour = O_PBLACK; break;
    default:        enemy_colour = O_PNONE;
    }

    switch(dir)
    {
    case 0:
        do { ++y_t; } while(colour_distance(x, y, dir, 0) != colour_distance(x, y_t, dir, i));
        return y_t - y;
        
    case 1:
        if(x-1 > bsize || y+1 > bsize || bgame[x][y] != bgame[x-1][y+1]) return 0;
        return 1 + count(x-1, y+1, dir);
    
    case 2:
        if(x-1 > bsize || bgame[x][y] != bgame[x-1][y]) return 0;
        return 1 + count(x-1, y, dir);
        
    case 3:
        if(x-1 > bsize || y-1 > bsize || bgame[x][y] != bgame[x-1][y-1]) return 0;
        return 1 + count(x-1, y-1, dir);
        
    case 4:
        if(y-1 > bsize || bgame[x][y] != bgame[x][y-1]) return 0;
        return 1 + count(x, y-1, dir);
        
    case 5:
        if(x+1 > bsize || y-1 > bsize || bgame[x][y] != bgame[x+1][y-1]) return 0;
        return 1 + count(x+1, y-1, dir);
        
    case 6:
        if(x+1 > bsize || bgame[x][y] != bgame[x+1][y]) return 0;
        return 1 + count(x+1, y, dir);
        
    case 7:
        if(x+1 > bsize || y+1 > bsize || bgame[x][y] != bgame[x+1][y+1]) return 0;
        return 1 + count(x+1, y+1, dir);
    }
}
