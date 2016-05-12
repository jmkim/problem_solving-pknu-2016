#include <stdio.h>

int prac1(const int n, const int arr[])
{
    int long_count = 0;

    int count, begin, end;
    int i = 0;

    while(i < n - 1)
    {
        /* Increasing */
        while(i > 0 && arr[i] == arr[i - 1]) --i; /* Pull back (Equal) */
        begin = i;
        while(i < n - 1 && arr[i] <= arr[i + 1]) ++i; /* Going forward (Increase) */
        end = i;

        count = end - begin + 1;
        if(count > long_count) long_count = count;

        /* Decreasing */
        while(i > 0 && arr[i] == arr[i - 1]) --i; /* Pull back (Equal) */
        begin = i;
        while(i < n - 1 && arr[i] >= arr[i + 1]) ++i; /* Going forward (Decrease) */
        end = i;

        count = end - begin + 1;
        if(count > long_count) long_count = count;
    }

    return long_count;
}


int main(void)
{
    int arr[] = {2, 3, 15, 15, 13, 12, 11, 9, 0, -1, 2, -3, 5};
    printf("%d\n", prac1(13, arr));

    return 0;
}
