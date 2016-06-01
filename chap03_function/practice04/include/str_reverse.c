#include <stdio.h>
#include "str_reverse.h"

void
str_reverse(char * c)
{
    if(*c != '\0')
    {
        str_reverse(c + 1);
        putchar(*c);
    }
}
