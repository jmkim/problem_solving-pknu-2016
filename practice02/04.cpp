long double calc_pi(const int step)
{
    /* base case */
    if(step <= 0) return 0;

    /* recursive case */
    long double denominator = ( step % 2 ? 2 * step - 1 : -(2 * step - 1) );
    return calc_pi(step - 1) + 4 / denominator;
}
