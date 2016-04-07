#include <stdio.h>

#define YEAR    0
#define MONTH   1
#define DAY     2

int is_leap_year(const int year)
{
    if(year % 400 == 0 || year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}

int get_month(const int year, const int month)
{
    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return is_leap_year(year) ? 29 : 28;
    }
}

int main(void)
{
    int i;
    int birth[3]; /* birth[0] is YEAR, birth[1] is MONTH, birth[2] is DAY */
    int today[3]; /* today[0] is YEAR, today[1] is MONTH, today[2] is DAY */
    int passed_day = 0;

    printf("Enter birth[YEAR, MONTH, DAY](divide by space)=");
    scanf("%d%d%d", &birth[YEAR], &birth[MONTH], &birth[DAY]);

    printf("Enter today[YEAR, MONTH, DAY](divide by space)=");
    scanf("%d%d%d", &today[YEAR], &today[MONTH], &today[DAY]);

    {
        {
            passed_day += get_month(birth[YEAR], birth[MONTH]) - birth[DAY];
            passed_day += today[DAY] - 1;
        }

        {
            for(; birth[MONTH] < 12; ++birth[MONTH])
                passed_day += get_month(birth[YEAR], birth[MONTH]);
            for(i = 1; i < today[MONTH] - 1; ++i)
                passed_day += get_month(today[YEAR], today[MONTH]);
        }

        {
            for(; birth[YEAR] < today[YEAR] - 1; ++birth[YEAR])
                passed_day += is_leap_year(birth[YEAR]) ? 366 : 365;
        }
    }

    printf("Result is: %d\n", passed_day);

    return 0;
}
