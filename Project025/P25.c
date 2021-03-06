/*Gordon Stangler
The Fibonacci sequence is defined by the recurrence relation:
Fn = Fn  1 + Fn  2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:
F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.
What is the first term in the Fibonacci sequence to contain 1000 digits?

Sln:  Using a BigNum sln, this is simply brute force.  However, there is an elegant solution.
To determine F(n) = [(1+sqrt(5))/2]^n - [(1-sqrt(5))/2]^n, which can be reduced to round(/phi^n /sqrt(5)), /phi = 1.61803...
Our digit must be a 1,000 digit number, which is 10E999 or greater.  So, we set
/phi^n/sqrt(5) > 10^999 -> n log(/phi) - (1/2)*log(5) > 999 log(10)
Solving for n yields:  n > (999*log(10) + (1/2)*log(5))/log(/phi)
*/
#include <stdio.h>
#include <math.h>

main()
{
   double phi = 1.61803;
   double ans = ((999*log(10))+(log(5)/2))/log(phi);
   int ia = (int)ans;
   ia++;
   
    printf("The first Fibonacci number with over 1000 digits is %d\n", ia);
	return 0;

}