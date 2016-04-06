#include <stdio.h>

int main(void)
{
    int size, temp, i;
    int input[100];
    FILE *fp = fopen("res/04_input.txt", "r");

    {
        for(size = 0; size < 100 && !feof(fp); ++size)
            fscanf(fp, "%d", &input[size]);
        --size;
    }

    {
        temp = input[size - 1];

        for(i = size - 1; i > 0; --i)
            input[i] = input[i - 1];

        input[0] = temp;
    }

    {
        printf("Result is: ");

        for(i = 0; i < size; ++i)
            printf("%d ", input[i]);

        printf("\n");
    }
}
