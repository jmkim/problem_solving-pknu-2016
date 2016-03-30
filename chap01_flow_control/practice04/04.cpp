#include <stdio.h>
#include <stdlib.h> /* rand(), srand() */
#include <time.h> /* time() */
#include <math.h> /* abs() */

int main(void)
{
    srand(time(NULL));

    int N, T;
    printf("Enter N= "); scanf("%d", &N);
    printf("Enter T= "); scanf("%d", &T);

    int step = 0;
    for(int count = 0; count < T; ++count)
    {
        int s, x = 0, y = 0;
        for(s = 0; abs(x) < N || abs(y) < N; ++s)
        {
            switch(rand() % 4)
            {
            case 0: ++x; break;
            case 1: ++y; break;
            case 2: --x; break;
            case 3: --y; break;
            }
        }
        step += s;
    }
    step /= T;

    printf("Result: %d\n", step);

    return 0;
}
