/*Gordon Stangler
 Euler problem 20
n! means n * (n − 1) * ... * 3 * 2 * 1

For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
Sln:  most languges have a Big Integer package.  Using that, in C#, the program is simple.*/

using System;
using System.Diagnostics;
using System.Numerics;

namespace euler
{
    class P20
    {
        public static void Main()
        {
            BigInteger number = 1;
            int result = 0;

            for (int i = 100; i > 0; i--)
                number *= i;

            while (number > 0)
            {
                result += (int)(number % 10);
                number /= 10;
            }

            Console.WriteLine("The sum of the numbers of 100! is {0}", result);
        }
    }
}
