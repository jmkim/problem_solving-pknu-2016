#include <stdio.h>

int two_sum(const int k, const int n, const int arr[])
{
    int count = 0;
    int i, j;

    for(i = 0; i < n; ++i)
    {
        for(j = i + 1; j < n; ++j)
        {
            while(arr[j] == arr[j + 1]) ++j;
            if(arr[i] + arr[j] == k) ++count;
        }
        while(arr[i] == arr[i + 1]) ++i;
    }
    
    return count;
}

int main(void)
{
}
