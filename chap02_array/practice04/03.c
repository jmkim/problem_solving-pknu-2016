#include <stdio.h>
#include <stdbool.h>
#include <time.h>


#define N_MAX   200
#define NONE    0
#define MINE    -1

int n;
int count;
bool lose;
int mine_board[N_MAX][N_MAX];
int mine_print[N_MAX][N_MAX];

void step_in(const int x, const int y);
void step(const int x, const int y);
bool is_mine(const int x, const int y);
int search(const int x, const int y);
void make_board(const int mine_count);
void print_board(void);
void debug_board(void);

int main(void)
{
    int k;

    printf("Enter N and K: ");
    scanf("%d%d", &n, &k);

    make_board(k);
    printf("Game started!\n");

    while(lose == false && count < n)
    {
        int x, y, i, j;
        char c;

        printf("Please enter a position: ");
        scanf("%d%d %c", &x, &y, &c);

        if(c == 'B')
        {
            if(mine_print[x][y] > NONE)
            {
                printf("Error: Position error.\n");
                continue;
            }
            mine_print[x][y] = MINE;
        }
        else if(c == 'N')
        {
            if(mine_print[x][y] > NONE)
            {
                printf("Error: Position error.\n");
                continue;
            }
            else if(mine_print[x][y] == MINE) --count;
            step_in(x, y);
        }
        else
            continue;

        print_board();
        if(lose)
        {
            printf("Result: You lose.\n");
            for(i = 0; i < n; ++i)
            {
                for(j = 0; j < n; ++j)
                {
                    if(mine_board[i][j] == -1)
                    {
                        mine_print[i][j] = 9;
                    }
                }
            }
            print_board();
        }
    }

    return 0;
}

void step_in(const int x, const int y)
{
    if(mine_board[x][y] == MINE)
        mine_print[x][y] = 9;
    else
    {
        mine_print[x][y] = search(x, y);
        if(mine_print[x][y] == 0)
        {
            mine_print[x][y] = 10;
#if 0
            step(x+1, y  );
            step(x+1, y-1);
            step(x  , y-1);
            step(x-1, y-1);
            step(x-1, y  );
            step(x-1, y+1);
            step(x  , y+1);
            step(x+1, y+1);
#endif
        }
    }
}

void step(const int x, const int y)
{
    if(mine_board[x][y] <= MINE)
        return;
    else
    {
        mine_print[x][y] = search(x, y);
#if 0
        if(mine_print[x][y] == 0)
        {
            step(x+1, y  );
            step(x+1, y-1);
            step(x  , y-1);
            step(x-1, y-1);
            step(x-1, y  );
            step(x-1, y+1);
            step(x  , y+1);
            step(x+1, y+1);
        }
#endif
    }
}

bool is_mine(const int x, const int y)
{
    return mine_board[x][y] == MINE;
}

int search(const int x, const int y)
{
    return is_mine(x+1, y  )
         + is_mine(x+1, y-1)
         + is_mine(x  , y-1)
         + is_mine(x-1, y-1)
         + is_mine(x-1, y  )
         + is_mine(x-1, y+1)
         + is_mine(x  , y+1)
         + is_mine(x+1, y+1);
}


void make_board(const int mine_count)
{
    int i, x, y;

    srand(time(NULL));
    for(i = 0; i < mine_count; ++i)
    {
        x = rand() % n;
        y = rand() % n;

        if(mine_board[x][y] == MINE)
        {
            --i;
            continue;
        }

        mine_board[x][y] = MINE;
    }
}

void print_board(void)
{
    char c;
    int i, j;

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(mine_print[i][j] > NONE && mine_board[i][j] == MINE) lose = true;
            switch(mine_print[i][j])
            {
            case NONE: printf(" -"); break;
            case MINE: printf(" @"); break;
            case 9: printf(" B"); break;
            case 10: printf(" 0"); break;
            default: printf("%2d", mine_print[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

void debug_board(void)
{
    int i, j;

    printf("BOARD DATA\n");
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            printf("%2d ", mine_board[i][j]);
        }
        printf("\n");
    }
}
