#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s [count] (max)\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    for(int i = 0; i < atoi(argv[1]); ++i)
        printf("%d\n", rand() % ((argc == 3) ? atoi(argv[2]) : RAND_MAX));

    return 0;
}
