#include <stdio.h>

#define YEAR    0
#define MONTH   1
#define DAY     2

int is_leap_year(const int year)
{
    if(year % 400 == 0 || year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}

int get_last_day_of_month(const int year, const int month)
{
    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return is_leap_year(year) ? 29 : 28;
        default: return 0;
    }
}

int get_day_in_month_range(const int year, const int first_month, const int second_month)
{
    /* Range ( first_month, second_month ) */

    /* Base cases */
    if(first_month > second_month) return -1 * get_day_in_month_range(year, second_month, first_month); /* Return with minus sign */
    if(first_month == second_month || first_month + 1 == second_month) return 0;

    return get_last_day_of_month(year, first_month + 1) + get_day_in_month_range(year, first_month + 1, second_month);
}

int get_day_in_year_range(const int first_year, const int second_year)
{
    /* Range ( first_year, second_year ) */

    /* Base cases */
    if(first_year > second_year) return -1 * get_day_in_year_range(second_year, first_year); /* Return with minus sign */
    if(first_year == second_year || first_year + 1 == second_year) return 0;

    return (is_leap_year(first_year + 1) ? 366 : 365) + get_day_in_year_range(first_year + 1, second_year);
}

int main(void)
{
    int birth[3]; /* birth[0] is YEAR, birth[1] is MONTH, birth[2] is DAY */
    int today[3]; /* today[0] is YEAR, today[1] is MONTH, today[2] is DAY */
    int passed_day = 0;

    printf("Enter birth[YEAR, MONTH, DAY](divide by space)=");
    scanf("%d%d%d", &birth[YEAR], &birth[MONTH], &birth[DAY]);

    printf("Enter today[YEAR, MONTH, DAY](divide by space)=");
    scanf("%d%d%d", &today[YEAR], &today[MONTH], &today[DAY]);

    {
        /* Calculate days in range YEAR */
        passed_day += get_day_in_year_range(birth[YEAR], today[YEAR]); /* Range ( birth[YEAR], today[YEAR] ) */

        /* Calculate days in range MONTH */
        if(birth[YEAR] == today[YEAR])
            passed_day += get_day_in_month_range(birth[YEAR], birth[MONTH], today[MONTH]); /* Range ( birth[MONTH], today[MONTH] ) */
        else if(birth[YEAR] > today[YEAR])
        {
            passed_day += get_day_in_month_range(birth[YEAR], birth[MONTH], 0); /* Range [ 1, birth[MONTH] ] with minus sign */
            passed_day += get_day_in_month_range(today[YEAR], 13, today[MONTH]); /* Range [ today[MONTH], 12 ] with minus sign */
        }
        else
        {
            passed_day += get_day_in_month_range(today[YEAR], 0, today[MONTH]); /* Range [ 1, today[MONTH] ] */
            passed_day += get_day_in_month_range(birth[YEAR], birth[MONTH], 13); /* Range [ birth[MONTH], 12 ] */
        }

        /* Calculate days not included in above ranges */
        if(birth[YEAR] == today[YEAR] && birth[MONTH] == today[MONTH]) /* Same year, same month */
            passed_day += today[DAY] - birth[DAY];
        else if(birth[YEAR] > today[YEAR] || birth[YEAR] == today[YEAR] && (birth[MONTH] > today[MONTH] || birth[MONTH] == today[MONTH] && birth[DAY] > today[DAY])) /* birth is later than today */
        {
            passed_day -= get_last_day_of_month(today[YEAR], today[MONTH]) - today[DAY]; /* Range [ today[DAY], last day of today[MONTH] ] with minus sign */
            passed_day -= birth[DAY]; /* Range [ 1, birth[DAY] ] with minus sign */
        }
        else /* birth is earlier than today */
        {
            passed_day += get_last_day_of_month(birth[YEAR], birth[MONTH]) - birth[DAY]; /* Range [ birth[DAY], last day of birth[MONTH] ] */
            passed_day += today[DAY]; /* Range [ 1, today[DAY] ] */
        }
    }

    printf("Result is: %d\n", passed_day);

    return 0;
}
