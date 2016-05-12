#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM  7

bool is_straight(const int arr[], const int n)
{
    int count = 1;
    int i;
    for(i = 0; i + 1 < n; ++i)
    {
        while(i + 1 < n && arr[i] == arr[i + 1]) ++i;
        if(i + 1 >= n) break;

        if(arr[i + 1] == arr[i] + 1)
            ++count;
        else
        {
            if(count >= 5)
                break;
            else
                count = 1;
        }
    } 
    return count >= 5;
}

void sort(int arr[], const int size)
{
    int i, j, t;
    for(i = size - 1; i >= 0; --i)
    {
        for(j = 0; j <= i; ++j)
        {
            if(arr[j] > arr[i])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main(void)
{
    int arr[MAX_NUM];
    int i;

    for(i = 0; i < MAX_NUM; ++i)
    {
        printf("Enter arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }

    sort(arr, MAX_NUM);

    printf("Is straight? -> %s.\n", is_straight(arr, MAX_NUM) ? "True" : "False");

    return 0;
}
