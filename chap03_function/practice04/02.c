#include <stdio.h>
#include "include/read_line.h"
#include "include/str_sort.h"

#define MAX_LINE_INPUT 81

int main(void)
{
    char line[MAX_LINE_INPUT];

    read_line(stdin, line);
    str_sort(line);

    printf("%s\n", line);

    return 0;
}
