/*Gordon Stangler
 Euler problem 16
 2^^15 = 32768 and the sum of the digits is 3+2+7+6+8 = 26.
 Find 2^^1000/
 
 Sln:  most languges have a Big Integer package.  Using that, in C#, the program is simple.*/

using System;
using System.Diagnostics;
using System.Numerics;

namespace euler
{
    class P16
    {
        public static void Main()//P16Sln_BigInt()
        {
            BigInteger number = BigInteger.Pow(2,1000);
            int result = 0;

            while(number > 0)
            {
                result += (int)(number%10);
                number /= 10;
            }

            Console.WriteLine("The sum of the digits of 2^1000 is {0}\n", result);
        }
    }
}
