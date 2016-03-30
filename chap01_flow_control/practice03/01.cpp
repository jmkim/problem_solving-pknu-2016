#include <stdio.h>

int main(void)
{
    int sum = 0, count = 0;

    do
    {
        int num;

        printf("Enter the num= ");
        scanf("%d", &num);

        sum += (++count % 2 == 1) ? num : -num;
    }
    while(sum != 0);

    printf("Result: %d\n", count);

    return 0;
}
