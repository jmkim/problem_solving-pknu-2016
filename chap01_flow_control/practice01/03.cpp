#include <stdio.h>

double ctof(const int celsius) { return celsius * 1.8 + 32; }

int main(void)
{
    printf("Celsius Fahrenheit\n");

    for(int celsius = 0; celsius <= 100; celsius += 5)
        printf("%7d %10.2lf\n", celsius, ctof(celsius));

    return 0;
}
