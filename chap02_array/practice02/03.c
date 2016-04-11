#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("res/input.txt", "r");

    int data[1000], size;
    for(size = 0; size < 1000; ++size) { fscanf(fp, "%d", &data[size]); if(feof(fp)) break; }

    for(int i = size - 1; i >= 0; --i)
    {
        int max = i;
        for(int j = 0; j < i; ++j)
            if(data[j] > data[max]) max = j;

        int tmp = data[i];
        data[i] = data[max];
        data[max] = tmp;
    }

    for(int i = 0; i < size; ++i) printf("%d\n", data[i]);
}
