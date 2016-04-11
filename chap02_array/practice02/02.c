#include <stdio.h>

int main(void)
{
    FILE *fp1 = fopen("res/input1.txt", "r");
    FILE *fp2 = fopen("res/input2.txt", "r");

    int data1[1000], data2[1000];
    int size1, size2;

    for(size1 = 0; size1 < 1000; ++size1) { fscanf(fp1, "%d", &data1[size1]); if(feof(fp1)) break; }
    for(size2 = 0; size2 < 1000; ++size2) { fscanf(fp2, "%d", &data2[size2]); if(feof(fp2)) break; }

    const int size3 = size1 + size2;
    int data3[size3];
    int c1, c2, c3;
    c1 = c2 = c3 = 0;

    for(c3 = 0; c3 < size3; )
    {
        while(data1[c1] <= data2[c2]) { data3[c3] = data1[c1]; ++c1; ++c3; }
        while(data1[c1] >= data2[c2]) { data3[c3] = data2[c2]; ++c2; ++c3; }
    }

    FILE *fp3 = fopen("res/result.txt", "w");
    for(int i = 0; i < size3; ++i) fprintf(fp3, "%d\n", data3[i]);

    return 0;
}
