#include <stdio.h>
#include <math.h>

int main(void)
{
    int num;

    printf("Enter num= ");
    scanf("%d", &num);

    printf("Result: %d\n", (int)sqrt(num) * (int)sqrt(num));

    return 0;
}
