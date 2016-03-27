#include <stdio.h>
#include <stdlib.h> /* rand(), srand() */
#include <time.h> /* time() */

int count_one_came_out_when_throwing_dice(const int count)
{
    int rc = 0;

    for(int i = 0; i < count; ++i)
        if(rand() % 6 + 1 == 1) ++rc;

    return rc;
}

int main(void)
{
    srand(time(NULL));

    const int max = 10000;

    int six = 0, twelve = 0;
    for(int i = 0; i < max; ++i)
    {
        six += (count_one_came_out_when_throwing_dice(6) >= 1);
        twelve += (count_one_came_out_when_throwing_dice(12) >= 2);
    }

    printf("Result: %s\n", (six == twelve) ? "SAME" : (six < twelve) ? "SIX" : "TWELVE");

    return 0;
}
