#include <stdio.h>

int get_gcd(const int num1, const int num2)
{
    /* Euclidean algorithm */
    /* Base case */
    if(num1 < num2) return get_gcd(num2, num1); /* Swap two numbers; num2 should be less than num1 */
    if(num1 % num2 == 0) return num2; /* num2 is GCD */

    /* Recursive case */
    return get_gcd(num1 % num2, num2);
}

int main(void)
{
    int num1, num2;
    printf("Enter a num1= "); scanf("%d", &num1);
    printf("Enter a num2= "); scanf("%d", &num2);

    printf("Result: %d\n", get_gcd(num1, num2));

    return 0;
}
