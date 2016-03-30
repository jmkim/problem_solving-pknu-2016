#include <stdio.h>

int main(void)
{
    const double r = 100;
    int count = 1; /* Include (0, 0) which makes denominator to zero */

    for(double x = 1; x <= r; ++x)
        for(double y = 1 / (3 * x); x * x + y * y <= r * r && y <= 2 / (3 * x); ++y, ++count);

    printf("Result: %d\n", count);

    return 0;
}
