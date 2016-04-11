#include <stdio.h>

#define MAX_ARRAY_SIZE  100

int main(void)
{
    int data[MAX_ARRAY_SIZE] = {0, };
    int size = 0;

    while(size < MAX_ARRAY_SIZE)
    {
        int input, i, j;

        {
            /* User input */
            scanf("%d", &input);
            if(input == -1) break;
        }

        {
            /* Search */
            for(i = 0; input > data[i] && i < size; ++i); /* Ascend */
            //for(i = 0; input < data[i] && i < size; ++i); /* Descend */

            if(input == data[i] && i < size)
            {
                printf("duplicate entry\n");
                continue;
            }
        }

        {
            /* Input data to data[] */
            for(j = size; j > i; --j) data[j] = data[j - 1]; /* Pull back */
            data[j] = input;
            ++size;
        }
        
        {
            /* Print all elements */
            for(j = 0; j < size; ++j) printf("%d ", data[j]);
            printf("\n");
        }
    }

    return 0;
}
