#include <stdio.h>
#include <stdbool.h>

bool is_last_two_divided_by_two_or_three(const int num)
{
    return (num % 100 % 2 && num % 100 % 3) == 0;
}

int main(void)
{
    int count = 0;
    for(int i = 10; i <= 10000; i++)
        count += is_last_two_divided_by_two_or_three(i);

    printf("Result: %d\n", count);

    return 0;
}
