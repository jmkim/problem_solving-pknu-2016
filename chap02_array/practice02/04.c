#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter n= ");
    scanf("%d", &n);

    int data[n];

    printf("Enter %d data (divide with space)= ", n);
    for(int i = 0; i < n; ++i) scanf("%d", &data[i]);

    for(int i = n - 1; i >= 0; --i)
    {
        int max = i;
        for(int j = 0; j < i; ++j)
            if(data[j] > data[max]) max = j;

        int tmp = data[i];
        data[i] = data[max];
        data[max] = tmp;
    }
    
    for(int i = n - 1; i >= 0; --i)
    {
        if(data[i] == data[i - 1])
        {
            for(int j = i; j < n; ++j) data[j - 1] = data[j];
            --n;
        }

    }

    for(int i = 0; i < n; ++i) printf("%d ", data[i]);
    printf("\n");

    return 0;
}
