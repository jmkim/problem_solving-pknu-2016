#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    int input[10];
    int sum = 0;
    double average = 0;
    double sd = 0; /* Population standard deviation */

    for(i = 0; i < 10; ++i)
    {
        printf("Enter input[%d]=", i);
        scanf("%d", &input[i]);
        sum += input[i];
    }

    /* Calculate the average */
    {
        average = (double)sum / 10;
    }

    /* Calculate the population standard deviation */
    {
        for(i = 0; i < 10; ++i)
            sd += ((double)input[i] - average) * ((double)input[i] - average);
        sd *= 0.1;
        sd = sqrt(sd);
    }

    printf("Result is: average=%lf sd=%lf\n", average, sd);

    return 0;
}
