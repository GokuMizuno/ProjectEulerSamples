/*ProjectEuler.net - Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.  Find the sum of all the multiples of 3 or 5 below 1000.*/
/*Solution
This is a simple application of inclusion-exclusion principle. The sum of all numbers we are interested in is (1) the sum of all numbers divisible by 3, plus (2) the sum of all numbers divisible by 5, minus (3) the sum of all numbers divisible by 15. Each of the 3 sums is a sum of an arithmetic progression, which is relatively easy to find. Basically, you don't need a loop.
The number of non-negative integers divisible by n below N is exactly [(N - 1) / n] + 1. The maximal such number is n * ([(N - 1) / n], therefore by the arithmetic progression sum formula, their sum is [(N - 1) / n] * ([(N - 1) / n] + 1) * n / 2.
For our case, we have got:

    N = 1000, n = 3, [(N - 1) / n] = 333, sum = 333*334*3/2.
    N = 1000, n = 5, [(N - 1) / n] = 199, sum = 199*200*5/2.
    N = 1000, n = 15, [(N - 1) / n] = 66, sum = 66*67*15/2.

The final result is 233168.*/

#include <stdio.h>

int main()
{
    int total=0;

    total = 3*333*334/2;
    total += 5*199*200/2;
    total -= 15*66*67/2;

    printf("%i", total);
    return 0;
}