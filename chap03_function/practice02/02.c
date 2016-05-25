/* Macros */
#define MAX_COUNT_OF_NUMBERS    100
#define MAX_COUNT_OF_PRIME      1000

/* Includes */
#include <stdio.h>  /* printf, scanf */
#include <limits.h> /* UINT_MAX */

typedef int     PrNumberType;
typedef size_t  PrSizeType;
typedef int     PrBooleanType;
typedef int     PrKeyType;

/** Declarations */
PrSizeType
count_prime(const PrNumberType numbers[], const PrSizeType count_of_numbers);

PrBooleanType
is_prime(const PrNumberType num);

PrSizeType
add(PrSizeType n, PrNumberType primes[], const PrNumberType k);

/** Definitions */
int
main(void)
{
    PrNumberType    numbers[MAX_COUNT_OF_NUMBERS];
    int             n;
    int             i;

    printf("Enter n= ");
    scanf("%d", &n);

    if(n > 9)
        printf("Warning: The number should be greater than %d (INT_MAX), which occurs unexpected behavior.\n", INT_MAX);

    printf("Enter numbers (delims by whitespace)= ");
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &numbers[i]);
    }

    printf("Result: %d\n", count_prime(numbers, n));
    return 0;
}

PrSizeType
count_prime(const PrNumberType numbers[], const PrSizeType count_of_numbers)
{
    PrNumberType    n[count_of_numbers * count_of_numbers], /** Array which have no duplication */
                    p[MAX_COUNT_OF_PRIME];                  /** Array to store prime numbers */
    PrSizeType      n_size = 0,                             /** Size of array `n' */
                    p_size = 0;                             /** Size of array `p' */
    PrKeyType       i, j, k, l;
    PrNumberType    num;

    for(i = 0; i < count_of_numbers; ++i) /** Number of digits */
    {
        for(j = 0; j + i < count_of_numbers; ++j) /** index of array */
        {
            num = 0;
            l = j + i; /** index of number */
            for(k = 1; l >= i; k *= 10) /** Make a number */
            {
                num += numbers[l] * k;
                --l;
            }
            n_size = add(n_size, n, num);
        }
    }
    
    for(i = 0; i < n_size && p_size < MAX_COUNT_OF_PRIME; ++i)
    {
        if(is_prime(n[i]))
            p_size = add(p_size, p, n[i]);
    }

    return p_size;
}

PrBooleanType
is_prime(const PrNumberType num)
{
    PrKeyType i;

    if(num == 0) return 0;
    for(i = 2; i < num; ++i)
    {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

PrSizeType
add(PrSizeType n, PrNumberType primes[], const PrNumberType k)
{
    PrKeyType point_to_insert = 0;
    PrKeyType i;

    while(point_to_insert < n && k > primes[point_to_insert])
        ++point_to_insert;

    if(point_to_insert == n)
    {
        primes[point_to_insert] = k;
        ++n;
    }
    if(point_to_insert < n && primes[point_to_insert] != k)
    {
        for(i = n; i > point_to_insert; --i)
            primes[i] = primes[i - 1];

        primes[point_to_insert] = k;
        ++n;
    }

    return n;
}
