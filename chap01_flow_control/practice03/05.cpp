#include <stdio.h>

int main(void)
{
    int isbn;

    printf("Enter isbn= ");
    scanf("%d", &isbn);

    int sum = 0;
    int base = 100000000; /* Used to extract each place value */

    for(int pos = 10; pos >= 2; pos--)
    {
        int digit = isbn / base; /* Extract the highest place value */

        sum += pos * digit;

        isbn %= base; /* Cut out the highest place value */
        base /= 10;
    }

    printf("Result: ");

    int checksum = 11 - (sum % 11);
    putchar((checksum < 10) ? '0' + checksum : 'X'); /* checksum should be in the range 0 to 9 */

    putchar('\n');

    return 0;
}
