#include <string.h>
#include "str_sort.h"

char *
str_sort(char str[])
{
    char tc;
    int i, j;

    for(i = 0; i < strlen(str); ++i)
    {
        for(j = i; j > 0 && str[j] < str[j - 1]; --j)
        {
            tc = str[j];
            str[j] = str[j - 1];
            str[j - 1] = tc;
        }
    }

    return str;
}
