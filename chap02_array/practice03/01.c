#include <stdio.h>
#include <math.h>

void prac1(const int n, const int arr[])
{
    int pair[2] = {0, };
    int diff = 0;
    int i, j;

    for(i = 0; i < n; ++i)
    {
        for(j = i + 1; j < n; ++j)
        {
            int d = abs(arr[i] - arr[j]);
            if(diff == 0 || d > 0 && d < diff)
            {
                diff = d;
                pair[0] = arr[i];
                pair[1] = arr[j];
            }
        }
    }
    printf("%d %d\n", pair[0], pair[1]);
}

int main(void)
{
    int arr[] = {8, 1, 6, 9, 6};
    prac1(5, arr);

    return 0;
}
