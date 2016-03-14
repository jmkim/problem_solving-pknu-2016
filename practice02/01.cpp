#include <stdbool.h>

bool triangular_inequality(const int a, const int b, const int c)
{
    if(a + b > c && b + c > a && c + a > b) return true;
    return false;
}
