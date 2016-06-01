#include <stdio.h>
#include <string.h>
#include "include/read_line.h"
#include "include/str_sort.h"

#define MAX_LINE_INPUT 81

int main(void)
{
    char str1[MAX_LINE_INPUT];
    char str2[MAX_LINE_INPUT];

    read_line(stdin, str1);
    read_line(stdin, str2);

    str_sort(str1);
    str_sort(str2);

    printf("%s\n", ((strcmp(str1, str2) == 0) ? "true" : "false"));

    return 0;
}
