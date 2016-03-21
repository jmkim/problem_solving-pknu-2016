#include <stdio.h>

int main(void)
{
    int isbn;

    printf("Enter isbn= ");
    scanf("%d", &isbn);

    int sum = 0, base = 1000000000;

    for(int i = 10; i >= 2; i--)
    {
        sum += i * (isbn / base);
        isbn %= base;
        base /= 10;
    }

    int checksum = 11 - (sum % 11);
    printf("Result: %d\n", checksum);

    return 0;
}
