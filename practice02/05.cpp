#include <stdbool.h>

struct interval
{
    int begin;
    int end;
};

bool is_two_intervals_overlap(const struct interval *a, const struct interval *b)
{
    if( (a->begin < b->begin && a->end < b->begin) &&
        (a->begin > b->begin && a->begin > b->end)) return false;

    return true;
}
