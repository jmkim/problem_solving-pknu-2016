#include <stdio.h>

int main(void)
{
    int i;
    int input[10];
    int small[2]; /* small[0] is the smallest, small[1] is the smallest but large than small[0] */

    for(i = 0; i < 10; ++i)
    {
        printf("Enter input[%d]=", i);
        scanf("%d", &input[i]);
    }

    /* Calculate the smallest and its second */
    {
        small[0] = input[0];
        small[1] = input[1];
        for(i = 1; i < 10; ++i)
        {
            if(input[i] < small[1] && input[i] > small[0]) /* Check if input[i] is small[1] */
                small[1] = input[i];
            else if(input[i] < small[0])
            {
                small[1] = small[0];
                small[0] = input[i];
            }
        }
    }

    printf("Result is: small[0]=%d small[1]=%d\n", small[0], small[1]);

    return 0;
}
