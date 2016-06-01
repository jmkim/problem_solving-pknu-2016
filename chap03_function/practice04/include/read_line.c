#include <stdio.h>
#include "read_line.h"

size_t
read_line(FILE * stream, char line[])
{
    char ch;
    size_t size = 0;

    while((ch = fgetc(stream)) != EOF && ch != '\n')
        line[size++] = ch;

    line[size] = '\0';

    return size;
}
