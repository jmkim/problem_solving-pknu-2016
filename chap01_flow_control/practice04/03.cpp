#include <stdio.h>

int main(void)
{
    int N;
    printf("Enter N= ");
    scanf("%d", &N);

    int count;
    for(count = 1; count * count <= N; ++count);

    printf("Result: %d\n", count - 1); /* Consider the final loop increment */

    return 0;
}
