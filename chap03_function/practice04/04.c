#include <stdio.h>
#include <string.h>
#include "include/refine.h"

#define MAX_WORD_INPUT 81

int
main(void)
{
    const   int     limit  = 80;
            FILE *  fp      = fopen("res/input04.txt", "r");
            int     i;

    for(i = 0; i < limit; ++i)
        printf(" ");
    printf("| %d\n", limit);

    refine(stdout, fp, limit);
}
