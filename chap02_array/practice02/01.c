#include <stdio.h>

int main(void)
{
    int array[100] = {0, };
    int size = 0;

    while(true)
    {
        int input;
        scanf("%d", &input);
        if(input == -1) break;

        int i = 0;
        for(; input < array[i] && i < size; ++i);
        if(size > 0 && array[i] == input)
        {
            printf("duplicate entry\n");
            continue;
        }

        for(int j = size; j > i; --j) array[j] = array[j - 1];

        array[i] = input;
        ++size;
        
        for(int j = size - 1; j >= 0; --j) printf("%d ", array[j]);
        printf("\n");
    }

    return 0;
}
