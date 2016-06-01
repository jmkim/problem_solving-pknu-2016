#include <stdio.h>
#include "include/str_reverse.h"
#include "include/read_line.h"

#define MAX_LINE_INPUT 81

int main(void)
{
    char line[MAX_LINE_INPUT];

    read_line(stdin, line);
    str_reverse(line);
    putchar('\n');

    return 0;
}
