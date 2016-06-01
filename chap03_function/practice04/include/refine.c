#include <stdio.h>
#include <string.h>
#include "refine.h"

void
refine(FILE * stream_out, FILE * stream_in, const size_t limit)
{
    int     len;
    char    word[limit];

    while(! feof(stream_in))
    {
        fscanf(stream_in, "%s", word);

        if(len + strlen(word) + 1 <= limit + 1)
        {
            fprintf(stream_out, "%s ", word);
            len += strlen(word) + 1;
        }
        else
        {
            fprintf(stream_out, "\n%s ", word);
            len = strlen(word) + 1;
        }
    }
    fprintf(stream_out, "\n");
}
